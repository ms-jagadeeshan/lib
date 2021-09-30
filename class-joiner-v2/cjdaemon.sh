#!/bin/sh

HOUR=$(date +%H)
MINUTE=$(date +%M)
DAY=$(date +%w)
sixty=54
twenty=114
if [ "$MINUTE" -lt "54" ]; then
    count=$((sixty - MINUTE))
    sleep "$count"m

else
    count=$((twenty - MINUTE))
    sleep "$count"m
fi
while true; do
    #classjoiner
    gtk-launch classjoiner
    sleep 60m
done
