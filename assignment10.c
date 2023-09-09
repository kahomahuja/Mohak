#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	printf("Enter a file-name:\n");
	char filename[100];
	scanf("%s",filename);
	printf("Filename:%s\n",filename);
	int fd=open(filename,O_RDWR);
	int count=0;
	char c;
	printf("Writting 10 bytes of data in file\n");
	while(count>=0){
		c=count+'0';
		write(fd,&c,1);
		count--;}
	printf("Skipping 10 characters in file\n");
	off_t seekResp=lseek(fd,10,SEEK_CUR);
	printf("Current position in file:%ld\n",seekResp);
	while(count<10){
	count++;
         c=count+'0';
  write(fd,&c,1);	 
	}

	close(fd);
	return 0;}
