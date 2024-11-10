
#include "get_next_line_bonus.h"


char *get_next_line(int fd)
{
	char	*res;
	static int i;
	static int stop;
	//if(sizeof(res) > 1)
		//free(res);
	if (!(res = malloc(sizeof(char))))
		return(NULL);
	//if(!fd)
	//	return (free(res),NULL);
	//if(stop == 0)
	//	stop = 1;
	i = -1;
	if(!(BUFFER_SIZE > 0))
		return(NULL);
	while (stop != -1)
	{
		if (!(res = ft_realloc(res, i + 2, i + 1)))
			return (NULL);
			stop = read(fd, &res[++i], (BUFFER_SIZE > 0));
			if(!stop && (res[i - 1] == '\0'))
				return(free(res),NULL);
		if (res[i] == '\n' || stop == 0)
		{
			//if (stop == 0 )
				//stop = -1;
			//if (res[i] == '\0')
			//res = ft_realloc(res, i + 2, i + 1);
            	return (res[++i] = '\0', res);
		}
    }
    return (NULL);
}

