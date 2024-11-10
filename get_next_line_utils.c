#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	if (!dest && !src)
		return (dest);
	psrc = (char *)src;
	pdest = (char *)dest;
	while (n > 0)
	{
		*pdest++ = *psrc++;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*pdest;
	const char	*psrc;

	pdest = dest;
	psrc = src;
	if (dest == src)
		return (dest);
	if (dest < src)
	{
		while (len--)
			*pdest++ = *psrc++;
	}
	else
	{
		pdest += len - 1;
		psrc += len - 1;
		while (len--)
			*pdest-- = *psrc--;
	}
	return (dest);
}

void	*ft_realloc(void* ptr, size_t new_size, size_t old_size) 
{
    size_t size_to_cpy;
	void* new_ptr;
    // Se o novo tamanho é zero, libera o ponteiro e retorna NULL
    if (new_size == 0)
	{
        free(ptr);
        return NULL;
    }
    // Se o ponteiro é NULL, age como malloc
    if (!ptr)
        return malloc(new_size);
    // Aloca um novo bloco de memória
    new_ptr = malloc(new_size);
    if (!new_ptr)// Se falhar, retorna NULL (não altera o ptr original)
        return NULL;
    // Copia o conteúdo do bloco antigo para o novo bloco
    if (old_size < new_size)
        size_to_cpy = old_size;
    else 
        size_to_cpy = new_size;        
    ft_memmove(new_ptr, ptr, size_to_cpy);
    // Libera o bloco antigo
    free(ptr);
    return new_ptr;
}


int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}
