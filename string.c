#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "string.h"

String  sinit() {
  return lcreat();
}

int    slength(String s) {
  return s.size;
}

String ssubstr(String s, int from, int to) {
  String res = sinit();
  for (LNode *it = lnth(s, to-1); it != lnth(s, from-1); it = it->prev) {
    linsertn(&res, 0, it->val);
  }
  return res;
}

void   sinserts(String *dst, String *src, int n) {
  List newl = lcopy(*src);
  LNode *former = lnth(*dst, n-1), *latter = lnth(*dst, n);
  llinkn(former, newl.head->next);
  llinkn(newl.tail->prev, latter);
  dst->size += src->size;
}

void   sdestro(String *s) {
  ldestro(s);
}

void   sinsertc(String *dst, int n, char ch) {
  linsertn(dst, n, ch);
}

char   snth(String s, int n) {
  return lnth(s, n)->val;
}

bool   sissubstr(String s1, String s2) {
  if (s1.size < s2.size) {
    return false;
  }
  for (int i = 0; i < s1.size; i++) {
    int j = 0;
    for (j = 0; j < s2.size; j++) {
      if (snth(s1, i+j) != snth(s2, j)) {
        break;
      }
    }
    if (j == s2.size) {
      return true;
    }
  }
  return false;
}

bool   sstartwith(String s1, String s2) {
  if (s1.size < s2.size) {
    return false;
  }

  for (int i = 0; i < s2.size; i++) {
    if (snth(s1, i) != snth(s2, i)) {
      return false;
    }
  }
  return true;
}

int   scompare(String s1, String s2) {
  if (s1.size < s2.size) {
    return -1;
  }
  else if (s1.size > s2.size) {
    return 1;
  }
  else {
    for (int i = 0; i < s1.size; i++) {
      if (snth(s1, i) < snth(s2, i)) {
        return -1;
      }
      else if (snth(s1, i) > snth(s2, i)) {
        return 1;
      }
    }
    return 0;
  }
}

String sconcat(String s1, String s2) {
  String n1 = lcopy(s1), n2 = lcopy(s2);

  llinkn(n1.tail->prev, n2.head->next);
  llinkn(n2.tail->prev, n1.tail);

  free(n2.head); free(n2.tail);
  n1.size = s1.size + s2.size;

  return n1;
}

void   sdeleter(String *s, int from, int to) {
  ldeleter(s, from, to);
}

void   sdeleten(String *s, int n) {
  ldeleten(s, n);
}

String cstr2str(const char *s) {
  String n = sinit();
  for (int i = strlen(s)-1; i>=0; i--) {
    linsertn(&n, 0, s[i]);
  }

  n.size = strlen(s);

  return n;
}

char * str2cstr(String s) {
  char *n = (char *) malloc(s.size * sizeof(char));

  int i = 0;
  for (i = 0; i < s.size; i++) {
    n[i] = snth(s, i);
  }

  n[i] = 0;
  return n;
}
