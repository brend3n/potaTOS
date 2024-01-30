import time

# Thread Classes 
from mqtt_thread import IP_OF_BROKER, mqtt_thread
# from streamlit_thread import streamlit_thread
from gui_thread import gui_thread

# Message Queues
from queue import Queue

def main():
	msq_queue = Queue()

	mqtt_thread(msq_queue)
	# streamlit_thread(msq_queue)
	gui_thread(msq_queue)

	while True:
		time.sleep(1)
		pass

if __name__ == "__main__":
	main()