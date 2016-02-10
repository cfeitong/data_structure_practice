#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "test_string.h"
#include "../string.h"

int main() {

  test_string_init();
  test_string_lenth();
  test_string_insert();
  test_string_substr();
  test_string_issubstr();
  test_string_compare();
  test_string_delete();
  test_string_concat();

  return 0;
}

void test_string_init() {
  const char *test_type = "string", *test_content = "init";
  bool ok = 1;
  String s = sinit();
  ok &= !s.size;


  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s);
}

void test_string_lenth() {
  const char *test_type = "string", *test_content = "lenth";
  bool ok = 1;

  String s = cstr2str("123456789");
  if (slength(s) != 9) {
    ok = 0;
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s);
}

void test_string_insert() {
  const char *test_type = "string", *test_content = "insert";
  bool ok = 1;
  String s = sinit();

  for (int i = 0; i < 100; i++) {
    sinsertc(&s, 0, i);
  }

  for (int i = 0; i < 100; i++) {
    if (snth(s, i)+1 != 100-i) {
      ok = 0;
      break;
    }
  }

  String n = sinit();
  for (int i = 0; i < 10; i++) {
    sinsertc(&n, 0, i+'0');
  }

  String t = cstr2str("9876543210");
  sinserts(&n, &t, 5);

  char *tt = str2cstr(n);
  if (strcmp("98765987654321043210", tt) != 0) {
    ok = 0;
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  free(tt);
  sdestro(&s);
  sdestro(&t);
  sdestro(&n);
}

void test_string_substr() {
  const char *test_type = "string", *test_content = "substr";
  bool ok = 1;

  String s = sinit();
  for (int i = 0; i < 10; i++) {
    sinsertc(&s, s.size, i);
  }
  String n = ssubstr(s, 3, 7);

  for (int i = 0; i < n.size; i++) {
    if (snth(n, i) != i+3) {
      ok = 0;
      break;
    }
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s);
  sdestro(&n);
}

void test_string_issubstr() {
  const char *test_type = "string", *test_content = "issubstr";
  bool ok = 1;

  String s1 = cstr2str("123456789");
  String s2 = cstr2str("4567");
  String s3 = cstr2str("688");

  if (!sissubstr(s1, s2) || sissubstr(s1, s3)) {
    ok = 0;
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s1);
  sdestro(&s2);
  sdestro(&s3);
}

void test_string_compare() {
  const char *test_type = "string", *test_content = "compare";
  bool ok = 1;

  String s1 = cstr2str("123456789");
  String s2 = cstr2str("987654321");
  String s3 = cstr2str("292");

  if (scompare(s1, s2) != -1 ||
      scompare(s2, s1) != 1  ||
      scompare(s1, s1) != 0  ||
      scompare(s1, s3) != 1  ||
      scompare(s3, s2) != -1
      ) {
    ok = 0;
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s1);
  sdestro(&s2);
  sdestro(&s3);
}

void test_string_delete() {
  const char *test_type = "string", *test_content = "delete";
  bool ok = 1;

  String s1 = cstr2str("0123456789");
  sdeleter(&s1, 4, 7);
  char *t = str2cstr(s1);

  if (strcmp(t, "0123789") != 0) {
    ok = 0;
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s1);
  free(t);
}

void test_string_concat() {
  const char *test_type = "string", *test_content = "concat";
  bool ok = 1;
  String s1 = sinit();
  String s2 = sinit();

  for (int i = 0; i < 50; i++) {
    sinsertc(&s1, s1.size, i);
  }

  for (int i = 0; i < 50; i++) {
    sinsertc(&s2, s2.size, i+50);
  }

  String s3 = sconcat(s1, s2);

  for (int i = 0; i < 100; i++) {
    if (snth(s3, i) != i) {
      ok = 0;
      break;
    }
  }

  if (!ok) {
    printf("%s test fails on %s.\n", test_type, test_content);
  }

  sdestro(&s1);
  sdestro(&s2);
  sdestro(&s3);
}
