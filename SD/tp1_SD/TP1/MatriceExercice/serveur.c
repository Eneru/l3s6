#include "include.h"

entiers2 * divise(entiers2 *e) { 
  static entiers2 res;
  res.x = e->x / e->y;
  res.y = e->x % e->y;
  return &res;
}
int main (void) {
  bool_t stat;
  stat = registerrpc(PROGNUM,VERSNUM,PROCNUM,divise,(xdrproc_t)xdr_entiers2,(xdrproc_t)xdr_entiers2);
  if (stat != 0) {
    fprintf(stderr,"Echec de l'enregistrement\n");
    exit(1);
  }
  svc_run(); /* le serveur est en attente de clients eventuels */
  return(0); /* on y passe jamais ! */
}


