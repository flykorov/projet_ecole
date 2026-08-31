#!/bin/sh

if test -z "$1"
then
	echo "Le paramètre est manquant"
	exit
fi

if test -n "$2"
then
	echo "Trop de paramètres"
	exit
fi

if test -f "$1"
then
	echo "$1 est un fichier ordinaire"
	exit
fi

if test -d "$1"
then
	echo "$1 est un répertoire"
	exit
fi

echo "$1 n'existe pas dans l'arborescence"

# variable=$(ls -l | grep -w $1 | cut -c 1)
# case $variable in
#	"") echo "$1 n'existe pas dans l'arborescence";;
#	"-") echo "$1 est un fichier ordinaire";;
#	"d") echo "$1 est un répertoire";;
#	"p") echo "$1 est un pipe";;
#	"l") echo "$1 est un lien symbolique";;
#	"s") echo "$1 est un socket";;
#	"c"|"b") echo "$1 est un périphérique"
#esac

