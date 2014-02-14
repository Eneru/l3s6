#include "include.h"
bool_t xdr_entiers2(XDR *xdrs, entiers2 *e) {
  bool_t res;
  res = xdr_int(xdrs, &e->x);
  if (res == 1)
	res = xdr_int(xdrs, &e->y);
  return res;
}
