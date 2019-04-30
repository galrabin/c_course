#!/bin/bash

if [ $# -eq 0 ]
 then
	echo "Usage: ./count-items.sh <path>"
	exit 2			
elif [ -f $1 ] 
 then
	echo 1
elif [ ! -e $1 ]
 then
	echo "No such path"
	exit 1
elif  [ -d $1 ]
 then
   count=1
   dir=`echo $1 | sed -r 's/\/$//'`
   let count+=`source num-readable-files.sh`
   readable_dirs=`source list-readable-dirs.sh`
   for directory in $readable_dirs
   do
	addition=`./count-items.sh $dir/$directory`
	let count+=addition
   done
   echo $count
fi
