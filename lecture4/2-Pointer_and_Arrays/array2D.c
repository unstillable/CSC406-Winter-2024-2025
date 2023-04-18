#include <stdio.h>
#include <stdlib.h>

long A[2][3] = {
  {2,0,4},
  {1,3,0}
};

void main ()
{
  int i,j;
  long s = A[0][2] + A[1][0];

  printf("s = %li\n", s);
  A[0][2] = 1;
  
  for (i=0; i<2; i++) {
    for (j = 0; j < 3; j++) {
      printf("%li ", A[i][j]);
    }
    printf("\n");
  }
}
