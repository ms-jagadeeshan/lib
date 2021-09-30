#!/bin/sh

HOUR=$(date +%H)
MINUTE=$(date +%M)
DAY=$(date +%w)

launch_time=54 #launches classjoiner at time xx.54
launch_time_=$((launch_time + 60))

if [ "$MINUTE" -lt "54" ]; then
    gtk-launch classjoiner
    count=$((launch_time - MINUTE))
    sleep "${count}m"

else
    gtk-launch classjoiner
    count=$((launch_time_ - MINUTE))
    sleep "${count}m"
fi
while true; do
    gtk-launch classjoiner
    sleep 60m
done
