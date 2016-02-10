#include <stdio.h>
#include "test_deque.h"
#include "../deque.h"

int main() {

  test_deque_init();
  test_deque_operation();

  return 0;
}

void test_deque_init() {
  Deque dq = dqinit();
  if (dq.size) {
    printf("Deque test fails on init.\n");
  }
  dqdestro(&dq);
}

void test_deque_operation() {
  Deque dq = dqinit();
  bool ok = 1;

  for (int i = 0; i < 500; i++) {
    dqpush_back(&dq, i);
  }

  for (int i = 1000; i < 1500; i++) {
    dqpush_back(&dq, i);
  }

  for (int i = 0; i < 500; i++) {
    if (dqpop_front(&dq) != i) {
      ok = 0;
      break;
    }
  }

  if (dq.size != 500) {
    ok = 0;
  }

  for (int i = 0; i < 500; i++) {
    if (dqpop_back(&dq)+1 != 1500-i) {
      ok = 0;
      break;
    }
  }

  if (dq.size != 0) {
    ok = 0;
  }

  if (!ok) {
    printf("Deque test fails on operation.\n");
  }

  dqdestro(&dq);
}
