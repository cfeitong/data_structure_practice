#include <stdbool.h>
#include <assert.h>
#include "deque.h"

Deque dqinit() {
  return lcreat();
}

void  dqdestro(Deque *q) {
  ldestro(q);
}

void  dqpush_front(Deque *q, int val) {
  linsertn(q, 0, val);
}

int   dqpop_front(Deque *q) {
  assert(q->size > 0);

  int save = lnth(*q, 0)->val;
  ldeleten(q, 0);

  return save;
}

void  dqpush_back(Deque *q, int val) {
  lappendn(q, val);
}

int   dqpop_back(Deque *q) {
  assert(q->size > 0);

  int save = lnth(*q, q->size-1)->val;
  ldeleten(q, q->size-1);

  return save;
}

bool  dqempty(Deque q) {
  return !q.size;
}
