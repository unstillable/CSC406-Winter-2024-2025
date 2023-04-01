#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

#define BINARY 0

static char bin[42];
char* binary(int i)
{
    for (int pos=40; pos >= 0; --pos)
    {
        if (pos%5 ==0)
            bin[pos] = ' '; 
        else{ 
            bin[pos] = i & 0x1 == 1 ? '1' : '0';
            i = i >> 1;
        }
    }
    return bin;
}

void printbin(char* id, unsigned x)
{
  printf("%s:\t%s\n", id, binary(x));
}
void printhex(char* id, unsigned x)
{
  printf("%s:\t0x%08X\n", id, x);
}

int main()
{
        unsigned x;
        printf("enter an unsigned number: ");
        scanf("%u", &x);
        printbin("binary", x);
        printhex("hex", x);
        return 0;
}
