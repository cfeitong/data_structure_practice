#include <assert.h>
#include "queue.h"

Queue qinit() {
  return lcreat();
}

void  qdestro(Queue *q) {
  ldestro(q);
}

void  qpush(Queue *q, int val) {
  lappendn(q, val);
}

int   qpop(Queue *q) {
  assert(q->size > 0);

  int save = lnth(*q, 0)->val;
  ldeleten(q, 0);

  return save;
}

bool  qempty(Queue q) {
  return !q.size;
}
