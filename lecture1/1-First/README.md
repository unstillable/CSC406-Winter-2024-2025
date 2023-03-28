# From source to executable

`hello.c` is compiled as follows:
```bash
$ gcc -o hello hello.c
```

The compilation system performs the translation of the source file hello.c to an executable hello which consists of a
sequence of low-level machine language instructions.

To obtain the "preprocessed" source program hello.i, do: `$ gcc -E hello.c`
To obtain the assembly program hello.s, do:

```bash
$ gcc -S hello.c
$ ls
hello  hello.c  hello.s
```

Use `bat` (or `more`) to view the file
```asm
$ Bat hello.s
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

To obtain the relocatable object file (binary file that is not yet executable because it is not linked to
helper library functions) hello.o, do:

```bash
$ gcc -c hello.c
$ ls
hello  hello.c  hello.o  hello.s
```

## A binary file cannot be viewed using text viewing tools...

```bash
$ more hello.o

******** hello.o: Not a text file ********
```

