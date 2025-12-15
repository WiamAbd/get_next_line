# include "get_next_line.h"
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

int back_to_line(char * buffer){
    size_t i=0;
    while(buffer[i]){
        if(buffer[i]=='\n')
            return i;
        i++;
    }
    return -1;
}
static char *ft_join(char *s1, char *s2)
{
    size_t len1 = s1 ? strlen(s1) : 0;
    size_t len2 = strlen(s2);
    char *out = malloc(len1 + len2 + 1);
    if (!out) return NULL;

    if (s1) 
    memcpy(out, s1, len1);
    memcpy(out + len1, s2, len2);
    out[len1 + len2] = '\0';

    free(s1);
    return out;
}
char *get_next_line(int fd){
    //* */ tests
    if( fd <0 || BUFFER_SIZE <= 0)
        return NULL;

    //** */ rest line allocation !! should join it with line in the end and refill it
    static char *rest_line;
    static size_t rl_size;
    //rest_line=malloc(sizeof(char)*(BUFFER_SIZE));
    
    //*** initialize line and buffer
    char * line;
    line=malloc(sizeof(char)*7);
    //line = rest_line;
    
    char * tmp_line;
    tmp_line=malloc(sizeof(char)*7);
    size_t size_line=0;
    size_t read_size;
    char *buffer;
    //if (buffer !=back_to_line(buffer)<0)
    buffer = malloc(sizeof(char)*(BUFFER_SIZE+1));
    // if(!buffer)
    //     return NULL;

    read_size = read(fd, buffer, BUFFER_SIZE);
    buffer[read_size]='\0';
    if (read_size <= 0){
            free(buffer);
            free(rest_line);
            return NULL;
    while(back_to_line(buffer)<0 && read_size>0){
        free(tmp_line);
        tmp_line = ft_join(line,size_line, buffer,read_size);
        size_line +=read_size;
        free(line);
        line = tmp_line;

        read_size = read(fd, buffer, BUFFER_SIZE);
        buffer[read_size]='\0';
        
    }
    if(back_to_line(buffer)>=0  && read_size>0 ) {
        free(tmp_line);
        tmp_line = ft_join(line,size_line, buffer,back_to_line(buffer)+1);
        size_line +=back_to_line(buffer)+1;
        free(line);
        line = tmp_line;
        
        } 


    free(tmp_line);
    tmp_line=ft_join(rest_line,rl_size,buffer+back_to_line(buffer),read_size-back_to_line(buffer));
    free(line);
    line = tmp_line;
    
    //create rest line
    rest_line=malloc(sizeof(char)*(BUFFER_SIZE+1));
    size_t i = back_to_line(buffer);
    while(i<read_size){
        rest_line[i-back_to_line(buffer)]=buffer[i];
        i++;
    }
    rest_line[i]='\0';

    free(buffer);
    free(tmp_line);
    return line;
}