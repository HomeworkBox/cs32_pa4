#!/bin/bash

if [ ! -f ./dynb ] || [ ! -f ./dynb-virt ]
then
	echo "Executables ./dynb and ./dynb-virt are not found";
	exit 1;
fi

diff_result=$(diff -w <(./dynb) <(./dynb-virt) | wc -l)
if [ 0 == $diff_result ]
then
	echo "SUCCESS: Executables produce identical result"
	exit 0
else
	echo "FAILURE: Executables produce different result"
	exit 1
fi
