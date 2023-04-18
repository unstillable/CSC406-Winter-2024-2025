# Structures

A structure is a grouping of several variables, possibly of different type, under a single name.
```c
struct employee {
    char *first;
    char *last;
    int age;
};

struct employee e = {"Sam", "Smith", 55};
```
**Example:** [struct.c](struct.c)

Note: The name of this type is `struct employee`. It is **NOT** named employee. 


## `struct employee` sucks to type

Fortunately, we can *type* (ha!) `struct employee` so that we don't have to include  `struct` every time we use it. We can use `typedef`, which defines a new (user-defined) type. 
```c
typedef struct employee {
    char *first;
    char *last;
    int age;
} some_type_name_for_struct_employee_t;

some_type_name_for_struct_employee_t f = {"Tam", "Tmith", 55};
```

Okay, so, the typedef name i picked was actually worse, but the point is that you can create `typedef`s.  

You can also use typedef when you have already created a struct.
```c
typedef struct employee employee_t;
employee_t g = {"Uam", "Umith", 55};
```

**Example:** [struct2.c](struct2.c)

## Structures and pointers

If e is defined as a pointer to an employee structure
```c
employee_t* e_p = &f; // That's the middle one from above
```

then the pointer must be dereferenced in order for the structure content to be accessed:
```c
(*e_p).first = "Tam";
(*e_p).last = "Tmith";
(*e_p).age = 55;

printf("%s %s, age %d\n", (*eptr).first, (*eptr).last, (*eptr).age);
```

## I don't want to type open parentheses asterisk variable_name close parentheses
An alternative notation is typically used:
```c
// alternative notation                                                      
e_p->first = "Sam";
e_p->last = "Smith";
e_p->age = 55;

printf("%s %s, age %d\n", eptr->first, eptr->last, eptr->age);
```

[struct3.c](struct3.c)
Note: the call malloc(12) allocates 12 bytes and returns the address of the first byte (similar to new() in C++ and Java)
