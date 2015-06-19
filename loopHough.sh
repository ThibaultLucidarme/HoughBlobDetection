#!/bin/bash

for file in data/*
do
	../bin/Hough $file
	mv ../bin/output/tmp.png ../bin/output/`echo $file|rev|cut -d/ -f1|rev`
done
