# The basics of a C program

- [`#include` Code from other files](#include-code-from-other-files)
- [Entry Point: `int main()`](#entry-point-int-main)
  - [Compare to Java and Python](#compare-to-java-and-python)
- [Variables](#variables)
  - [**Declaration**](#declaration)
  - [**Initialization**](#initialization)
- [Console I/O](#console-io)
  - [Output (printf)](#output-printf)
    - [String Literals](#string-literals)
    - [Format Strings](#format-strings)
    - [New Line (`'\n'`)](#new-line-n)
  - [Input (`scanf` and `&`)](#input-scanf-and-)
  - [References (`&`)](#references-)

---

Consider [demo1.c](demo1.c)

```c
/* demo1.c - demo program */

#include <stdlib.h> // scanf
#include <stdio.h>  // printf

int main()
{
  int x;
  int y=34;
    
  printf("Please enter an integer: ");
  scanf("%d", &x );  /* &x is the memory address of variable x*/
  printf("x: %d  y: %d\n", x, y );
    
  return 0;

}
```

---

## `#include` Code from other files

The `#include` line at the top is conceptually similar to an import in Java or Python but the behavior differs significantly. In C, the `#include` is a **pre-compilation directive** that instructs the compiler to replace the `#include` line with the text from the indicated file. This included file (e.g., stdlib.h, stdio.h) is called a header file and it contains references to library function executables that the program uses. 

---

## Entry Point: `int main()`

The main *function* is the **entry point** for the program. 

The main function can be prototyped to return other types, but void and int are the most common. For this course we will adhere to the most common practice which is to return an int. The usefulness of this returned value is however moot for our purposes since we do no script programming which might examine and use the value returned by main.

### Compare to Java and Python

Much like the Java entry point class method `public static void main()`, a C program must have exactly one main function (now that we are in C, we refer to methods as functions from now on). 
    
The Python equivalent to main is the module-level code (i.e., code that is not inside a function or class definition). In python, you may also have a main.py file, and files may check `if (__name__ == '__main__')`

---

## Variables 

### **Declaration**

Naming a variable of a specific type. 

### **Initialization**

Setting a variable's value in memory.

Variable *declarations* are syntactically similar to Java. However in C, the compiler makes no *initializations*.  Newly declared variables contain **garbage values.** We will discuss the data types in [Data Types](../3-Types/).

---
## Console I/O

Console I/O can be done via the many print, scan and get functions (see the `man` pages). 

### Output (printf)

Our first C program uses:
```c
    printf("Please enter an integer: ");
    ...
    printf("x: %d  y: %d\n", x, y );	
```
#### String Literals
In the first printf we supply a **string literal**. What you see is what you get. 

#### Format Strings
In the second printf call we pass in a **format string**. This is a string that contains placeholder characters (`%`). We also pass one argument for each placeholder character (the x and y variables). The format string is printed after replacing the placeholder (`%`) symbols.

The values of the arguments (x and y) will be printed exactly where the placeholders are. Each placeholder (`%`) is followed by a conversion instruction---`d` in our examples---that says how the value is to be printed. **Examples:**

* `%d` - signed decimal - base 10 (32 bits)
* `%f` - floating point numbers
* `%x` - hexadecimal - base 16
* ...and many others

#### New Line (`'\n'`)

At the end of the format there is an escape sequence \n which denotes a newline. **Always** include a newline at the end of your files. 

---

### Input (`scanf` and `&`)

To read data from the keyboard our first C program uses:

```c
    ...
    scanf("%d", &x );	
    ...
```

The first argument is, again, a format string. It is used to instruct the function scanf how to interpret what the user types. In this case it instructs scanf to interpret the user's input as an integer in decimal notation. The second argument contains the name of the variable where the input is to be stored (x). Note the ampersand character (`&`) before the x variable. This ampersand character is the `address-of operator`. This operator when placed before an variable produces the address of that variable, rather than the value of the variable. This address value is a positive memory address between 0 and however much memory you have in your computer. scanf needs the `address of x` not the **value** of `x` because scanf wants to know where to store the numeric conversion of the string you typed into the keyboard.
Recall that when we just want the value of x we just use the name x in a statement such as:
```c
	x = 15;     // assignment into the value of x
	// or
	y = x + 5;  // lookup the value of x
	// or
	printf("value of x: %d", x );  // lookup the value of x	
```

### References (`&`)

This is the first time we have ever been concerned with the address of where a variable is stored in memory. Java intentionally shields us from any such concerns. C does not. Thus it is important to understand the distinction between the **value** of a variable, and the **address** of a variable. They are not the same. If we want the address we must put the `&` operator immediately to the left of the variable name.