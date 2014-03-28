#include "include.h"
bool_t xdr_matrice(XDR *xdrs, Matrice *e) 
{
	bool_t res;
	int i,j;
	
	if ((res = xdr_int(xdrs, &e->n)) == FALSE)
		return res;
	
	for (i=0 ; i<e->n && res!=FALSE ; i++)
	{
		for (j=0 ; j<e->n && res!=FALSE ; j++)
		{
			res = xdr_int(xdrs, &e->m[i][j]);
		}
	}
	return res;
}

bool_t xdr_Doublematrice(XDR* xdrs, DoubleMatrice * dm)
{
	bool_t res;
	
	if ((res = xdr_matrice(xdrs, (Matrice *) dm)) == FALSE)
		return res;
	Matrice * m2 = (Matrice *) dm;
	m2++;
	res = xdr_matrice(xdrs, m2);
	
	return res;
}
