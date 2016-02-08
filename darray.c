// dynamic array
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "darray.h"

static bool adjust_size(Darray *tar, int scale); // adjust to scale%

static bool adjust_size(Darray *tar, int scale) { // adjust to scale%
  assert(scale >= 0);

  Darray t;
  t.cap = scale * tar->cap / 100;
  t.arr = (int *) malloc(tar->cap * sizeof(int));
  if (t.arr == NULL) {
    return false;
  }
  else {
    memcpy(t.arr, tar->arr, tar->size*sizeof(int));
    *tar = t;
    return true;
  }
}

Darray dainit() {
  Darray res;
  res.size = 0;
  res.cap = INIT_SIZE;
  res.arr = (int *) malloc(INIT_SIZE*sizeof(int));
  return res;
}

bool dagrow(Darray *tar) {
  if (tar->size > tar->cap / 2) {
    return adjust_size(tar, 200);
  }
  return false;
}

bool dashrink(Darray *tar) {
  if (tar->size < tar->cap / 4) {
    return adjust_size(tar, 50);
  }
  return false;
}

void adappendn(Darray *tar, int val) {
  tar->size++;
  dagrow(tar);
  tar->arr[tar->size-1] = val;
}

void addeletr(Darray *tar, int from, int to) {
  assert(0 <= from && from < tar->size);
  assert(0 <= to && to <= tar->size);

  int delta = to - from;

  for (int i = from; i < to && i+delta < tar->size; i++) {
    tar->arr[i] = tar->arr[i+delta];
  }

  tar->size -= delta;

  dashrink(tar);
}

int addeletn(Darray *tar, int n) {
  int save = danth(*tar, n);
  addeletr(tar, n, n+1);
  return save;
}

int danth(Darray tar, int n) {
  assert(0 <= n && n < tar.size);
  return tar.arr[n];
}

void dadestro(Darray *tar) {
  free(tar->arr);
  tar->cap = tar->size = 0;
}
