#!/bin/bash

for D in $(ls)
do 
	cd "$D" 2> /tmp/error
	pwd
	if [ -s /tmp/error ]
	then
		rm /tmp/error
	else
		git remote show origin | grep Push
    	cd ..
	fi
done

