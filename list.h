#ifndef LIST_H_
#define LIST_H_

typedef struct _Node {
  int val;
  struct _Node *next;
  struct _Node *prev;
} LNode;

typedef struct _List {
  LNode *head;
  LNode *tail;
  int size;
} List;

LNode * lcreatn();
void    ldestro(List *lst);
List    lcreat();
void    linsertn(List *lst, int pos, int val);
void    lappendn(List *lst, int val);
void    ldeleter(List *lst, int from, int to);
void    ldeleten(List *lst, int pos);
LNode * lnth(List lst, int n);
char  * list2cstr(List lst);
List    cstr2list(const char *s);

#endif // LIST_H_
