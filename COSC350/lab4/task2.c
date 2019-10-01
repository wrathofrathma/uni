/* Write a C program which accept two file names as arguments: input file name and output file name. Your program copy one file to another file. Exit the program with an appropriate error message under the following condition: if input file is not avaialble*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUF_SIZE 32

int main(int argc, char **argv){
	if(argc!=3){
		printf("Please input an input and output file only\n");
		return -1;
	}
	int ifd = open(argv[1], O_RDONLY);
	if(ifd==-1){
		printf("An error occurred opening the input file\n");
		return -1;
	}
	umask(0);
	int ofd = open(argv[2], O_CREAT | O_WRONLY,0666);
	if(ofd==-1){
		printf("An error occurred opening the output file\n");
		close(ifd);
		return -1;
	}
	char buf[BUF_SIZE];
	int n_read=0;
	do {
		n_read = read(ifd, buf, BUF_SIZE);
		write(ofd, buf, n_read);
	} while(n_read>0);
	
	close(ifd);
	close(ofd);
	return 0;
}
