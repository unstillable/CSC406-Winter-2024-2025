# Loops

- [For Loop](#for-loop)
- [While loop](#while-loop)
- [Do-While loop](#do-while-loop)
- [Examples](#examples)
- [Symbolic Constants](#symbolic-constants)
- [Macros](#macros)
---

There are three types of loops in C:

## For Loop

A loop with a starting and an ending condition, and an initializer

```c
for( int i = 0; i < 10; ++i )
{ 
}
```

## While loop

Loop with a terminal condition only that is tested **before** the first iteration

```c
while( 1 ){ }
```

## Do-While loop

Loop with a terminal condition only that is tested **after** the first iteration.
Good when you want to do something at least once.

```c
do {

} while( 1 );
```
   
## Examples 

* [loops.c](./loops.c)
* [sum.c](./sum.c)
* [temp.c](./temp.c)


## Symbolic Constants

Note the use of `#define` line to define symbolic constants `LOWER`, `UPPER`, and `STEP`.

It is good practice to use them instead of "burying" numbers like 300 and 20 deep inside the code. 

    Note: Symbolic constants can refer to values of any type (int, char, string, float, etc.)


The command `#define STEP 20` causes any occurrence of the word `STEP` in your source file to be replaced by `12` by the [**preprocessor**](../1-First/README.md#preprocessing-still-c-code). 

## Macros
Note also the use of the function-like `macro` ftoc; the code fragment $(5.0/9.0)*((fahr)-32)$ will be used to substitute every occurrence of `ftoc(fahr)`in the source code.