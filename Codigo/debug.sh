#!/bin/bash

numArgs=1

# Check if the number of arguments is valid
if [ $# -ne $numArgs ]
then
	echo Error : Invalid number of arguments
	exit 1
fi

# Check if the max number of threads if a valid number = integer
re='^[0-9]+$'
if ! [[ $1 =~ $re ]]
then
	echo Error : maxThreads is invalid, $3 must be an integer
	exit 1
fi

maxnodes=$1

for numnodes in $(seq 1 $maxnodes)
do
	echo ====: $numnodes Nodes :===
	for decimal in $(seq 0 10)
	do

	prob=`echo "scale=2 ; ${decimal}/10" | bc`
	echo  - Probability = $prob

	# Generate a new DAG
	../GeradorDeTestes/randomDAG $numnodes 0$prob > testfile

	# Run the program with the calculated DAG
	printf "  Output : "
	./a.out < testfile

	done
done
