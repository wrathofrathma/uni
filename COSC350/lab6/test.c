#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

char *mygetenv(char *var){
	//For each string in environ
	//strip var_name from variable data
	//check if each index in var is = each index in var_name from environ. 
	//if they all match return pointer to this variable.
}

int main(int argc, char **argv){
	printf("%s",getenv("PATH"));
	return 0;
}
