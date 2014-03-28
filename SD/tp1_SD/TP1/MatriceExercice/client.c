#include "include.h"

int main (int argc, char **argv) 
{
	char *host = argv[1];
	enum clnt_stat stat;
	
	int i,j;
	int taille = atoi(argv[2]);
	
	Matrice res;
	initMatrice(taille,&res);
	
	DoubleMatrice donnees;
	initMatrice(taille,&donnees[0]);
	initMatrice(taille,&donnees[1]);
	
	for (i=0 ; i<taille ; i++)
		for (j=0 ; j<taille ; j++)
		{
			donnees[0].m[i][j] = i+j;
			donnees[1].m[i][j] = j*2-i;
		}
	
	stat = callrpc(host,PROGNUM,VERSNUM,PROCNUM,(xdrproc_t) xdr_Doublematrice,(char *)&donnees,(xdrproc_t)xdr_matrice,(char *)&res); 

	if (stat != RPC_SUCCESS) 
	{ 
		fprintf(stderr, "Echec de l'appel distant\n");
		clnt_perrno(stat);      fprintf(stderr, "\n");
	} 
	
	else 
	{
		printMatrice(&res);
	}
	return(0);
}
