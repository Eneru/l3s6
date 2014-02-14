#include "include.h"

int main (int argc, char **argv) {
  char *host = argv[1];
  enum clnt_stat stat;
  entiers2 res;
  entiers2 donnees = {13 , 5};
  stat = callrpc(host,PROGNUM,VERSNUM,PROCNUM,(xdrproc_t) xdr_entiers2,(char *)&donnees,(xdrproc_t)xdr_entiers2,(char *)&res); 

  if (stat != RPC_SUCCESS) { 
    fprintf(stderr, "Echec de l'appel distant\n");
    clnt_perrno(stat);      fprintf(stderr, "\n");
  } else {
    printf("client res : %d/%d (q:%d r:%d)\n",
	   donnees.x,donnees.y,res.x,res.y);
  }
  return(0);
}
