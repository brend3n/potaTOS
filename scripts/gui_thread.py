# Time
from time import sleep, time

# Threading
from threading import Thread

# Queue
from queue import Queue

# GUI
import PySimpleGUI as sg

########################################################################################
# GUI Thread


class gui_thread(Thread):
	def __init__(self, msg_queue: Queue):

		# Thread init
		Thread.__init__(self)
		self.daemon = True

		# Get that message queue
		self.msq_queue = msg_queue

		# Data collected from MQTT subscriptions to display in the GUI
		self.data = { "temp" : 0, "humidity" : 0, "heat_index" : 0, "button_r_count": 0, "button_l_count": 0}

		# Setup thread and launch it
		self.client = self.setup_gui_thread()
		self.start()


	def run(self):
		# Display and interact with the Window using an Event Loop
		while True:
			# sg.preview_all_look_and_feel_themes()

			# Sample more
			for i in range(5):
				self.fetch_subscriptions()
			
			print(self.data)
	
			event, values = self.window.read(timeout=100)

			# # See if user wants to quit or window was closed
			if event == sg.WINDOW_CLOSED or event == 'Quit':
				break

			if event == "Clear":
				self.data = { "temp" : 0, "humidity" : 0, "heat_index" : 0, "button_r_count": 0, "button_l_count": 0}

			self.window['temp'].update(self.data["temp"])
			self.window['hum'].update(self.data["humidity"])
			self.window['hi'].update(self.data["heat_index"])
			self.window['button_r_count'].update(self.data["button_r_count"])
			self.window['button_l_count'].update(self.data["button_l_count"])

		# Finish up by removing from the screen
		self.window.close()
		

	def setup_gui_thread(self):
		self.var = 0

		sg.theme('light brown 3')

		# Define the window's contents
		
		layout = [
				[sg.Text("Left Count", key='left_count_text'), sg.Push(), sg.Push(),sg.Push(),sg.Push(),sg.Push(),sg.Push(), sg.Text("Right Count", key='right_count_text')],
				[sg.Text(self.data["button_l_count"], key="button_l_count"), sg.Push(),sg.Text(self.data["button_r_count"], key="button_r_count")],
				[sg.Text("Temperature", key='temp_text'), sg.Text("Humidity", key='humidity_text'), sg.Text("Heat Index", key='heat_index_text')],
				[sg.Text(self.data["temp"], key='temp'), sg.Push(), sg.Text(self.data["humidity"], key='hum'),sg.Push(), sg.Text(self.data["heat_index"], key='hi')],
				[sg.Button('Clear'), sg.Button('Quit')]]

		# Create the window
		self.window = sg.Window('Window Title', layout)

		print("Done setting up gui_thread!")


	def fetch_subscriptions(self):

		msg = None

		# Attempt to get a message, return None is fetching fails (queue is empty)
		try:
			msg = self.msq_queue.get_nowait()
		except Exception:
			return None
				
		"""
		msg: structure
			{
				"topic" : msg.topic, 
				"data" : msg.payload
			}
		"""

		# Extract topic
		topic = msg["topic"]

		if (topic == 'button_event'):
			device, message = msg["data"].split(",")
			if (device == "Device_2"):
				self.data["button_r_count"] += 1
			else:
				self.data["button_l_count"] += 1
		elif (topic == 'ultra_sonic_event'):
			pass
		elif(topic == 'temp_hum_event'):
			# Message format example: Device_%d, %.2f, %.2f, %.2f
			# Message format: Device_ID, temp, humidity, heat_index
			device, temperature, humidity, heat_index = msg["data"].split(",")
			self.data["humidity"]     = float(humidity)
			self.data["heat_index"]   = float(heat_index)
			self.data["temp"]  = float(temperature)			
		else:
			print("Error: Missing topic in gui_thread.py -> fetch_subscriptions()")
			return None
			