#include <stdio.h>
#define ARRAY_SIZE 100
int main() {
  int i, j;
  int A[ARRAY_SIZE] = {0};

  for (i = 2; i < ARRAY_SIZE; i++){
      A[i] = 1;
  }
  
  for (i = 2; i < ARRAY_SIZE; i++ ) {
    for (j = 2; j * i < ARRAY_SIZE; j++) {
        A[j * i] = 0;
    }
  }

  for (i = 2; i < ARRAY_SIZE; i++){
    if (A[i] == 1)
        printf("%d ", A[i] * i);
    
  }

  printf("\n");

  return 0;
}