#include <stdio.h>
#include<iostream>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc1(const void * a, const void * b) {
  return (*(int*)a - *(int*)b);
}

int cmpfunc2(const void * a, const void * b) {
  return (*(int*)b - *(int*)a);
}


void runQuickSort() {
  int n;

  printf("Before sorting the list is: \n");
  for (n = 0; n < 5; n++) {
    printf("%d ", values[n]);
  }

  qsort(values, 5, sizeof(int), cmpfunc1);

  printf("\nAfter sorting the list first time: \n");
  for (n = 0; n < 5; n++) {
    printf("%d ", values[n]);
  }

  qsort(values, 5, sizeof(int), cmpfunc2);

  printf("\nAfter sorting the list second time: \n");
  for (n = 0; n < 5; n++) {
    printf("%d ", values[n]);
  }

  

  std::cin.get();
}