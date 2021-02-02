#!/bin/sh

hour=$(date +%H)
minute=$(date +%M)
day=$(date +%w)
dir="/home/$USER/lib/"
if [ "$day" = "6" ]
then 
{
    echo  "What is your timetable?\n"
    echo "1 for Monday\n2 for Tuesday\n3 for Wednesday\n4 for Thrusday\n5 for Friday\n"
    read -p "Enter here(1-5):" day
}
fi
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