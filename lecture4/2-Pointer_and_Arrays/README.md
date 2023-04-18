# C pointer arithmetic


## Pointers access memory
Pointers can be incremented:
```c
int y;
int *p = &y;
p = p + 5;    // Spooky unknown data access! 
```

Pointer p is incremented by $5 * 4 = 20$ bytes. This is because `p` is an **integer pointer** and what `p + 5` really means is the 5th integer after the one the address held in `p`.

Example: [pointers6.c](pointers6.c)


## C pointers and arrays

Anything you can do with arrays, you can do with pointers (faster!) 

More precisely:
* the name of the array is really a pointer to the beginning of the array
* array indexing is really pointer arithmetic

After executing this code fragment

```c
int a[10];
int *p;
p = a;

// element a[0] can be accessed as *p, or *a, or p[0]
a[0] == *p == *a == p[0]

// element a[1] can be accessed as *(p+1), or *(a+1), or p[1]
a[1] == *(p+1) == *(a+1) == p[1]

// element a[2] can be accessed as *(pa+2), or *(a+1), or p[2]
a[2] == *(p+2) == *(a+2) == p[2]

// etc.
```

The same is true if a (respectively, p) was an array of (respectively, a pointer to) chars, doubles, etc

__In fact, C compiles a[i] to *(a+i)__

**Example:** [pointers7.c](pointers7.c)


## Passing arrays as function arguments

When you pass an array as a function argument, in C, you have to remember that you are in a pass by value language.  This means that you are going to pass a copy of the address to the array (i.e., you are passing a pointer to the array)!

**Example:** [sort.c](sort.c)


## Multidimensional Arrays

C also supports multidimensional arrays: 
```c
long A[2][3] = {
  {2,0,4},
  {1,3,0}
};
```

Example: [array2d.c](array2D.c)
