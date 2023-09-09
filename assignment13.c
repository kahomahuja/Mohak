#include<stdio.h>
#include<sys/select.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	fd_set fdset;
	fflush(stdout);
	FD_ZERO(&fdset);
	FD_SET(0,&fdset);
	struct timeval timeVal;
	timeVal.tv_sec=5;
	printf("Data to be written on STDIN\n");
	int value=select(1,&fdset,NULL,NULL,&timeVal);
	printf("Number of total fds after waiting period:%d\n",value);
	if(value==-1){
		perror("ERROR with select()\n");
	}
	else if(value){
		printf("Data available from STDIN\n");}
	else{
		printf("Defined wait is over,possible reason:No new connection were made or no data sent from existing connection/fd.\n");
	}
	return 0;}

