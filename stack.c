#include "stack.h"

Stack   stinit() {
  return lcreat();
}

void   stdestro(Stack *st) {
  ldestro(st);
}

void stpush(Stack *st, int val) {
  lappendn(st, val);
}

int stpop(Stack *st) {
  int save = lnth(*st, st->size-1)->val;
  ldeleten(st, st->size-1);
  return save;
}

bool stempty(Stack st) {
  return !st.size;
}

