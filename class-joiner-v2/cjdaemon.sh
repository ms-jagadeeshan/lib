#!/bin/sh

HOUR=$(date +%H)
MINUTE=$(date +%M)
DAY=$(date +%w)
sixty=54
twenty=114
if [ "$MINUTE" -lt "54" ] ; then
    count=$((sixty-MINUTE))
    sleep "$count"m
    
else
    count=$((twenty-MINUTE))
    sleep "$count"m
fi
while true; do
    #classjoiner
    DISPLAY=$DISPLAY gnome-terminal -- "$HOME/.local/bin/classjoiner"
    sleep 60m
done
