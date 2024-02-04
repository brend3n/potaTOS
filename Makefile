# Define variables
ARDUINO_CLI = arduino-cli
BOARD = esp32:esp32:esp32s2
SKETCH = $(shell pwd)/potaTOS.ino
PORT = /dev/ttyUSB0
BAUD = 115200
PROJECT_NAME = potaTOS

# Build target
build:
	@echo $(PORT)
	$(ARDUINO_CLI) compile --verbose --fqbn $(BOARD) -p $(PORT) $(SKETCH)

# Upload target
upload:
	@echo $(PORT)
	sudo chmod a+rw $(PORT)
	$(ARDUINO_CLI) upload --verbose -p $(PORT) --fqbn $(BOARD) $(SKETCH)

build_and_upload:
	@echo $(PORT)
	$(ARDUINO_CLI) compile --verbose --fqbn $(BOARD) -p $(PORT) $(SKETCH)
	sudo chmod a+rw $(PORT)
	$(ARDUINO_CLI) upload --verbose -p $(PORT) --fqbn $(BOARD) $(SKETCH)

monitor:
	@echo $(PORT)
	@echo $(BAUD)
	sudo chmod a+rw $(PORT)
	minicom -D $(PORT) -b $(BAUD)
#$(ARDUINO_CLI) monitor --port $(PORT) --config baudrate=$(BAUD)

# Clean target
clean:
	$(ARDUINO_CLI) cache clean


esp-start:
	. $HOME/esp/esp-idf/export.sh

esp-build:	
	idf.py build

esp-flash:
	@echo $(PORT)
	sudo chmod a+rw $(PORT)
	idf.py -p $(PORT) flash

esp-monitor:
	@echo $(PORT)
	sudo chmod a+rw $(PORT)
	idf.py -p PORT monitor
	