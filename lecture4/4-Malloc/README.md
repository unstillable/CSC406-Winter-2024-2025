# Function malloc()

You can think of the function `malloc()` as C's version of the new operator you have seen in Java or C++ programs. You wouldn't be right, but hey, we all think believe crazy things. `new()` is going to call constructors and allocate memory and give you a pointer of the correct type. You can use `malloc` by including the `stdlib.h` header.

`malloc()`is *like* new in that it is used to dynamically (i.e., at run-time) allocate memory for you to use in your program, and it will return a pointer, but that pointer is `void*` and you need to ask for the amount of memory you want.

So far, we have mostly seen global and stack allocations:
```c
int global = 12;
int global_array[200];

...

int main()
{
    int stack_allocated = 3; 
    ...
};
```
Globals have their memory addresses defined by the linker. Stack allocated variables have their memory allocated when you call their surrounding function, but because you shouldn't use them after the function exits, sometimes you want to allocate memory outside of the stack.

That's where `malloc()` comes in.  It will do some implementation specific magic to acquire memory somewhere in your program for you to use, and it returns a pointer to that memory.  When you are done with that memory, you need to call `free()`. 

```c
void* x; // x is a pointer to a void - this is a generic address

x = malloc( 1 );  // x points to some address in memory

// note: using sizeof( void ) is invalid -- it will work in gcc, but not in anything else that I know.

free(x);  // you must pass in the address of the first byte that was allocated
```

`free(x);` gives back the dynamically allocated memory space pointed to by array to the operating system. This freeing of memory must be done when the dynamically allocated memory space is no longer needed by the program. Failure to do so is a "memory leak," which is very bad--it can lead to crashes, or worse: it can cause a program to use up all of the resources of a system, preventing itself from working and preventing other applications from working, thereby causing a computer to burn electricity while accomplishing nothing.

---

A more useful example: say you want to dynamically allocate an int:
```c
// note that i have to cast the return value of malloc to an int*
int* i = ( int* )malloc( sizeof(int) ); // and we need sizeof(int) bytes

i = 0; // we should initialize i

free(i); // and free it when we are done with it
```

What about allocating an array of ints?

```c
#define POWER_LEVEL 9001
// get memory, cast it to your type.
int* pLevels = (int*)malloc( sizeof(int) * POWER_LEVEL );
// pLevels now points to the first byte of the memory allocated

// initialize some things here:
for (int i = 0; i < POWER_LEVEL; ++i)
{
    pLevels[i] = i;  // use it like any other array!
}

// free it!
free(pLevels);
```

Examples:
## An array of ints - [malloc_example0.c](malloc_example0.c)
This demonstrates what we have learned above.

## Dynamically allocating 2D arrays

### A 2D array -  [malloc_example1A.c](malloc_example1A.c)

There are two ways to create dynamically allocated 2D arrays. The first is to simply use a 1D array. This approach requires a function that maps row index i and column index j to the appropriate index of the 1D array.

### An array of arrays - [malloc_example1.c](malloc_example1.c)

Another approach is to create a multi-level array. To do this, it is helpful and cleaner to use the C typedef instruction to define new types for a table row and for the table itself:

```c
typedef int* row_t;
typedef row_t* table_t;
```


The new type `row_t` is just a new name for the int* type; As we saw above, it can be used to refer to a dynamically allocated array of integers, i.e. a row of a 2-D array of integers.

The new type `table_t` is defined as `row_t`* and can thus be used to refer to a dynamically allocated array of `row_t` entries. In other words, a `table_t` variable will refer to an array of integer arrays, i.e. a 2-D array of integers.

Take heed of the way in which these are freed when compared to the earlier example using a 1D array.

### A 2D array of structs - [malloc_example2.c](malloc_example2.c)

Note that this, again, has additional complexity around the freeing of memory.
