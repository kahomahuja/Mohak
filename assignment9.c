#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>
int main(int argc,char*arg[]){
	if(argc!=2){
		printf("only single file-name needs to be passed along with the executable file command.\n");
		return 0;}
	struct stat buf;
	int result=stat(arg[1],&buf);
	if(result<0){
		printf("error in getting stat of file\n");
		return 0;}
	printf("Information about file:%s\n",arg[1]);
	printf("Inode:%ld \n",buf.st_ino);
	printf("Number of hard links:%ld \n",buf.st_nlink);
	printf("User-Id:%d \n",buf.st_uid);
	printf("Group-id:%d \n",buf.st_gid);
	printf("Size:%ld \n",buf.st_size);
	printf("Block-size:%ld\n",buf.st_blksize);
	printf("NUmber of blocks:%ld\n",buf.st_blocks);
	printf("Time of last access:%s",ctime(&buf.st_atime));

	printf("Time of last modification:%s",ctime(&buf.st_mtime));
	printf("Time of last change:%s",ctime(&buf.st_ctime));
	return 0;
}
