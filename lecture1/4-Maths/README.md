# Algebraic operations

C supports classical algebraic operators.

[arithmetic.c](./arithmetic.c)
```c
for ( int i = 0; i < 128; i++ )
{
    printf( "%c:  %d\n", i, i );
}
```

Notes:

`/` is the integer division operator when the numerator and denominator are integers.

`%` is the modulus (remainder) operator.