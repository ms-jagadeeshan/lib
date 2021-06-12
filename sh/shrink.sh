#!/bin/bash
read -p "Enter the folder path(relative path from home e.g Photos/screenshots): " DIR
read -p "Do you want to specify image type(Y/n): " op
if [ op='Y' or op='y' ]
then
read -p "Image file type(e.g png) :" IMG_TYPE
else
IMG_TYPE=""
fi
for file in $HOME/$DIR/*$IMG_TYPE; do
     line="$(basename "$file")"
     
done

while read -r line
do
    echo $line
    width=$(identify -format '%w' $line)
    height=$(identify -format '%h' $line)
     if [ width!=1031 ]
     then
        printf *********changing**********
          height=$((height*1031/width))
          height=$(echo $height | awk '{print int($1)}')
    convert $line -resize 1031x$height  ~/pom/$line
    fi
done 
