# File Input/Output and parsing strings

Suppose you have a file named `test.txt`.  Now suppose that you wanted to open it in a c program. Continue supposing that you want to read data from that file. I'm sure you have your reasons, but suppose you keep them secret. 

## Supposing you want to open the file

First, you will need a file handle:

```c
// the standard i/o header is required to do standard i/o stuff. 
#include <stdio.h>  

FILE* fp;
```

Congratulations! You are now ready to open a file.  Go ahead an try opening it like this: 

```c
fp = fopen("test.txt", "r");  // "r" is for read
```

It is always a good idea to make sure you opened the file: 
```c
if (fp == NULL)
{
    // well, shit.
    exit(1);
}
```

## Supposing you want to read from the file

Don't stop supposing now! It's time to suppose that you successfully opened the file and now you are moving on to the reading of data. You can read your data using the function `fgets()`.
```c
char buf[1000];  // need somewhere to put that data!

fgets(buf, 1000, fp);  // read the lesser of one line or 999 bytes
```

`fgets` will copy one byte at a time from the file into `buf`. When it finds a new line or end of file, it will write a `'\0'` into the buffer and stop. 

If it reads `999` non-EOF/'\n' characters (n - 1, where n is the second argument) it will stop and write a `'\0'` to the last character of the buffer. The `FILE` will remember where it is, so the next time you call `fgets` on it, it will continue from where it left off. 


The following is a complete program that opens file test.txt, reads it line by line, prints each line to standard output, and then closes the file:
[fileIO_example1.c](fileIO_example1.c)

When executed on file test.txt, it will show on the screen the content of file test.txt:
$ ./fileIO_example1
```
a 100,:,11
 b 200,:,22
c 300,:,33
 d 400,:,44
e 500,:,55
```

## Parsing input strings:

Suppose now that you want to parse the lines in the above test.txt file that start with a blank space in order to extract the first character and the two integers. For example, you would like to extract b, 200 and 22 from line
```
 b 200,:,22
````
and store them, respectively, in variables, c, a, and b defined as:
```c
  char c;
  unsigned int a;
  int b;
```

The function sscanf() can be used to do this. It takes as input: the character array buf that contains the line, a format string, and addresses of variables c, a, and b:
```c
sscanf(buf, " %c %u,:,%d", &c, &a, &b);
```

The format string describes the format of the string stored in buf and the placeholders %c, %u, and %u indicate the places where the values to be extracted into c, a, and b are.

[fileIO_example2.c](fileIO_example2.c)


## extras:

There are also some examples in this directory that can count different things about characters in files, try them out!

* [count.c](count.c)
* [count2.c](count2.c)
