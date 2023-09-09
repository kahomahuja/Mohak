#include <stdio.h>

int main(int argc, char** arg[], char** e){

	int i;
	for(int i=0; e[i]!=NULL;i++){
		printf("%s\n",e[i]);
	}
	return 0;
}
