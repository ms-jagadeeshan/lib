#!/bin/bash
while read -r line
do
    echo $line
    width=$(identify -format '%w' ~/test1/$line)
    height=$(identify -format '%h' ~/test1/$line)
     if [ width!="1140" ]
     then
        printf *********changing**********
          height=$((height*1140/width))
          height=$(echo $height | awk '{print int($1)}')
    convert $line -resize 1140x$height  ~/test2/$line
    fi
done < ~/tmps/lis1t.txt