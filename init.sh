#/bin/bash

echo -e "Initiliazing repo"

# Check if Python exists
if [ ! command -v python &> /dev/null ]; then
    echo "Python is not installed. Please install Python before proceeding."
    exit 1
else
    echo -e "Python already installed"
fi

# Check if arduino-cli exists
if [ ! command -v arduino-cli &> /dev/null ]; then
    echo "Arduino CLI is not installed. Please install Arduino CLI before proceeding."
    echo -e "But this isn't necessary if you are using esp-idf"
else
    echo -e "arduino-cli already installed"
fi

git submodule update --init --recursive --force

# cd import/esp-idf
# ./install.sh all
# cd ../..
# . ./import/esp-idf/export.sh # Run once during init. This is called each time we run a command

echo -e "$0. Done."
