#ifndef DEQUE_H_
#define DEQUE_H_

#include <stdbool.h>
#include "list.h"

typedef List Deque;

Deque dqinit();
void  dqpush_front(Deque *q, int val);
int   dqpop_front(Deque *q);
void  dqpush_back(Deque *q, int val);
int   dqpop_back(Deque *q);
bool  dqempty(Deque q);
void  dqdestro(Deque *q);

#endif // DEQUE_H_
