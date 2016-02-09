#include <stdio.h>
#include "../queue.h"
#include "test_queue.h"

int main() {
  test_queue_init();
  test_queue_operation();
  test_queue_empty();

  return 0;
}

void test_queue_init() {
  Queue q = qinit();
  if (q.size) {
    printf("Queue test fails on init.\n");
  }
}

void test_queue_operation() {
  Queue q = qinit();
  bool ok = 1;

  for (int i = 0; i < 1000; i++) {
    qpush(&q, i);
  }

  if (q.size != 1000) {
    ok = 0;
  }

  for (int i = 0; i < 1000; i++) {
    if (qpop(&q) != i) {
      ok = 0;
      break;
    }
  }

  if (q.size != 0) {
    ok = 0;
  }

  if (!ok) {
    printf("Queue test fails on operation.\n");
  }

}

void test_queue_empty() {
  Queue q = qinit();
  for (int i = 0; i < 5000; i++) {
    qpush(&q, i);
  }

  for (int i = 0; i < 5000; i++) {
    qpop(&q);
  }

  if (q.size != 0) {
    printf("Queue test fails on empty.\n");
  }
}
