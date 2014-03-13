#!/bin/sh
#Clean de tous les .o et le bin

OBJ=obj
QUESTION="Etes-vous sur de vouloir desinstaller ? (y/n) "

if [ -d "$OBJ" ]
	then
		read -p "$QUESTION" REP
		if [ "$REP" = "y" ] || [ "$REP" = "yes" ]
			then
				make clean
			else
				echo "Desinstallation avortee."
				exit 0
		fi
	else
		echo "Desinstallation avortee."
fi

exit 0
