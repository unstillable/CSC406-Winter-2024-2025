# Functions

- [Function Declaration](#function-declaration)
- [Parameter passing](#parameter-passing)

## Function Declaration

Functions in C are defined as you may expect for a (*fairly*) strongly typed language:

```c++
return_type function_name(parameter1_type parameter1, parameter2_type parameter2)
{
    // do the needful
    // create an instance of "return_type" named thing.
    return thing; // return that instance
}
```

[power.c](./power.c)

## Parameter passing

In C, function arguments are passed "by value".

This means that the called function is given **copies** of the original values. For example, when the main program executes `power(2, i)`, when the value of i is 5, copies of `2` and `5` are written to local variables `base` and `n` (they are local to the execution of function power):

```c
int power(int base, int n)
{
  int i, p;                     
  p = 1;                        
  for (i = 1; i <= n; ++i)      
    p = p * base;
  return p;
}
```
