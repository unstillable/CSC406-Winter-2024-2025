# Compiling a C program and running it

To compile a single file C program in a file named hello.c use the gcc compiler.

```bash
$ cp /home/jstillwe/public/lecture1/hello.c .
$ gcc -o hello hello.c
```

The command gcc (**G**NU **C** **C**ompiler):
* compiles the program hello.c
* links it with any standard c library routines called (e.g. i/o routines)
* produces the executable file named hello.

The file hello is an executable and could run at the command line
`$ hello`

If the PATH environment variable includes the current directory (denoted `.`). The value of the PATH environment 
variable is a sequence of directories the shell will look in for executables. To view this sequence, do:

```bash
$ echo $PATH
/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/stu/.local/bin:/home/stu/bin
```

Note that the current directory (`.`) is not included. To execute hello, you will need to specify
where the executable hello is:

```bash
$ ./hello
hello, world
$ /home/stu/hello
hello, world
```

/home/stu/hello is the absolute pathname of file hello
./hello is the relative pathname of file hello, and it is relative to (current working) directory `${HOME}/lecture1`


To obtain the assembly program hello.s, do:
$ gcc -S hello.c
$ ls
hello  hello.c  hello.s

```asm
$ more hello.s
    .file    "hello.c"
    .text
    .section    .rodata
.LC0:
    .string    "hello, world"
    .text
    .globl    main
    .type    main, @function
main:
.LFB0:
    .cfi_startproc
    pushq    %rbp
    .cfi_def_cfa_offset 16
    .cfi_offset 6, -16
    movq    %rsp, %rbp
    .cfi_def_cfa_register 6
    movl    $.LC0, %edi
    call    puts
    movl    $0, %eax
    popq    %rbp
    .cfi_def_cfa 7, 8
    ret
    .cfi_endproc
.LFE0:
    .size    main, .-main
    .ident    "GCC: (GNU) 8.4.1 20200928 (Red Hat 8.4.1-1.0.1)"
    .section    .note.GNU-stack,"",@progbits
```
