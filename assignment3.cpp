#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(){
        int fd = creat("myfile2.txt", O_RDWR);

        printf("file descriptor:%d\n",fd);
        if(fd==-1){
                printf("Error number:%d\n ",errno);
                perror("Program");
        }
}

