#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
	int crt=creat("Mohak1",O_CREAT);
	crt=creat("Mohak2",O_CREAT);
	crt=creat("Mohak3",O_CREAT);
	crt=creat("Mohak4",O_CREAT);
	crt=creat("file5",O_CREAT);
	while(1);
	return 0;}

