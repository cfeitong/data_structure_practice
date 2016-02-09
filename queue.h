#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include "list.h"

typedef List Queue;

Queue qinit();
void  qpush(Queue *q, int val);
int   qpop(Queue *q);
bool  qempty(Queue q);
void  qdestro(Queue *q);

#endif
