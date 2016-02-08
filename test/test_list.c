#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "test_list.h"
#include "../list.h"

int main() {
  test_list_cstr_convertion();
  test_list_insertion();
  test_list_deletion();
  test_list_get_element();

  return 0;
}

void DO_TEST(bool (*f)(const char *s) , const char *string) {
  if (!f(string)) {
    fprintf(stderr, "list test fails with %s\n" , string);
  }
}

void test_list_cstr_convertion() {
  DO_TEST(double_convertion, "");
  DO_TEST(double_convertion, "1234567890");
  DO_TEST(double_convertion, "111111111");
  DO_TEST(double_convertion, "9kdsaf0jf023ijf0");
  DO_TEST(double_convertion, "9wqj0ffffffffffffe9jf09wqejf9w0jf"
          "9ew0jfqw90jf9ef0qjfj0q9jf9f0ew9qjfw9efjbb");
}

void test_list_insertion() {
  DO_TEST(insertion, "");
  DO_TEST(insertion, "1234567890");
  DO_TEST(insertion, "111111111");
  DO_TEST(insertion, "9kdsaf0jf023ijf0");
}

void test_list_deletion() {
  DO_TEST(deletion, "");
  DO_TEST(deletion, "1234567890");
  DO_TEST(deletion, "111111111");
  DO_TEST(deletion, "9kdsaf0jf023ijf0");
}

void test_list_get_element() {
  DO_TEST(get_element, "");
  DO_TEST(get_element, "1234567890");
  DO_TEST(get_element, "111111111");
  DO_TEST(get_element, "9kdsaf0jf023ijf0");
}

bool double_convertion(const char *s) {
  List t = cstr2list(s);
  char *n = list2cstr(t);
  bool res = !strcmp(s, n);

  free(n);
  ldestro(&t);

  return res;
}

bool insertion(const char *s) {
  List t = cstr2list("");
  for (int i = 0; i < strlen(s); i++) {
    linsertn(&t, i, (int) s[i]);
  }
  char *n = list2cstr(t);
  bool res = !strcmp(n, s);

  ldestro(&t);
  free(n);

  return res;
}

bool deletion(const char *s) {
  List t = cstr2list(s);
  for (int i = 0; i < strlen(s); i++) {
    ldeleten(&t, 0);
  }
  for (int i = 0; i < strlen(s); i++) {
    linsertn(&t, i, s[i]);
  }
  char *n = list2cstr(t);
  bool res = !strcmp(s, n);

  free(n);
  ldestro(&t);

  return res;
}

bool get_element(const char *s) {
  List t = cstr2list(s);
  char *n = list2cstr(t);

  bool res = 1;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] != lnth(t, i)->val) {
      res = 0;
      break;
    }
  }

  free(n);
  ldestro(&t);

  return res;
}
