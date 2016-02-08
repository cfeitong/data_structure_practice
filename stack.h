#ifndef STACK_H_
#define STACK_H_

#include <stdbool.h>
#include "list.h"

typedef List Stack;

List   stinit();
void   stdestro(Stack *st);
void   stpush(Stack *st, int val);
int    stpop(Stack *st);
bool   stempty(Stack st);

#endif // STACK_H_
