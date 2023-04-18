# Command line arguments

Programs sometimes take command line input arguments:
```bash
$ ./cmdline0 Jack
Hello, Jack!
$ ./cmdline0 Natalie
Hello, Natalie!
$ ./cmdline0
Hello, World!
```
example: (cmdline0.c)[cmdline0.c]

If you want your C program to handle any command line input, you need to define function main() like this:
```
int main(int argc, char* argv[])
```

The argument argc will be assigned the number of (blank separated) command line arguments when the program is executed; this includes the name of the executable (./cmdline0 in the above examples).  The argument argv is an array of strings that will contain all the command line arguments. For example, in
```bash
$ ./cmdline0 Jack
Hello, Jack!
```

the `argc` is will be 2, `argv[0]` will be string "./cmdline0" and `argv[1]` will be "Jack".

The following example uses a program [cmdline1.c](cmdline1.c) that prints the values of argc and of every every string in array argv:
```
$ ./cmdline1 how many arguments?
4 arguments
 0: ./cmdline1
 1: how
 2: many
 3: arguments?
```

## Parsing arguments

We can get a bit of help parsing arguments by using the `getopt` function!
Function getopt()
Function getopt() is used to process Unix-like command line options of the type -x such as the -l option of the ls (list directory) instruction. Here is some sample usage of a program getopt_example.c that can take 4 command line options a, b, c, and d. Option a takes an integer argument, option b takes a string argument and options c and d take no argument (they are simply flags):
```
$ ./getopt_example                      
a = 0, b = (null), flagc = 0, flagd = 0     // all options receive default values
$ ./getopt_example -a 3
a = 3, b = (null), flagc = 0, flagd = 0     // option a is 3
$ ./getopt_example -a 3 -b hello!
a = 3, b = hello!, flagc = 0, flagd = 0     // a is 3 and b is string "hello!"
$ ./getopt_example -a 3 -b hello! -c
a = 3, b = hello!, flagc = 1, flagd = 0     // flag c is set as well
$ ./getopt_example -a 3 -b hello! -d
a = 3, b = hello!, flagc = 0, flagd = 1     // example with flag d instead
$ ./getopt_example -b hello! -d
a = 0, b = hello!, flagc = 0, flagd = 1     // using b and d options only
$ ./getopt_example -e
./getopt_example: invalid option -- 'e'     // an invalid option
ERROR!
```
[getopt_example.c](getopt_example.c)

The last argument of function getopt in the above program is "a:b:cd": that is the option string that contains the legitimate option characters. Any character followed by a colon (:) is an option that takes an argument.

By repeatedly calling getopt() in a while loop as shown above, we can retrieve the command line options one by one. Any option that takes an argument can access this argument through the global variable optarg defined in the getopt.c library.