/* Write a C main function that takes one command-line argument, the name of an input file. The input file contains exactly one integer spread out over a single line of up to 80 characters. For example, the integer 3579 is embedded in the line az3mqrm5t?7!z*&gqmzt9v.
 * Your program uses system calls to do the following:
 * a. Open and read the input file, accumulating the discovered digit characters into a character array(string).
 * b. convert the string to an integer. Do not use the atoi function
 * c. add 10 to the integer
 * d. convert the sum back to a string (using the function convIntToStr
 * e. Make a system call to write the string to standard output
int convIntToStr(char * str, int x)
{
	sprintf(str, "%d", x);
	return (strlen(str));
}
*/
#include <stdio.h>
//#include <stdlib.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#include <fcntl.h>

int convIntToStr(char *str, int x){
	sprintf(str,"%d", x);
	return (strlen(str));
}

int isdigit(char c){
	int zero='0';
	int diff=c-zero;
	if(diff<0 || diff >9){
		return 0;
	}
	return 1;
}

int ch_to_int(char c){
	if(isdigit(c)){
		int zero='0';
		int num=c-zero;
		return num;
	}
	return -1;
}

int convStrToInt(char *str){
	int num=0;
	int i=0;
	int buf=0;
	while(str[i]!='\0'){
		buf=ch_to_int(str[i]);
		num+=buf;
		num*=10;
		i++;
	}
	num/=10;
	return num;
}

int main(int argc, char **argv){
	if(argc!=2){
		printf("Invalid number of params. Please only pass a file name\n");
		return -1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd==-1){
		printf("An error occurred when opening the file for reading\n");
		return -1;
	}

	char c;
	char buffer[80];
	int index=0;

	//Read to the string.
	while(read(fd, &c, 1)==1){
		if(isdigit(c)){
			buffer[index]=c;
			index++;
		}
	}
	buffer[index]='\0';
	printf("Found integer string: %s\n", buffer);

	//Convert string to integer.
	int num=convStrToInt(buffer);
	printf("String as an integer: %d\n", num);
	//Add 10
	num+=10;
	printf("Number+10: %d\n", num);
	//Convert back to a string
	char buf2[80];
	convIntToStr(buf2, num);
	printf("Number converted back to a string: %s\n", buf2);
	printf("Writing to stdout using system call\n");
	write(1, buf2, strlen(buf2));
	close(fd);
	printf("\n");
	return 0;
}
