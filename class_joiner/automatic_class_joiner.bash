#!/bin/bash

HOUR=$(date +%H)
MINUTE=$(date +%M)
DAY=$(date +%w)
DIR="$HOME/lib/class_joiner"
if [ "$DAY" = "6" ] ; then 
{
    echo  "What is your timetable?\n"
    echo -e "1 for Monday\n2 for Tuesday\n3 for Wednesday\n4 for Thrusday\n5 for Friday\n"
    read -p "Enter here(1-5):" DAY
}
fi
cd
cd $DIR && g++ link_provider.cpp -o link_provider 
output=$($DIR/link_provider $HOUR $MINUTE $DAY)
declare -i i=0
declare -a ARR
declare -a DAYS
declare -i k
DAYS=(Sunday Monday Tuesday Wednesday Thursday Friday Saturday)
for word in $output     #parsing the output from link provider function
do                      #arr[0] is link or "noc", arr[1] is the name of the class,
    #echo $word         #arr[2] is the day in number, arr[3] is the timing of the class
    ARR[i]="$word"
    i=$((i + 1))
done
k=${ARR[2]}         
if [ "${ARR[0]}" == "noc" ]
then 
    echo "Cool,You don't have any classes now"
    echo "Your next class is ${ARR[1]} and will be on ${DAYS[k]} ${ARR[3]}.00 "
else
    wifistat=$(nmcli radio wifi)
    if [  $wifistat == "disabled" ]
    then
        nmcli radio wifi on
    fi 
       echo "Opening, ${ARR[0]}" 
       sleep 1
       DISPLAY=:0 firefox ${ARR[0]} 
       echo "Opened" 
       echo "Your current class is ${ARR[1]} and will be on ${DAYS[k]} ${ARR[3]}.00 "
fi
sleep 10;
