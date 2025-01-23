#!/bin/bash

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

compare_files=0
# Optionally pass in -valgrind to use valgrind or -asan to use ASAN
case $1 in
	"--compare-files")
		compare_files=1
		;;
esac

for f in $DIR/tests/test_cases/*
do
	if [ $compare_files -ne 0 ]
	then
		$DIR/bin/forlang < $f 2>&1 | diff - tests/reference/$(basename $f)
		result=$?
		if [ $result -ne 0 ]
		then
			echo "failed: $(basename $f)"
		else
			echo "passed: $(basename $f)"
		fi	
	else
		echo "------BEGIN $f OUTPUT------"
		$DIR/bin/forlang < $f
		echo "------END $f OUTPUT------"
	fi
done
