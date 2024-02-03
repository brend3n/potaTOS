#!/bin/bash

ROOT_DIR=$1
CWD=$(pwd)

function help_message ()
{
    echo -e "Example Usage:"
    echo -e "$0 <ROOT_DIR>"
}

if [ -z "$ROOT_DIR" ]; then
    help_message
    exit 1
fi

include_paths=$(find src/ -type f -name '*.h' -execdir pwd \; | sort -u)

# echo -e "Unsorted"
# echo -e "$include_paths"

unique_list=$(echo "$include_paths" | tr ' ' '\n' | sort -u | tr '\n' ',')
# echo -e "Sorted"
unique_list=${unique_list%?} # Remove trailing ,
echo -e "$unique_list"



# include_paths=$(find src/ -type f -name '*.h' -exec dirname {} \; | sort -u)

# for path in "$include_paths"; do
#     echo "--library $path"
# done
