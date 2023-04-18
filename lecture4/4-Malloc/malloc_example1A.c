#include <stdlib.h>   // to use malloc, free 
#include <stdio.h>    // scanf

#define IDX(n, i, j) ((i)*(n)+(j))

int main () {

  int i, j, n;

  printf("What size matrix do you need? ");
  scanf("%d", &n);

  // Dynamically obtain an array of n*n integers
  long *t = (long *) malloc(sizeof(long) * n * n);

  // Put value i+j in row i, column j of t
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      t[IDX(n,i,j)] = i+j;

  // Print the value in table t, row by row
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      printf("%d ", t[IDX(n,i,j)]);
    printf("\n");
  }

  return 0;
}
