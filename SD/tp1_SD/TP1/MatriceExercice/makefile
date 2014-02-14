LINUX= -lnsl
CC=gcc
CFLAGS=-Wall
#----------------------------------------------
all : serveur client 
#----------------------------------------------
serveur : serveur.o xdr_matrice.o
	gcc -o serveur serveur.o xdr_matrice.o ${LINUX}
#----------------------------------------------
client : client.o xdr_matrice.o
	gcc -o client client.o xdr_matrice.o ${LINUX}
#----------------------------------------------
clean :
	/bin/rm -f *.o serveur client *~ core* pok* *.ps
