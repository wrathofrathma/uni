/* Write your own getenv() function called mygetenv() which has the same syntax and symantics.
Write a simple c program to show your mygetenv()

*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *mygetenv(char *name){
//For each string in environ
	int i=0;
	int name_length=strlen(name);
	int var_length=0;
	for(i=0; environ[i]!='\0'; i++){
		//Find equals in environ.
		int j=0;
		while(environ[i][j]!='\0'){
			//If environ variable name != name, break and move to next.
			if(j>name_length)
				break;
			else if(name_length==j){
				//Check if we hit = sign in environ. If not, break.
				if(environ[i][j]=='='){
					return environ[i]+name_length+1;
				}
				else
					break;
			}
			else if(name[j]!=environ[i][j])
				break;
			else
				j++;
		}
	}
	return NULL;
}

int main(int argc, char **argv){
	if(argc!=2){
		printf("Please input a path name to search for as command line argument\n");
		return -1;
	}
	char *e = mygetenv(argv[1]);
	if(e!=NULL){
		printf("mygetenv(%s) returned: %s\n\n",argv[1],e);
	}
	else
		printf("mygetenv(%s) returned NULL\n", argv[1]);
	e = getenv(argv[1]);
	if(e!=NULL){
		printf("getenv(%s) returned: %s\n",argv[1],e);
	}
	else
		printf("getenv(%s) returned NULL\n", argv[1]);

	return 0;
}
