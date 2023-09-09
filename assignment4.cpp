#include<sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include<sys/stat.h>

using namespace std;

int main(){
        int res = open("checkMOhak.txt", O_RDWR | O_CREAT);
        printf("%d",res);
       if(res==-1){
	       printf("Error Number:%d ",errno);
	       printf("\n");
			       perror("Program");}
}

