
# Ft_printf

This 42 School project is part of the second "ring" of the Common Core. The goal is to recreate the standard C library function [printf](https://man7.org/linux/man-pages/man3/printf.3.html) following the Norminette([ Norm pdf ](https://raw.githubusercontent.com/42School/norminette/master/pdf/en.norm.pdf)) and ensuring the program is free of memory leaks.

Unlike the numerous flags the original function supports, this are the mandatory flags to replicate (c,u,d,i,s,x,X,%,p).

| Flag | Type |
|----------|-----------|
| c | characters |
| d, i  | signed integer |
| u | unsigned integer|
| p | print pointer address|
| s| string |
| x, X | lowercase and uppercase hexadecimal|
| % | to print the literal percent sign|

# Function Prototype

```c
    int ft_printf(const char *, ...);
```

this function uses variadic arguments via <[stdarg](https://man7.org/linux/man-pages/man3/stdarg.3.html)>, allowing it to accept a variable number of arguments. It returns the total number of characters written to the standard output, matching the behavior of the standard printf.



## Usage/Examples

The project has a Makefile which builds into a static library.

```bash
    make         #  compiles all sources into libftprintf.a
    make clean   #  removes objects
    make fclean  #  calls rule clean and removes libftprintf.a
    make test    #  compiles a mini program to test ft_printf against the original printf
```


## Running Tests

As mentioned above, once compiled you can run the test program and compare the outputs to the standard printf:

```bash
    make test
    ./test
```

To check for memory leaks, run the test program with Valgrind:

```bash
    valgrind --leak-check=full ./test
```
