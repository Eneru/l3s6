#include "include.h"
#include "string.h"

static void init_client (double_matrice * donnees, matrice * resultat)
{
	int valeur;
	printf("Entrez la taille des matrices : ");
	scanf("%d",&valeur);
	printf("\n");
	
    dinit (donnees, valeur);
    init (resultat, valeur);

    matrice * m1 = get_m1 (donnees);
    matrice * m2 = get_m2 (donnees);

    for (int i = 0; i < m_dim (m1); i++)
    {
        for (int j = 0; j < m_dim (m1); j++)
        {
			printf("Veuillez entrer la valeur m1[%d][%d] : ",i,j);
			scanf("%d",&valeur);
			set_m(m1, i, j, valeur);
			printf("\n");
        }
    }
    
    for (int i = 0; i < m_dim (m1); i++)
    {
        for (int j = 0; j < m_dim (m1); j++)
        {
			printf("Veuillez entrer la valeur m2[%d][%d] : ",i,j);
			scanf("%d",&valeur);
			set_m(m2, i, j, valeur);
			printf("\n");
        }
    }
}

static unsigned long choix_operation (const char * arg)
{
    if (strcmp (arg, "addition") == 0)
        return PROGNUM_ADD;
    else if (strcmp (arg, "multiplication") == 0)
        return PROGNUM_MULT;
    else
        return 0;
}

static char operation_vers_char (unsigned long op)
{
    return op == PROGNUM_ADD ? '+' : '*';
}

static void afficher_resultats (double_matrice * dm, matrice * r, unsigned long op)
{
    ddisplay (dm);
    printf ("Matrice 1 %c Matrice 2 :\n", operation_vers_char (op));
    display (r);

}

int main (int argc, char ** argv)
{
    if (argc != 3)
    {
        fprintf (stderr, "Usage: %s <host> <addition | multiplication>\n", argv[0]);
        exit (EX_USAGE);
    }

    unsigned long op = choix_operation (argv[2]);

    if (op == 0)
    {
        fprintf (stderr, "%s : Opération invalide.\n", argv[2]);
        exit (EX_USAGE);
    }

    enum clnt_stat stat;
    matrice resultat;
    double_matrice donnees;

    init_client (& donnees, & resultat);

    char * host = argv[1];

    stat = callrpc
    (
        host,
        op,
        VERSNUM,
        PROCNUM,
        (xdrproc_t) xdr_double_matrice,
        (char *) & donnees,
        (xdrproc_t) xdr_matrice,
        (char *) & resultat
    );

    if (stat != RPC_SUCCESS)
    {
        fprintf (stderr, "Echec de l'appel distant\n");
        clnt_perrno (stat);
        fprintf(stderr, "\n");
    }
    else
        afficher_resultats (& donnees, & resultat, op);

    dm_lib (& donnees);
    m_lib (& resultat);

    return (0);
}
