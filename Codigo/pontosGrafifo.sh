#!/bin/bash

numArgs=3

# Check if the number of arguments is valid
if [ $# -ne $numArgs ]
then
	echo Error : Invalid number of arguments
	exit 1
fi

# Check if the first argument is an integer
re='^[0-9]+$'
if ! [[ $1 =~ $re ]]
then
	echo Error : $1 must be an integer
	exit 1
fi

# Check if the second argument is an integer
if ! [[ $2 =~ $re ]]
then
	echo Error : $2 must be an integer
	exit 1
fi

# Check if the third argument is an integer
if ! [[ $3 =~ $re ]]
then
	echo Error : $3 must be an integer
	exit 1
fi

liminf=$1
limsup=$2
step=$3

for nodes in $(seq $1 $3 $2)
do
    # Gerar grafo
    ../GeradorDeTestes/randomDAG $nodes 0.4 > ./testfile

	echo =======: nodes $nodes :======= 
	# Obter a primeira lina do testfile V E e somar os seus elementos obtendo V + E
	echo -n V + E =  
	python3 -c "firstline = open(\"./testfile\").readline().split() ; print(\" \" + str(int(firstline[0]) + int(firstline[1])))"

	# Correr codigo com o grafo gerado dando display do tempo
	time ./a.out < ./testfile
	echo ===========================
	echo
done