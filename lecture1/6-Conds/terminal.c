# include <stdio.h>
//
//  Program 5.7, Stephen Kochan, Programming in C.
//

int main( void )
{
    char c;

    printf( "Enter a single character to be classified: \n" );
    scanf( "%c", &c );

    if ( ( 'a' <= c && c <= 'z' ) || ( 'A' <= c && c <= 'Z' ) )
        printf( "\"%c\" is an alphabetic character.\n", c );
    else if ( '0' <= c && c <= '9' )
        printf( "\"%c\" is a digit.\n", c );
    else
        printf( "\"%c\" is a special character.\n", c );

    return 0;
}
