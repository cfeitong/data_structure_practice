// dynamic array
#ifndef DARRAY_H_
#define DARRAY_H_

#define INIT_SIZE  32

typedef struct _Darray {
  int *arr;
  int size;
  int cap;
} Darray;

Darray dainit();
bool dagrow(Darray *tar);
bool dashrink(Darray *tar);
void adappendn(Darray *tar, int val);
void addeletr(Darray *tar, int from, int to);
int addeletn(Darray *tar, int n);
int danth(Darray tar, int n);

#endif // DARRAY_H_
