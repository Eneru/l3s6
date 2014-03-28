#include "include.h"

Matrice * multiplie(DoubleMatrice * dm) 
{ 
	static Matrice res;
	
	int i,j,k;
	
	for (i = 0 ; i<dm[0]->n ; i++)
		for (j = 0 ; j<dm[0]->n ; j++)
			res.m[i][j] = 0;
			for (k = 0 ; k<dm[0]->n ; k++)
				res.m[i][j] += dm[0]->m[i][k]*dm[1]->m[k][j];
	
	return &res;
}
int main (void) 
{
	bool_t stat;
	stat = registerrpc(PROGNUM,VERSNUM,PROCNUM,multiplie,(xdrproc_t)xdr_Doublematrice,(xdrproc_t)xdr_matrice);
	if (stat != 0) 
	{
		fprintf(stderr,"Echec de l'enregistrement\n");
		exit(1);
	}
	svc_run(); /* le serveur est en attente de clients eventuels */
	return(0); /* on y passe jamais ! */
}


