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
if [ ! command -v idf.py &> /dev/null ]; then
    echo "esp-idf not intialized"
    echo "cd into esp-idf repo. Run ./install.sh and then after . ./export.sh"
else
    echo -e "esp-idf-cli already initialized"
fi

git submodule update --init --recursive --force

echo -e "$0. Done."
