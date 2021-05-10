#!/bin/bash
for file in *.png
do
  if [ -e "${file// /_}" ]
  then
    printf >&2 '%s\n' "Warning, skipping $file as the renamed version already exists"
    continue
  fi

  mv -- "$file" "${file// /_}"
done