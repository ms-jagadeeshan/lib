#!/bin/bash

hour=$(date +%H)
minute=$(date +%M)
day=$(date +%w)
dir="/home/$USER/lib/"
if [ "$day" = "6" ]
then 
{
    echo  "What is your timetable?\n"
    echo -e "1 for Monday\n2 for Tuesday\n3 for Wednesday\n4 for Thrusday\n5 for Friday\n"
    read -p "Enter here(1-5):" day
}
fi
cd
cd $dir/c++ && g++ link_provider.cpp -o link_provider 
output=$(./link_provider $hour $minute $day)
declare -i i=0
declare -a arr
declare -a days
declare -i k
days=(Sunday Monday Tuesday Wednesday Thursday Friday Saturday)
for word in $output
do
    #echo $word
    arr[i]="$word"
    i=$((i + 1))
done
k=${arr[2]}
if [ "${arr[0]}" == "noc" ]
then 
    echo "Cool,You don't have any classes now"
    echo "Your next class is ${arr[1]} and will be on ${days[k]} ${arr[3]}.00 "
else
    wifistat=$(nmcli radio wifi)
    if [  $wifistat == "disabled" ]
    then
        nmcli radio wifi on
    fi
    echo "Opening, ${arr[0]}"
    sleep 1
    xdg-open ${arr[0]}
    echo "Opened"
    echo "Your current class is ${arr[1]} and will be on ${days[k]} ${arr[3]}.00 "
fi


##### (firefox:8374): Gtk-WARNING **: 09:00:36.050: Theme directory panel/22 of theme Mojave-CT-Classic has no size field
