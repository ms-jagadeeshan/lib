#!bin/sh

HOUR=$(date +%H)
MINUTE=$(date +%M)
DAY=$(date +%w)
sixty=47
twenty=114
if [ "$MINUTE" -lt "54" ] ; then
    echo hello$count
    count=$((sixty-MINUTE))
    sleep "$count"m
    
else
    echo shit$count
    count=$((twenty-MINUTE))
    sleep "$count"m
fi
while true; do
    test1
    sleep 60m
    
done
