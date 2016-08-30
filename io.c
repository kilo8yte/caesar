#include <unistd.h>
//#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

ssize_t write_stdout(const void *s)
{
	return write(1,s,strlen(s));
}

ssize_t write_stderr(const void *s)
{
	return write(2,s,strlen(s));
}


int redirect_stdout(const char *f)
{
	int fd;
	close(1);
	if((fd=open(f,O_RDWR|O_CREAT|O_TRUNC,0666))!=1){
		write_stderr("redirect_stdout failed\n");
		close(fd);
		return -1;
	}
 return fd;
}

int redirect_stdin(const char *f)
{
	int fd;
	close(0);
	if((fd=open(f,O_RDONLY|O_CREAT))!=0){
		write_stderr("redirect_stdin failed\n");
		close(fd);
		return -1;
	}
 return fd;
}
