#include <stdio.h>

int main()
{
    int i, x;

    x = 0;
    for ( i = 0; i < 5; i++ )
    {
        if ( i % 2 == 0 )
            continue;
        x = x - i;
        if ( i % 3 == 0 )
            break;
        printf( "%d\n", x );
    }
}

