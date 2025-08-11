#!/bin/bash

# This script builds and runs the Swappy application.
#  ninja -C build swappy-pot   
#  ninja -C build swappy-update-po
#  meson compile -C build

if [ -z "$1" ]; then
  echo "Error: Please provide a path to an image file."
  echo "Usage: ./run.sh <path_to_image>"
  exit 1
fi

./build/swappy -f "$1"
