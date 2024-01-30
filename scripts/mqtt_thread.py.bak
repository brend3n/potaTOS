# Time
from time import sleep, time

# Threading
from threading import Thread

# MQTT
import paho.mqtt.client as p_mqtt

# Queue
from queue import Queue

IP_OF_BROKER = "192.168.1.224"
topics = ['button_event', 'ultra_sonic_event', 'temp_hum_event', 'servo_matrix_event']
# topics = ['temp_hum_event']

########################################################################################
# MQTT Thread


class mqtt_thread(Thread):
	def __init__(self, msg_queue: Queue):
		Thread.__init__(self)
		self.daemon = True
		self.msq_queue = msg_queue
		client = self.setup_mqtt_thread()
		self.start()
	
	def run(self):
		while True:
			print("mqtt thread")
			self.client.loop()
			sleep(1)

	# The callback for when the client receives a CONNACK response from the server.
	def on_connect(self, client, userdata, flags, rc):
		print("Connected with result code: "+ str(rc))
		# Subscribing in on_connect() means that if we lose the connection and
		# reconnect then subscriptions will be renewed.
		print(f"Subscribing to topics: {topics}")
		for topic in topics:
			client.subscribe(topic)

	# The callback for when a PUBLISH message is received from the server.
	def on_message(self, client, userdata, msg):
		topic = msg.topic
		payload = msg.payload.decode("utf-8")

		print(f"{topic}: {payload}")

		self.msq_queue.put(
			{
				"topic" : topic, 
    			"data" : payload
			}
		)

	def setup_mqtt_thread(self):
		self.client = p_mqtt.Client()
		self.client.on_connect = self.on_connect
		self.client.on_message = self.on_message
		self.client.connect(IP_OF_BROKER, 1883, 60)