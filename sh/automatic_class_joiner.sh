#!/bin/sh

hour=$(date +%H)
minute=$(date +%M)
day=$(date +%w)
dir="/home/$USER/lib/"
cd
cd $dir/c++ && g++ link_provider.cpp -o link_provider 
link=$(./link_provider $hour $minute $day)
if [ "$link" = "noc" ]
then 
echo "Cool,You don't have any classes now"
else
echo "Opening, $link "
xdg-open $link
echo "Opened"
fi