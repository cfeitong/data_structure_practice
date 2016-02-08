#include <stdio.h>
#include "../darray.h"
#include "test_darray.h"

int main() {

  test_dynamic_array_init();
  /* test_dynamic_array_append(); */
  /* test_dynamic_array_delete(); */
  /* test_dynamic_array_grow(); */
  /* test_dynamic_array_shrink(); */
  /* test_dynamic_array_visit(); */

  return 0;
}

void test_dynamic_array_init() {
  Darray n = dainit();
  if (n.size != 0 || n.cap != INIT_SIZE) fprintf(stderr, "Test fails on init\n");
}

void test_dynamic_array_append() {

}

void test_dynamic_array_delete() {
  
}

void test_dynamic_array_grow() {
  
}

void test_dynamic_array_shrink() {
  
}

void test_dynamic_array_visit() {
  
}
