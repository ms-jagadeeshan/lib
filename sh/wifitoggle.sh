#!/bin/sh
#This is wifi toggle

wifistat=$(nmcli radio wifi)
if [  $wifistat == "enabled" ]
then
nmcli radio wifi off
else
nmcli radio wifi on
fi
