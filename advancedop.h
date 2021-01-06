/*
* Advanced Operation.
* Complexe Operation using logicop and basicop
*
*/

#ifndef _AOP_H_
#define _AOP_H_

#include <stdio.h>
#include <stdlib.h>
#include "num.h"

/*Do a (base^exp)%m, at furiously fast rate ! */
void _MODPOW(struct num* base, struct num* exp, struct num* m);

#endif