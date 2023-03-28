# Flow Control
- [`continue`](#continue)
- [`break`](#break)

---

Now that we know how to check conditions, we can use them to control loops! C supports two statements that modify the execution of a loop, and you usually trigger them in switch 

## `continue`

Skip the rest of the loop iteration, and jump to the next loop condition check.  **continue** from there 

```c
int x = 10;
do{
    if ( x != 2)
        continue;
    return x;  // always returns 2
} while( x > 0);
```

## `break`

Break out of the loop!  Skip the rest of the loop iteration and  and continue with 
statement that follows the loop body

```c
for (; x != 3; --x)
{
    if (x < 3 )
    {
        // this is a good example of bad code.
        break;
    }
}
```

[flow.c](flow.c)
