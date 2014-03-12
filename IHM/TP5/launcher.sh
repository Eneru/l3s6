#!/bin/sh
#Lancer et compiler drawtri

BIN=bin/drawtri
QUESTION="Vous n'avez pas make, voulez vous le faire ? (y/n) "

if ! [ -f "$BIN" ]
	then
		read -p "$QUESTION" REP
		if [ "$REP" = "y" ] || [ "$REP" = "yes" ]
			then
				make
				./bin/drawtri
			else
				exit 0
		fi
	else
		./bin/drawtri
fi

exit 0
