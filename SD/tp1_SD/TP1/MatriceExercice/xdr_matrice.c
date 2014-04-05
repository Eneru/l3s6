#include "include.h"

bool_t xdr_matrice_interne (XDR * xdrs, matrice * m)
{
    bool_t res;
    for (int i = 0; i < m_dim (m) && res!=FALSE; i++)
    {
        res=xdr_array (xdrs, (char **) & m->m[i], & m->taille, m->taille, sizeof (int), (xdrproc_t) xdr_int);
    }
    return res;
}

bool_t xdr_matrice (XDR * xdrs, matrice * m)
{
    bool_t res;

    if((res = xdr_int (xdrs, & m->taille))==FALSE)
		return res;
    res = xdr_matrice_interne (xdrs, m);

    return res;
}

bool_t xdr_matrice_serveur (XDR * xdrs, matrice * m)
{
    bool_t res;
    res = xdr_matrice (xdrs, m);
    m_lib (m);
    return res;
}

bool_t xdr_double_matrice (XDR * xdrs, double_matrice * dm)
{
    bool_t res;

    if((res = xdr_matrice (xdrs, & dm->m1)) == FALSE)
		return res;
   res = xdr_matrice (xdrs, & dm->m2);

    return res;
}

bool_t xdr_double_matrice_serveur (XDR * xdrs, double_matrice * dm)
{
    bool_t res;
    matrice * m1 = get_m1 (dm);
    matrice * m2 = get_m2 (dm);

    if((res = xdr_int (xdrs, & m1->taille))==FALSE)
		return res;
    init (m1, m_dim (m1));
    init (m2, m_dim (m1));
    if ((res = xdr_matrice_interne (xdrs, m1))==FALSE)
		return res;
    res = xdr_matrice (xdrs, m2);

    return res;
}
