#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
    int fd = 0;
    FILE *fptr;

    if (argc > 2)
    {
        printf("Usage: %s [filename]\nRun without arguments to read from stdin", argv[0]);
        return 1;
    }
    if (argc == 2)
    {
        fptr = fopen(argv[1], "r");
        if (fptr == NULL)
        {
            perror("Error opening file");
            return 1;
        }
        fd = fileno(fptr);
    }
    else
    {
        printf("Type some lines (Ctrl+D to stop):\n");
    }
    i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line[%d]:%s", i, line);
		free(line);
		i++;
	}
	printf("End of input.\n");
    if (argc == 2)
	    fclose(fptr);
	return (0);
}