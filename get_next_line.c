# include "get_next_line.h"
size_t not_back_to_line(char * buffer){
    size_t i=0;
    while(buffer[i]){
        if(buffer[i]=='\n')
            return i;
        i++;
    }
    return 0;
}
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
	return (d);
}

char *get_next_line(int fd){
    char buffer[BUFFER_SIZE + 1];
    static char rest[BUFFER_SIZE + 1];
    char *result;
    char *tmp;
    char *tmp2;
    size_t i =0;
    size_t size=0;
    tmp2 = malloc(sizeof(char)*(BUFFER_SIZE+1));
    if(!tmp2){
            return NULL;
        }
    while(i=)
    while(!not_back_to_line(buffer)){
        if (buffer==""){
            return NULL;
        }
        read(fd, buffer, BUFFER_SIZE);
        size+=BUFFER_SIZE;
        tmp=malloc(sizeof(char)*(size+1));
        if(!tmp){
            return NULL;
        }
        ft_memcpy(tmp,tmp2,size-BUFFER_SIZE);
        free(tmp2);
        ft_memcpy(tmp+size-BUFFER_SIZE,buffer,BUFFER_SIZE);
        tmp="\0";
        tmp=malloc(sizeof(char)*(size+1));
        if(!tmp){
            return NULL;
        }
        ft_memcpy(tmp2,tmp,size+1);
        free(tmp);
        
        }



        
        
        i=0;
        while(buffer[i]){

            i++;
        }
        result=malloc (sizeof(char)*(size+1));
        ft_memmove(result,tmp,size+1);


        result
          
    }
    if(buffer==""){
        return NULL;
    }
    size+=not_back_to_line(buffer);
    all= malloc(sizeof(char)*(size +1));
    i =0;
    while(buffer[i] && buffer[i]!='\n' ){
        rest[i]=buffer[i];
        size++;
        i++;
    }
    while(buffer[i] ){
        rest[i]=buffer[i];
        i++;
    }
    rest[j+1]='\0';

    return all;
    
    }

int main (){
    int fd = open("wiam.txt", O_RDONLY);
    printf("%s",get_next_line(fd));
}