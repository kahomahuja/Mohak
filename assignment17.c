#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
struct {
	int ticketno;}TICKET;
int main(){
	struct TICKET ;
	TICKET.ticketno=0;
	struct flock lock;
	int fd=open("ticket.txt",O_RDWR|O_CREAT,0777);
	if(fd==-1){
		printf("NOOOOOO");
	}
	else{
	read(fd,&TICKET,sizeof(TICKET));
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before Critical Section\n");
	fcntl(fd,F_SETLKW,&lock);
	printf("ticket no=%d\n",TICKET.ticketno+1);
	TICKET.ticketno++;
	lseek(fd,0L,SEEK_SET);
	   int buffer =TICKET.ticketno;
        write(fd,&buffer,sizeof(buffer));
	printf("we are inside critical section yessssssssssssss hurrray\n");
	printf("enter for unlock guys\n");
	getchar();
	
	lock.l_type=F_UNLCK;
	printf("unlocked\n");
	fcntl(fd,F_SETLK,&lock);
	printf("done\n");}
	return 0;}
