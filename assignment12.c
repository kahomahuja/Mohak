#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc,char** arg){
	if(argc!=2){
		printf("Need to pass one file name with the command during execution\n");}
	int fd=open(arg[1],O_RDONLY);
	if(fd==-1){
		printf("ERROR OPENING THE FILE\n");
		return 0;}
	int flag=fcntl(fd,F_GETFL)& O_ACCMODE;
	if(flag==0){
		printf("FIle is opened in read only mode\n");}
	else if(flag==1){
		printf("File is opened in write only mode\n");}
	else if(flag==2){
		printf("File is opened in read-write mode.\n");}
	else{
		printf("File is opened in other mode\n");}
	close(fd);
	return 0;
}
