
# Libft

This is the first project of the 42 coding school. `Libft` is a static library that reimplements some functions from the standard library and other utilities meant to be useful in the next projects.

The pecularity of this project are the syntax rules to abide policed by 42's "Norminette", such as a limit of 25 lines for each function, a space following instructions and functions, indentation and many more found in the official [norminette pdf](https://raw.githubusercontent.com/42School/norminette/master/pdf/en.norm.pdf). 


## Compilation

You can compile the library with make, the output is an archive named libft.a

```bash
  make          # compiles all the source files into an archive
  make clean    # removes object files
  make fclean   # removes object files and the archive
```
    
Since this is a static library, to be able to use the functions you must compile the library alongside the binaries i.e.

```c
#include "libft.h"

int main(void)
{
	char *s = ft_strdup("42");
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

```bash
gcc main.c libft.a -o main
```


## Functions implemented

| Category | Functions |
|----------|-----------|
| Character checks | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Conversion | `ft_atoi`,`ft_itoa` ,`ft_toupper`, `ft_tolower`|
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_memccpy`, `ft_calloc` |
| String manipulation | `ft_strlen`, `ft_strdup`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| Write to file | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
