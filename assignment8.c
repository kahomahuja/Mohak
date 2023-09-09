#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
char buf;
int fd_read=open(argv[1],O_RDONLY);
if(fd_read==-1){
	printf("NOOOOOOOO");
	return 0;
}

	int readthis=read(fd_read,&buf,1);
	int count=1;
while(1){
	readthis=read(fd_read,&buf,1);
	printf("%c",buf);
	if(buf=='\n'){
		printf("line no %d\n",count);
             count++;
	}
	if(readthis==0){
		break;}}

int close_fd_read=close(fd_read);
if(close_fd_read==-1){
	printf("NOOO its an error");}
return 0;}

