#!/bin/bash

COMMAND=$1
PORT=$2

function help()
{
    echo -e "Invalid command: <$COMMAND>"
    echo -e "Proper syntax: $0 [COMMAND] <PORT>"
    echo -e "COMMAND
        - build          - builds the project
        - monitor [PORT] - Opens a serial monitor to the board
        - flash   [PORT] - Uploads the recently built executable to the connected board
    "
}

function run_esp_idf_if_necessary()
{
    if [ -z "$IDF_PATH" ]; then
        echo -e "ESP-IDF export.sh script has not been run"
        echo -e "Running it now"
        . ~/esp/esp-idf/export.sh
    else
        echo -e "ESP-IDF export.sh script has been run"
    fi
}

function main()
{
    run_esp_idf_if_necessary

    case $COMMAND in
    "build")
        echo -e "Building..."
        idf.py build
    ;;
    "monitor")
        echo -e "Monitoring..."
        echo -e "Not yet implemented"
        idf.py -p $PORT monitor
    ;;
    "flash")
        echo -e "Flashing..."
        echo -e "Not yet implemented"
        idf.py -p $PORT flash
    ;;
    *)
        help
    ;;
    esac
}


main