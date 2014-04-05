#ifndef INCRPC
#define INCRPC  

#include <rpc/types.h>
#include <rpc/xdr.h>
#include <rpc/rpc.h>
#include <sysexits.h>

#define PROGNUM_ADD 0x20000102
#define PROGNUM_MULT 0x20000103
#define VERSNUM 1
#define PROCNUM 1

typedef struct matrice
{
    int taille;
    int ** m;
} matrice;

typedef struct double_matrice
{
    matrice m1;
    matrice m2;
} double_matrice;

bool_t xdr_matrice (XDR * xdrs, matrice * m);
bool_t xdr_matrice_serveur (XDR * xdrs, matrice * m);
bool_t xdr_double_matrice (XDR * xdrs, double_matrice * dm);
bool_t xdr_double_matrice_serveur (XDR * xdrs, double_matrice * dm);

static inline void init (matrice * m, int dimension)
{
    m->taille = dimension;
    m->m = malloc (dimension * sizeof * m->m);
    for (int i = 0; i < dimension; i++)
        m->m[i] = malloc (dimension * sizeof * m->m[i]);
}

static inline int m_dim (matrice * m)
{
    return m->taille;
}

static inline void m_lib (matrice * m)
{
    for (int i = 0; i < m_dim (m); i++)
        free (m->m [i]);
    free (m->m);
}

static inline int m_elem (matrice * m, int x, int y)
{
    return m->m[x][y];
}

static inline void set_m (matrice * m, int x, int y, int valeur)
{
    m->m[x][y] = valeur;
}

static inline void display (matrice * m)
{
    for (int i = 0; i < m_dim (m); i++)
    {
        for (int j = 0; j< m_dim (m); j++)
            printf ("%d\t", m_elem (m, i, j));
        printf("\n\n");
    }
}

static inline matrice * get_m1 (double_matrice * dm)
{
    return & dm->m1;
}

static inline matrice * get_m2 (double_matrice * dm)
{
    return & dm->m2;
}

static inline void ddisplay (double_matrice * dm)
{
    printf ("Matrice 1:\n");
    display (get_m1 (dm));
    printf ("Matrice 2:\n");
    display (get_m2 (dm));
}

static inline void dinit (double_matrice * dm, int dimension)
{
    init (get_m1 (dm), dimension);
    init (get_m2 (dm), dimension);
}

static inline void dm_lib (double_matrice * dm)
{
    m_lib (get_m1 (dm));
    m_lib (get_m2 (dm));
}

#endif /* INCRPC */
