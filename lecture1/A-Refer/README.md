# C pointers as function arguments

In C arguments to functions are passed by value.

* [pointers2.c](./pointers2.c)

## The consequence of pass by value

So, does the below function swap work correctly?
```c
void swap(int x, int y)
{
  int temp;

  temp = x;
  x = y;
  y = temp;
}

int main()
{
  int a = 0;
  int b = -123;
  swap(a, b);
  return 0;
}
```

* [pointers3.c](./pointers3.c)

To alter the value of a variable (e.g., `val` in example pointers2 and `a` and `b` in example pointers3) in the calling function (i.e., function main), the calling function must pass a pointer to the variable.

* [pointers4.c](./pointers4.c)

## Passing pointers by value

The correct way to swap in C:

* [pointers5.c](./pointers5.c)

