#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
int main(){
	struct flock fp;
	struct flock fp1;
	int fd,fd1;
	fp.l_start=0;
	fp.l_len=0;
	fp.l_whence=SEEK_SET;
	fp.l_pid=getpid();
	fp.l_type=F_WRLCK;
	if((fd=open("ticket.txt",O_RDWR))==-1){
		perror("ERROR:");}
	printf("getting write lock:\n");
	sleep(2);
	int gotlock=fcntl(fd,F_SETLKW,&fp);
	if(gotlock==-1){
		printf("error in aquiring writeLock\n");
	}
	else{
		printf("write lock aquired");
	}
	printf("press any key to relaese writelock\n");
         getchar();
	 fp.l_type=F_UNLCK;
	 gotlock=fcntl(fd,F_SETLK,&fp);
	 printf("exiting from critical section and releasing write lock\n");
	 printf("before entering into critical sectionwith read lock\n");
	 fp.l_type=F_RDLCK;
	 gotlock=fcntl(fd,F_SETLKW,&fp);
	 if(gotlock==-1){
		 printf("error in aquiring the wright lock\n");
	 }
	 else{
		 printf("aquired succesfully\n");
	 }
	 printf("press any key to release read lock\n");
	 getchar();
	 fp.l_type=F_UNLCK;
	 gotlock=fcntl(fd,F_SETLKW,&fp);
	 printf("exiting from the critical section and read lock released\n");
	 close(fd);
}
