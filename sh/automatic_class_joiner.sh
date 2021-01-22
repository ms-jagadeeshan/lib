#!/bin/sh

hour=$(date +%H)
minute=$(date +%M)
day=$(date +%w)
Ec_batch=1
dir="/home/$USER/lib/"
#dir="~/lib/sh/automatic_class_joiner"
cd
cd $dir/c++ && g++ link_provider.cpp -o link_provider 
link=$(./link_provider $hour $minute $day $Ec_batch)
xdg-open $link
echo "Script executed from: ${PWD}"

BASEDIR=$(dirname $0)
echo "Script location: ${BASEDIR}"