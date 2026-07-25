
# Get Next Line

This 42 school project is part of the second "ring" of the common core. Gnl for short, consist in a function meant to replicate the [getline](https://man7.org/linux/man-pages/man3/getline.3.html) way to retrieve a line (from the start to '\n') from any file descriptor. 

```c
    char *get_next_line(int fd);
```

The function takes a file descriptor as input and 
[reads](https://man7.org/linux/man-pages/man2/read.2.html) from it until it 
encounters a newline (`'\n'`) or reaches the end of the file.  It returns a 
pointer to the first character of a newly allocated string and freeable string containing the line (including `'\n'` if present), or `NULL` if there is nothing left to read 
or an error occurs. Calling the 
function again and again will return each subsequent line in turn. Useless to say this project requires to be compliant to the norm ([norminette pdf](https://raw.githubusercontent.com/42School/norminette/master/pdf/en.norm.pdf))
## Usage/Examples

To use Get Next Line you have to compile the source code

```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c 
```
the `-D BUFFER_SIZE`, tells the preprocessor the value of BUFFER_SIZE before compiling, defaulted at 42 it's the size of the buffer used by the function for each read syscall, less size means more calls to read while greater size means more memory allocated. Important to note that the BUFFER_SIZE accept any input, using a negative number like -2 will result in this on my current machine

```bash
    get_next_line.c:43:23: error: ‘read’ specified size 18446744073709551614 exceeds maximum object size 9223372036854775807 [-Werror=stringop-overflow=]
   43 |                 ret = read(fd, str, BUFFER_SIZE);
      |                       ^~~~~~~~~~~~~~~~~~~~~~~~~
```

Similarly, since `<stdbool.h>` defines `false` as the macro `0`, compiling 
with `-D BUFFER_SIZE=false` is equivalent to `-D BUFFER_SIZE=0` — the 
preprocessor just substitutes the already defined value, printing the value of the macro results:


```bash
    root@root:~/Projects/42/get_next_line$ gcc -Wall -Wextra -Werror -D BUFFER_SIZE=false get_next_line.c get_next_line_utils.c main.c -o main
    root@root:~/Projects/42/get_next_line$ ./main 
    BUFFER_SIZE: 0
    End of input.
```

## Tests

I included a simple main file to test the function. Running the test without 
parameters lets you write to the standard input; pressing enter after each line 
will make the program output the line it read, to demonstrate it is
correct. Passing a path to a file will redirect the program to read 
from that file, outputting its content to the standard output.

```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c -o gnl_test
```

**Reading from stdin:**
```bash
    root@root:~/Projects/42/get_next_line$ ./gnl_test
    Type some lines (Ctrl+D to stop):
    hello
    Line[1]:hello
    End of input.
    root@root:~/Projects/42/get_next_line$ 
```

**Reading from a file:**
```bash
    root@root:~/Projects/42/get_next_line$ ./gnl_test main.c | head -5
    Line[1]:#include "get_next_line.h"
    Line[2]:#include <stdio.h>
    Line[3]:
    Line[4]:int     main(int argc, char **argv)
    Line[5]:{
    root@root:~/Projects/42/get_next_line$ 
```

