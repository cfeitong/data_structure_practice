#include <stdio.h>
#include <stdbool.h>
#include "../darray.h"
#include "test_darray.h"

int main() {

  test_dynamic_array_init();
  test_dynamic_array_append();
  test_dynamic_array_delete();
  test_dynamic_array_grow();
  test_dynamic_array_shrink();

  return 0;
}

void test_dynamic_array_init() {
  Darray n = dainit();
  if (n.size != 0 || n.cap != DAINIT_SIZE) fprintf(stderr, "Test fails on init\n");
  dadestro(&n);
}

void test_dynamic_array_append() {
  Darray n = dainit();
  for (int i = 0; i < 2000; i++) {
    daappendn(&n, i);
  }

  bool ok = true;

  if (n.size != 2000) {
    ok = false;
  }
  for (int i = 0; i < 2000; i++) {
    if (danth(n, i) != i) {
      ok = false;
      printf("%d\t", i);
      break;
    }
  }
  if (!ok) {
    printf("Test fails on darray append.\n");
  }
}

void test_dynamic_array_delete() {
  bool ok = true;

  Darray n = dainit();

  for (int i = 0; i < 2000; i++) {
    daappendn(&n, i);
  }

  for (int i = 0; i < 1000; i++) {
    dadeleten(&n, 0);
  }

  for (int i = 0; i < 1000; i++) {
    if (danth(n, i) != i+1000) {
      ok = false;
      break;
    }
  }

  dadeleter(&n, 0, 500);

  for (int i = 0; i < 500; i++) {
    if (danth(n, i) != i+1500) {
      ok = false;
      break;
    }
  }

  if (!ok) {
    printf("Test fails on darray delete.\n");
  }
}

void test_dynamic_array_grow() {
  Darray n = dainit();
  for (int i = 0; i < DAINIT_SIZE/2+1; i++) {
    daappendn(&n, i);
  }
  if (!(n.cap == DAINIT_SIZE*2)) {
    printf("Test fails on array grow.\n");
  }
}

void test_dynamic_array_shrink() {
  Darray n = dainit();
  for (int i = 0; i < 256; i++) {
    daappendn(&n, i);
  }
  dadeleter(&n, 0, 195);
  if (n.cap == 128) {
    printf("Test fails on array shrink.\n");
  }
}
