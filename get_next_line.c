# include "get_next_line.h"
// if char contains back to line it gives its index otherwise it returns -1
size_t not_back_to_line(char * buffer){
    size_t i=0;
    while(buffer[i]){
        if(buffer[i]=='\n')
            return i;
        i++;
    }
    return -1;
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
void * ft_join (char * line,size_t size_line, char *buffer,size_t read_size)
{
    char * new_line;   
    new_line = malloc (sizeof(char)*(read_size+size_line+1)) ;
    size_t i=0;
    while(i< size_line){
        new_line[i]=line[i];
        i++;
    }
    while(i< read_size + size_line){
        new_line[i]=buffer[i-size_line];
        i++;
    }
    new_line[i]='\0';
    free(line);
    return new_line;

}
char *get_next_line(int fd){
    if( fd == NULL || BUFFER_SIZE <= 0)
        return NULL;
    static char * line;
    size_t size_line=0;
    size_t read_size;
    char *buffer;
    buffer = malloc(sizeof(char)*(BUFFER_SIZE+1));
    if(!buffer){
            return NULL;
        }
    while(!not_back_to_line(buffer)){
        read_size = read(fd, buffer, BUFFER_SIZE);
        size_line =+read_size;
        if (size_line <= 0)
            return NULL;
        line = ft_join(line,size_line, buffer,read_size);
        

    }
    

}










char *get_next_line(int fd){
    char buffer[BUFFER_SIZE + 1];
    static char rest[BUFFER_SIZE + 1];
    fill_with_0(rest,BUFFER_SIZE+1);
    char *result;
    char *tmp;
    char *tmp2;
    size_t bytes;
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