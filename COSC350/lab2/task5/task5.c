#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(){
	umask(0);
	int fd1 = open("foo", O_RDONLY);
	int fd2 = open("clone1", O_CREAT | O_WRONLY, 0666);
	
	char c;
	while(read(fd1, &c, 1)==1){
		write(fd2, &c, 1);
	}
	close(fd1);
	close(fd2);
	return 0;
}
