# C pointers
- [Things in memory](#things-in-memory)
- [Properties of variables](#properties-of-variables)
- [Dereferencing pointer variables](#dereferencing-pointer-variables)



We already saw that the `&` operator is used to obtain the **memory-address** of a variable:
```c 
scanf("%d", &x );
```

## Things in memory

Since a C programmer may need to store a variable's address for later use, C provides a data type called the **pointer type**. The pointer type allows us to declare variables **that are meant to hold the address of some other variable**. So, a pointer is a variable that contains the address of another variable.

Declaring a pointer variable is done as follows:
```c
	int* pi   /* creates a 64 bit variable whose data type is pointer to int */
	int i;    /* an int var */
	pi = &i;  /* pi now holds i's address - i.e it points to i */
```

[pointers.c](./pointers.c)

## Properties of variables

Every variable in C has 2 properties:
* it's value (the contents of the variable)
* it's address (the memory address WHERE that value is stored)

A pointer variable is itself a variable and its value can change. A pointer can hold only one of 3 values:
* the NULL value ( value ZERO, indicates not pointing to any variable)
* the memory address of any variable of it's point type
* garbage
  
Pointer variables are NOT the data type of the variable they point to. The data type of `pi` (above) is *pointer* to int--**THAT IS NOT INT**. The name of the pointer variable is `pi` NOT `*pi`.

You can declare a pointer to ANY data type.
```c
char *pc;   /* pc is type: pointer to char */
float *pf;  /* pf is type: pointer to float */
double *pd; /* pd is type: pointer to double */

typedef struct
	double cost;
	int age;
} student_type;

student_type *ps;          /* ps can store the address of any student_type variable */

student_type one_student;
ps = &one_student;	   /* ps has the address where one_student is stored in memory */
```

## Dereferencing pointer variables

Let's go back to our int example:
```c
int *pi;  /* variable of type pointer to int  */
int i;    /* plain old int var */
pi = &i;  /* pi now contains address of var i */
```

We can use pointer variable pi to manipulate the contents of the int variable i. To do so we must dereference pi as follows:
```c
*pi = 15; /* i now contains 15. */
printf(" value pointed to by pi is: %d\n" *pi ); /* deref's pi and prints 15 */
```

The expression `*pi` can be thought of as "the value at the address stored in pi."

Using pi with the * in front of it is called **dereferencing** the pointer variable.

In summary, when pi is defined as:
```c
int *pi;
```
1. pi is a pointer (to an integer value)
1. *pi is an integer
