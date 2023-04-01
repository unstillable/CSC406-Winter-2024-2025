#include <stdio.h>

int main()
{
        int x;
        printf("enter a signed number: ");
        scanf("%i", &x);
        printf("signed: %i,\nunsigned: %u\n", x, x);
        return 0;
}
