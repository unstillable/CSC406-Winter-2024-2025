#include <stdio.h>

int main()
{
    int val = 12345;
    float a = 3.14;
    int* valp;
    float* ap;

    printf( "val = %d\n", val );
    printf( "a = %3.2f\n", a );
    printf( "&val = %p\n", &val );
    printf( "&a = %p\n", &a );

    valp = &val;
    ap = &a;
    printf( "valp = %p\n", valp );
    printf( "ap = %p\n", ap );
}
