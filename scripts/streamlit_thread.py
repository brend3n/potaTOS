# Time
import time

# Threading
from threading import Thread

# Data
import numpy as np
import pandas as pd

# Streamlit UI
from streamlit.report_thread import add_report_ctx
import streamlit as st

# Queue
from queue import Queue


########################################################################################
# Streamlit Thread

class streamlit_thread(Thread):
	def __init__(self, msg_queue: Queue):
		Thread.__init__(self)
		self.daemon = True
		self.msq_queue = msg_queue
		self.setup_streamlit()
		add_report_ctx(self)
		self.start()
	
	def run(self):
		# Button count
		butL_count = 0
		butR_count = 0


		# Temperature data

		temperature = -1000
		humidity    = -1000
		heat_index  = -1000

		last_temperature = 0
		last_humidity    = 0
		last_heat_index  = 0

		first_time = True

		# Clear display
		placeholder = st.empty()
		while True:
			msg = None
			if not first_time:
				try:

					try:
						# Update button count data
						msg = self.msq_queue.get_nowait()
					except Exception:
						continue
					
					
					"""
					msg: structure
						{
							"topic" : msg.topic, 
							"data" : msg.payload
						}
					"""

					topic = msg["topic"]
					print(f"topic: {topic}")

					if (topic == 'button_event'):
						print("Python: button_event")
						device, message = msg["data"].split(",")
						if (device == "Device_2"):
							butR_count += 1
						else:
							butL_count += 1
						# New data means refresh
						placeholder.empty()
					if (topic == 'ultra_sonic_event'):
						print("Python: ultra_sonic_event")
						pass
					if(topic == 'temp_hum_event'):
						print("Python: temp_hum_event")			
						# Message format example: Device_%d, %.2f, %.2f, %.2f
						# Message format: Device_ID, temp, humidity, heat_index
						device, temperature, humidity, heat_index = msg["data"].split(",")
						humidity     = float(humidity)
						heat_index   = float(heat_index)
						temperature  = float(temperature)			

						# New data means refresh
						placeholder.empty()
					
				except Exception as e:
					# print("Nothing in the message queue")
					# time.sleep(3)
					print(e)
					continue

			first_time = False


			with placeholder.container():
				but_L_col, but_R_col, temp_col, humidity_col, heat_index_col = st.columns(5)

				but_L_col.metric("Button L Count", butL_count)
				but_R_col.metric("Button R Count", butR_count)
				temp_col.metric("Temperature", temperature, round((temperature - last_temperature), 2) )
				humidity_col.metric("Humidity", humidity, round((humidity - last_humidity), 2) )
				heat_index_col.metric("Heat Index", heat_index, round((heat_index - last_heat_index), 2) )

			# Update last values
			last_temperature = temperature
			last_humidity = humidity
			last_heat_index = heat_index

			# Refresh every second
			time.sleep(0.2)

	def setup_streamlit(self):
		return 0

########################################################################################