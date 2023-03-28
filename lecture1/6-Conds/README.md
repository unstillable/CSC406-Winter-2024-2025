# Conditionals

## `if (predicate)`

When the predicate is "true" execute the block of code it surrounds. In C, there are no `bool`s, so this is the rule:

`0` == false

anything else is true. 

## `else`
When the first condition is false do this block. you can have an if in here, which looks like this: 
```c
if (thing)
{

}
else if (other_thing)
{

}
```

[blocks.c](./blocks.c)

The usual if-else statement is the conditional statement in C.

Note that the conditional expression must be in parentheses.

## boolean logical operators
Compound conditional expressions are created using || (or), && (and), and ! (not).
[terminal.c](./terminal.c)

| operator | English term |
| -------- | ------------ |
| `\|\|`   | or           |
| `&&`     | and          |
| `!`      | not          |


## Truth Tables

| `x` | `y` | <!--looked weird--> | `x \|\| y` | `x && y` | `!x` |
| --- | --- | ------------------- | ---------- | -------- | ---- |
| T   | T   | <!--without this--> | T          | T        | F    |
| T   | F   | <!--because of  --> | T          | F        | F    |
| F   | T   | <!--formatting  --> | T          | F        | T    |
| F   | F   |                     | F          | F        | T    |
