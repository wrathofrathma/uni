#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	if(argc!=3){
		printf("Invalid parameters, please pass input and output file names\n");
		return -1;
	}
	umask(0000);
	int in_fd=open(argv[1], O_RDONLY);
	if(in_fd==-1){
		printf("Error opening input file\n");
		return -1;
	}
	int out_fd = open(argv[2], O_CREAT | O_RDWR, 0666);
	if(out_fd==-1){
		printf("Error opening output file\n");
		return -1;
	}
	char buf;
	int offset = lseek(in_fd, -2, SEEK_END);
	while(pread(in_fd, &buf, 1,offset)==1){
		printf("writing: %c\n", buf);
		write(out_fd, &buf, 1);
		offset--;
	}
	close(in_fd);
	close(out_fd);
	return 0;
}
