# Basic data types

The four basic data types are int, float, double, and char.

| Data Type      | Size (bits) | min       | max        |
| -------------- | ----------- | --------- | ---------- |
| char           | 8           | $-2^{7}$  | $2^{7}-1$  |
| unsigned char  | 8           | $0$       | $2^{8}$    |
| short          | 16          | $-2^{15}$ | $2^{15}-1$ |
| unsigned short | 16          | $0$       | $2^{16}$   |
| int            | 32          | $-2^{31}$ | $2^{31}-1$ |
| unsigned int   | 32          | $0$       | $2^{32}$   |
| long           | 64          | $-2^{63}$ | $2^{63-1}$ |
| unsigned long  | 64          | $0$       | $2^{64}$   |
| float          | 32          |           |            |
| double         | 64          |           |            |


An int is a 32 bit signed value having a range of about negative 2G to positive 2G (1G = 230). An unsigned int is a strictly positive 32 bit value ranging from 0 to 4G. C has floating point types float and double. It is common practice in C (as in Java) to just use the double type with its increased precision for floating point numbers to minimize accumulated rounding errors. The char type is an 8 bit signed quantity that stores the ascii code for a character. Thus a char is just an 8 bit int and has an unsigned version also. We will discuss data types some more later.


[data-types.c](./data-types.c)
```c

    printf( "%d %c\n", x, a );
    printf( "%3d %5c\n", x, a );
    printf( "%f %e\n", e, d );
    printf( "%.9f %.9e\n", e, d );
    printf( "%20.9f %20.9e\n", e, d );
```
conversion instructions other than d are used. Here are the conversions we will use:

| Conversion Specification | Output                                    |
| ------------------------ | ----------------------------------------- |
| `%c`                     | character                                 |
| `%s`                     | string of characters                      |
| `%d or %i`               | decimal integer                           |
| `%e`                     | floating point number in e-notation       |
| `%f`                     | floating point number in decimal notation |
| `%p`                     | pointer                                   |
| `%u`                     | unsigned decimal integer                  |
| `%o`                     | octal integer                             |
| `%x`                     | hexadecimal integer, using lower case     |
| `%X`                     | hexadecimal integer, using upper case     |
| `%%`                     | Prints a % sign                           |

A number right after the placeholder (%) specifies the width (i.e., the number of characters) that the value should occupy, with blank spaces used as fillers when necessary:
printf("%3d %5c\n",x,a);
printf("%20.9f %20.9e\n",e,d);
For float and double values, a precision can be specified:
printf("%.9f %.9e\n",e,d);
printf("%20.9f %20.9e\n",e,d);
The following is a list of some common escape sequences: 

| Escape Sequences | Meaning         |
| ---------------- | --------------- |
| \n               | New break       |
| \b               | Backspace       |
| \f               | Form feed       |
| \r               | Carriage return |
| \t               | Horizontal tab  |
| \\               | Prints a \      |
| \'               | prints a '      |
| \"               | prints a "      |


## Man pages (**RTFM**)
To learn more about printf, we use the man page

```bash
$ man -k printf
asprintf (3)         - print to allocated string
dprintf (3)          - formatted output conversion
dprintf (3p)         - print formatted output
fprintf (3)          - formatted output conversion
fprintf (3p)         - print formatted output
fwprintf (3)         - formatted wide-character output conversion
fwprintf (3p)        - print formatted wide-character output
printf (1)           - format and print data
printf (1p)          - write formatted output
printf (3)           - formatted output conversion
printf (3p)          - print formatted output
snprintf (3)         - formatted output conversion
snprintf (3p)        - print formatted output
sprintf (3)          - formatted output conversion
sprintf (3p)         - print formatted output
swprintf (3)         - formatted wide-character output conversion
swprintf (3p)        - print formatted wide-character output
vasprintf (3)        - print to allocated string
vdprintf (3)         - formatted output conversion
vfprintf (3p)        - format output of a stdarg argument list
vfprintf (3)         - formatted output conversion
vfwprintf (3)        - formatted wide-character output conversion
vfwprintf (3p)       - wide-character formatted output of a stdarg argument list
vprintf (3)          - formatted output conversion
vprintf (3p)         - format the output of a stdarg argument list
vsnprintf (3)        - formatted output conversion
vsnprintf (3p)       - format output of a stdarg argument list
vsprintf (3)         - formatted output conversion
vswprintf (3)        - formatted wide-character output conversion
vswprintf (3p)       - wide-character formatted output of a stdarg argument list
vwprintf (3)         - formatted wide-character output conversion
vwprintf (3p)        - wide-character formatted output of a stdarg argument list
wprintf (3)          - formatted wide-character output conversion
wprintf (3p)         - print formatted wide-character output
The printf C function is described in man 3:
```

### Man pages (3) 
```c
$ man 3 printf
PRINTF(3)                  Linux Programmer's Manual                 PRINTF(3)

NAME
       printf,   fprintf,  sprintf,  snprintf,  vprintf,  vfprintf,  vsprintf,
       vsnprintf - formatted output conversion

SYNOPSIS
       #include <stdio.h>

       int printf(const char *format, ...);
       int fprintf(FILE *stream, const char *format, ...);
       int sprintf(char *str, const char *format, ...);
       int snprintf(char *str, size_t size, const char *format, ...);

       #include <stdarg.h>

       int vprintf(const char *format, va_list ap);
       int vfprintf(FILE *stream, const char *format, va_list ap);
       int vsprintf(char *str, const char *format, va_list ap);
       int vsnprintf(char *str, size_t size, const char *format, va_list ap);

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       snprintf(), vsnprintf(): _BSD_SOURCE || _XOPEN_SOURCE >= 500 ||
       _ISOC99_SOURCE; or cc -std=c99
 Manual page printf(3) line 1
...
```

In C, the char type is really an integer type. We use the conversion instructions to illustrate this:
[ascii.c](./ascii.c)
