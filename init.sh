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
    exit 1
else
    echo -e "arduino-cli already installed"
fi
echo -e "$0. Done."
