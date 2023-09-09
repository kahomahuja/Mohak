#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[]){
	  if(argc!=3){
		  printf("you are bad");}
	    printf("%d",argc);
	    printf("%s",argv[0]);
	    int fd_read=open(argv[1],O_RDONLY);
	   // int fd_write=open(argv[2],O_WRONLY);// we have to add ocreate as if pathname donsent exist
	   int fd_write=open(argv[2],O_WRONLY|O_CREAT,0744);//we add bitwise or as they are macros and stored in form of bits
	  if(fd_read==-1||fd_write==-1){//to handle error
		  printf("no use");}
	  char buf;
	int char_writen=write(fd_write,&buf,1);
	 int char_read=read(fd_read,&buf,1);

	  while(1){

	        buf;//as it has to read byte by byte therefore make it 1 byte
                char_read=read(fd_read,&buf,1);
	       if(char_read==0){//read returns 0 if it didnt read anything else returns 1;
		       break;}
	        char_writen=write(fd_write,&buf,1);
	  }
	  int fd_read_close=close(fd_read);
	  int fd_write_close=close(fd_write);
	  if(fd_read_close==-1||fd_write_close==-1){
		  printf("error");}
	    return 0;}
