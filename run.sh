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
        idf.py -p $PORT monitor
    ;;
    "flash")
        echo -e "Flashing..."        
        # idf.py -p $PORT flash
        /home/brenden/.espressif/python_env/idf5.1_py3.10_env/bin/python ../../../esp/esp-idf/components/esptool_py/esptool/esptool.py -p $PORT -b 460800 --before default_reset --after hard_reset --chip esp32s2  write_flash --flash_mode dio --flash_size 2MB --flash_freq 80m 0x1000 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x10000 build/potatos.bin
    ;;
    *)
        help
    ;;
    esac
}


main