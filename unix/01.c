/*************************************************************************
	> File Name: 01.c
	> Author: dong xu
	> Mail: gwmxyd@163.com 
	> Created Time: 2016年10月31日 星期一 10时56分30秒
 ************************************************************************/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUFFSIZE 1024

int main(int argc,char **argv[])
{
	int read_fd,write_fd;
	int bytes_read,bytes_write;
	char *buffer;
	char *ptr;


	if(argc != 3)
	{
		fprintf(stderr,"Usage:%s form file to file \n\a",argv[0]);
		exit(1);
	}

	buffer = (char *)malloc(BUFFSIZE);
	if(buffer == NULL)
	{
		fprintf(stderr,"Can't allocate buffer memory.\n\a");
		exit(2);
	}

	if((read_fd = open(argv[1],O_RDONLY)) == -1)
	{
		fprintf(stderr,"open file %s error:%s.\n\a",argv[1],strerror(errno));
		exit(3);
	}

	if((write_fd = open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR)) == -1)
	{
		fprintf(stderr,"Open file %s Error:%s.\n\a",argv[2],strerror(errno));
		exit(4);
	}

	while(bytes_read = read(read_fd,buffer,BUFFSIZE))
	{
		if(bytes_read == -1 && errno != EINTR)
			break;
		else if(bytes_read > 0)
		{
			ptr = buffer;
			while(bytes_write = write(write_fd,ptr,bytes_read))
			{
				if(bytes_write == -1 && errno != EINTR)
					break;
				else if(bytes_write == bytes_read)
					break;
				else if(bytes_write > 0)
				{
					ptr += bytes_write;
					bytes_read -= bytes_write;
				}
			}
			if(bytes_write == -1)
				break;
		}
	}

	close(read_fd);
	close(write_fd);

	exit(0);
}

