# C arrays and strings

Arrays store a set of "indexable" values of the same type. For an arrays with n entries, the valid index values are from 0 to n-1. 

[arrays.c](arrays.c)
```c
#include <stdio.h>

int main(){

  int i;

  int a[3];    // 12 bytes, split into 3 4-byte ints
  char b[5];   // 5 bytes, split into 5 1-byte chars
  double c[3]; // 24 bytes, split into 3 8-byte doubles

  printf("&a = %p\t&a[1] = %p\t&a[2] = %p\n\n", &a, &a[1], &a[2]);

  for (i = 0; i < 5; i++)
    printf("&b[%d] = %p\n", i, &b[i]);
  
  printf("\n");

  for (i = 0; i < 3; i++)
    printf("&c[%d] = %p\n", i, &c[i]);

  return 0;
}
```


## C String (c_str)
A C string is a special kind of array of characters: the string ends with character '\0', the NULL character which is not necessarily the last character of the array.

[str.c](str.c)
```c
#include <stdio.h>

int main(){

  char s[10] = "hello";
  int i = -1;

  do {
    i += 1;
    printf("%c\t%x\n", s[i], s[i]);
  } while (s[i] != '\0');

  return 0;
}
```


### Notes:
The null character '\0' contains 0 bits, so it can be replaced by integer 0
Rather than defining variable s to be an array of 6 or 10 (or ...) characters, it is traditional to define it simply as `char *s = "hello"`, which creates an array as follows:

```c
 char *s = [ 'h', 'e', 'l', 'l', 'o', '\0' ]
```

