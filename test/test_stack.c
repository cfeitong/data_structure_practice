#include <stdio.h>
#include <stdbool.h>
#include "../stack.h"
#include "test_stack.h"

int main() {
  test_stack_init();
  test_stack_operation();
  test_stack_empty();
  return 0;
}

void test_stack_init() {
  Stack st = stinit();
  if (st.size) printf("stack test fails on init.\n");
}

void test_stack_operation() {
  Stack st = stinit();
  for (int i = 0; i < 1000; i++) {
    stpush(&st, i);
  }

  bool ok = 1;
  if (st.size != 1000) {
    ok = 0;
  }

  for (int i = 0; i < 1000; i++) {
    if (stpop(&st)+1 != 1000-i) {
      ok = 0;
      break;
    }
  }

  if (!ok) {
    printf("stack test fails on operation.\n");
  }
}

void test_stack_empty() {
  Stack st = stinit();
  for (int i = 0; i < 5000; i++) {
    stpush(&st, i);
  }
  for (int i = 0; i < 5000; i++) {
    stpop(&st);
  }
  if (!stempty(st)) {
    printf("stack test fails on empty.\n");
  }
}
