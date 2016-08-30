#include <stdlib.h>
#include <ctype.h>
#include "io.h"
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

void encrypt(char *s,int k)
{
	while(*s){
		if(!isalpha(*s))
			goto end;	
		*s=toupper(*s)+k%26;
		end:++s;
	}
}

void print_help()
{
	write_stderr("usage:caesar <opt><arg>\n\t-d decrypt  \
	\n\t-k size where size is the rotation\n");
}

int main(int argc,char *argv[])
{
	unsigned int key=0;

	if(argc==1){
		print_help();
		return 1;
	}
	for(int i=1;i<argc;i++){
		if(*argv[i]=='-'){
			switch(*(++argv[i])){
				case 'k':if(i+1<argc){ 
						if(!((key=atoi(argv[++i]))>=1&&key<=25)){return 1;}
					}else
						return 1;
						
					break;
				case 'd':key=key-key*2;
					break;
				default: write_stderr("unknown option\n");
			}
		}
	}

		char *buf=malloc(sizeof(char)*4096);
		ssize_t count=0;
		if(buf==NULL){
			perror("malloc buf");
			return errno;
		}

		while((count=read(0,buf,4096))>0){
			encrypt(buf,key);
			write(1,buf,count);
		}
		if(count==-1)
			perror("read");
		write_stdout("\n");

 return 0;
}
