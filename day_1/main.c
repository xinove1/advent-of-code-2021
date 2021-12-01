#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>


int	main()
{
	char	*line;
	int		file;
	int		count;
	int		previous;
	int		current;

	file = open("./input.txt", O_RDONLY);
	line = get_next_line(file);
	current = atoi(line);
	free(line);
	line = get_next_line(file);
	count = 0;
	previous = 0;
	while(line)
	{
		current = atoi(line);
		if (current > previous)
			count++;
		previous = current;
		free(line);
		line = get_next_line(file);
	}
	printf("Count: %d \n", count);
	close(file);
}
