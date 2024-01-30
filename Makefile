# Define variables
ARDUINO_CLI = arduino-cli
BOARD = esp32:esp32:esp32s2
SKETCH = $(shell pwd)/potaTOS.ino
PORT = INVALID_PORT

# Build target
build:
	$(ARDUINO_CLI) compile --verbose --fqbn $(BOARD) $(SKETCH)

# Upload target
upload:
	@echo $(PORT)
	$(ARDUINO_CLI) upload --verbose -p $(PORT) --fqbn $(BOARD) $(SKETCH)

# Clean target
clean:
	$(ARDUINO_CLI) cache clean