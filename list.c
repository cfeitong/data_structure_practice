#include <stdlib.h>
#include <assert.h>
#include "list.h"


void llinkn(LNode *n1, LNode *n2) {
  n1->next = n2;
  n2->prev = n1;
}

List    lcopy(List l) {
  List n = lcreat();
  for (int i = l.size-1; i >= 0; i--) {
    linsertn(&n, 0, lnth(l, i)->val);
  }
  return n;
}

LNode * lcreatn() {
  LNode *n = (LNode *) malloc (sizeof(LNode));
  n->val = 0;
  n->next = n->prev = NULL;

  return n;

}

LNode * lnth(List lst, int n) {
  assert(-1 <= n && n <= lst.size);
  LNode *it;
  if (n == -1) {
    it = lst.head;
  }
  else {
    if (n < lst.size/2) {
      for (it = lst.head->next; n; n--, it = it->next);
    }
    else {
      n = lst.size - n;
      for (it = lst.tail; n; n--, it = it->prev);
    }
  }
  return it;
}

void  ldestro(List *lst) {
  for (LNode *it = lst->head->next; it != lst->tail; it = it->next) {
    free(it->prev);
  }
  free(lst->tail);
}

List    lcreat() {
  List lst;
  lst.head = lcreatn();
  lst.tail = lcreatn();

  llinkn(lst.head, lst.tail);
  lst.size = 0;

  return lst;
}

void    linsertn(List *lst, int pos, int val) {
  assert(pos <= lst->size);

  LNode *latter = lnth(*lst, pos);
  LNode *former = latter->prev;
  LNode *newnode = lcreatn();

  newnode->val = val;
  llinkn(former, newnode);
  llinkn(newnode, latter);
  lst->size++;
}

void    ldeleter(List *lst, int from, int to) {
  assert(from < lst->size);
  assert(to <= lst->size);
  LNode *start = lnth(*lst, from-1), *end = lnth(*lst, to);

  for (LNode *i = lnth(*lst, from+1); i != end; i = i->next) {
    free(i->prev);
  }
  free(end->prev);

  llinkn(start, end);
  lst->size -= to-from;

}

void    ldeleten(List *lst, int pos) {
  ldeleter(lst, pos, pos+1);
}

void    lappendn(List *lst, int val) {
  linsertn(lst, lst->size, val);
}

char  * list2cstr(List lst) {
  char *res = (char *) malloc(lst.size*sizeof(char)+1);

  int i;
  for (i = 0; i < lst.size; i++) {
    res[i] = lnth(lst, i)->val;
  }
  res[i] = '\0';

  return res;
}

List    cstr2list(const char *s) {
  List res = lcreat();
  for (int i = 0; s[i]; i++) {
    lappendn(&res, s[i]);
  }
  return res;
}
