/* Rewrite task#5 by using pread system call instead of using lseek system call */

/* Write c code which opens a file (foo) as an input and write into a file by using the lseek system call (foorev) as a reverse order (Created output file mode will be rwxrw---) */

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  ///Set the umask so we can handle permissions correctly.
  umask(0000);

  //Open both files. Check file descriptors for errors. Log any errors into stderr and exit.
  int foo_fd = open("foo", O_RDONLY);
  if(foo_fd==-1){
    char msg[] = "[ ERROR ] An error occurred when opening the file foo.";
    write(2, msg, sizeof(msg));
    exit(-1);
  }
  int rev_fd = open("foorev", O_CREAT | O_WRONLY, 0760);
  if(rev_fd==-1){
    char msg[] = "[ ERROR ] An error occurred when opening the file foorev.";
    write(2, msg, sizeof(msg));
    close(foo_fd);
    exit(-1);
  }

  //Seeking to the end of the file.
  int pos=lseek(foo_fd, -1, SEEK_END);
  char buffer;
  while(pread(foo_fd, &buffer, 1, pos)==1 && pos>=0){
    write(rev_fd, &buffer, 1);
    pos--;
  }

  close(foo_fd);
  close(rev_fd);
  return 0;
}
