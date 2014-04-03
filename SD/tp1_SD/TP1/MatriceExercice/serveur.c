#include "include.h"

/* Variable globale pour les résultats. */
static matrice resultat;

static void addition (matrice * m1, matrice * m2, matrice * r)
{
    for (int i = 0; i < m_dim (r); i++)
        for (int j = 0; j < m_dim (r); j++)
            set_m (r, i, j, m_elem (m1, i, j) + m_elem (m2, i, j));
}

static void multiplication (matrice * m1, matrice * m2, matrice * r)
{
    for (int i = 0; i < m_dim (r); i++)
        for (int j  = 0; j < m_dim (r); j++)
        {
            int temp = 0;

            for (int k = 0; k < m_dim (r); k++)
                temp += m_elem (m1, i, k) * m_elem (m2, k, j);

            set_m (r, i, j, temp);
        }
}

static matrice * effectuer_operation (double_matrice * dm, void (* operation) (matrice *, matrice *, matrice *))
{
    matrice * m1 = get_m1 (dm);
    matrice * m2 = get_m2 (dm);
    matrice * r = &resultat;
    
    init (r, m_dim (m1));
    operation (m1, m2, r);
    dm_lib (dm);

    return r;

}

static matrice * additionne (double_matrice * dm)
{
    return effectuer_operation (dm, addition);
}

static matrice * multiplie (double_matrice * dm)
{
    return effectuer_operation (dm, multiplication);
}

static void enregistrement (unsigned long prognum, matrice * (* procname) (double_matrice *))
{
    bool_t stat;

    stat = registerrpc
    (
        prognum,
        VERSNUM,
        PROCNUM,
        procname,
        xdr_double_matrice_serveur,
        xdr_matrice_serveur
    );

    if (stat != 0)
    {
        fprintf (stderr, "Échec de l'enregistrement\n");
        exit (EX_OSERR);
    }
}

int main (void)
{
    enregistrement (PROGNUM_ADD, additionne);
    enregistrement (PROGNUM_MULT, multiplie);
    svc_run (); /* le serveur est en attente de clients eventuels */

    return (0); /* on y passe jamais ! */
}
