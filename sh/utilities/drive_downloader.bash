#!/bin/bash

declare -a LINKS=(
    #enter the links here
    # sample #
    # "https://drive.google.com/file/d/1FkdfCqTAxlwt5aoB43eZQEly_nN4ct9I/view"
    "https://drive.google.com/file/d/1he0szcypdBXnNhd1m2TvRIebcb8q8qCW/view"
    "https://drive.google.com/file/d/17YqNdSjqzKwR3vgufPZdfJpPrOUzlay6/view"
    "https://drive.google.com/file/d/1oJkkUit-VSpXjrIXDg0VyOE6vpwHJmcm/view"
    "https://drive.google.com/file/d/1iYl9Ft4U47vqHEuEoCM1ZHGiAdTKV6aJ/view"
    "https://drive.google.com/file/d/1WQIiMCIcD7porKTbMexlValbcq0Mk23Y/view"
)

OUTPUT_DIR="$HOME/college/3rd\ sem/lectures/linear_algebra"
for link in "${LINKS[@]}" ; do
    gnome-terminal --working-directory="$OUTPUT_DIR" -- youtube-dl --cookies ~/newcookiefile.txt $link
done