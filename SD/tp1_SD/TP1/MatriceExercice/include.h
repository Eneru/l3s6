#ifndef INCRPC
#define INCRPC  

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>
#define PROGNUM 0x20000100
#define VERSNUM 1
#define PROCNUM 1

typedef struct matr
{
	int n;
	int** m;
}Matrice;

typedef Matrice DoubleMatrice[2];

bool_t xdr_matrice(XDR *, Matrice*);

bool_t xdr_Doublematrice(XDR *, DoubleMatrice*);

static inline void initMatrice (int n, Matrice * m)
{
	int i;
	m->m = malloc(m->n*sizeof (int*));
	for (i=0 ; i<m->n ; i++)
		m->m[i] = malloc(m->n*sizeof(int));
}

static inline void printMatrice (Matrice* m)
{
	int i,j;
	for(i = 0 ; i<m->n ; i++)
	{
		printf("(");
		for(j = 0 ; j<m->n ; j++)
			printf("%d\t",m->m[i][j]);
		printf(")\n");
	}
	printf("\n");
}

#endif /* INCRPC */
