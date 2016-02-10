#ifndef STRING_H_
#define STRING_H_

#include <stdbool.h>
#include "list.h"

typedef List String;

String sinit();
int    slength(String s);
void   sinserts(String *dst, String *src, int n);
void   sinsertc(String *dst,  int n, char ch);
String ssubstr(String s, int from, int to);
bool   sissubstr(String s1, String s2);
bool   sstartwith(String s1, String s2);
void   sdestro(String *s);
int    scompare(String s1, String s2);
String sconcat(String s1, String s2);
char   snth(String s, int n);
void   sdeleter(String *s, int from, int to);
void   sdeleten(String *s, int n);
String cstr2str(const char *s);
char * str2cstr(String s);

#endif // STRING_H_
