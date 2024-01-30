# Define variables
ARDUINO_CLI = arduino-cli
BOARD = esp32:esp32:esp32s2
SKETCH = $(shell pwd)/potaTOS.ino

# Build target
build:
	$(ARDUINO_CLI) compile --verbose --fqbn $(BOARD) $(SKETCH)

# Upload target
upload:
	$(ARDUINO_CLI) upload -p --verbose <port> --fqbn $(BOARD) $(SKETCH)

# Clean target
clean:
	$(ARDUINO_CLI) cache clean