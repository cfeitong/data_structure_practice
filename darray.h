// dynamic array
#ifndef DARRAY_H_
#define DARRAY_H_

#define DAINIT_SIZE  32

typedef struct _Darray {
  int *arr;
  int size;
  int cap;
} Darray;

Darray dainit();
bool dagrow(Darray *tar);
bool dashrink(Darray *tar);
void daappendn(Darray *tar, int val);
void dadeleter(Darray *tar, int from, int to);
int dadeleten(Darray *tar, int n);
int danth(Darray tar, int n);
void dadestro(Darray *tar);

#endif // DARRAY_H_
