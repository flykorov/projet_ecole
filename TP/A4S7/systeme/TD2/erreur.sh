#!/bin/sh

NB_USERS=`cat /etc/password | wc -l`

if [ $NB_USERS -gt 0 ]
then
	echo "$NB_USERS sont déclarés sur votre système"
else
	echo "une erreur a dû se produire"
fi
