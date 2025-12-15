#include "get_next_line.h"

char	*read_into_stash(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes;
	char	*tmp;

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(stash), NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_strjoin("", buf);
		else
		{
			tmp = ft_strjoin(stash, buf);
			free(stash);
			stash = tmp;
		}
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*trim_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(ft_strlen(stash) - i);
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_into_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = trim_stash(stash);
	return (line);
}
