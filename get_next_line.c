
#include "get_next_line.h"



char *get_next_line(int fd)
{
	char	*res;
	static int i;
	static int stop;

	if (fd < 0 || read(fd, NULL, 0) < 0  || BUFFER_SIZE < 1)
		return (NULL);
	if (!(res = malloc(sizeof(char))))
		return(NULL);
	i = -1;
	while (stop != -1)
	{
		if (!(res = ft_realloc(res, i + 2, i + 1)))
			return (NULL);
		stop = read(fd, &res[++i], (BUFFER_SIZE > 0));
		if((!stop) && (res[i - 1] == '\0' || !ft_isprint(res[i])))
			return(free(res), stop = - 1, NULL);
		if (res[i] == '\n' || (stop == 0))
			return (res[++i] = '\0', res);
    }
    return (free(res),NULL);
}

