/* Write code which opens two files (foo, foo1) and appends to a file (foo12) by using the lseek system call (created output file mode will be rwxrw---)*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
  //Set our umask so permissions work later
  umask(0000);

  //Open both files as read only and write to stderr if we encounter errors.
  int fd1 = open("foo", O_RDONLY);
  if(fd1==-1){
    char msg[] = "[ ERROR ] An error occured while opening foo as readable.\n";
    write(2, msg, sizeof(msg));
    exit(-1);
  }
  int fd2 = open("foo1", O_RDONLY);
  if(fd2==-1){
    char msg[] = "[ ERROR ] An error occured while opening foo1 as readable.\n";
    write(2, msg, sizeof(msg));
    close(fd1);
    exit(-1);
  }
  //Open & create foo12 as write only and write to stderr if we encounter errors.
  int out_fd=open("foo12", O_CREAT | O_WRONLY, 0760);
  if(out_fd==-1){
    char msg[] = "[ ERROR ] An error occured while opening & creating foo12.\n";
    write(2, msg, sizeof(msg));
    close(fd1);
    close(fd2);
    exit(-1);
  }
  //Seek to the end of the file of foo12.
  lseek(out_fd, 0, SEEK_END);

  char buffer[32];
  bool reading=true;
  // Read and write foo to foo12 32 bytes at a time.
  //If an error writing occurs, print it to stderr and exit.
  while(reading){
    int n_read = read(fd1, buffer, 32);
    if(n_read==0){
      reading=false;
      continue;
    }
    if(write(out_fd, buffer, n_read)!=n_read){
      char msg[] = "[ ERROR ] An error occured while writing foo to foo12\n";
      write(2, msg, sizeof(msg));
      close(fd1);
      close(fd2);
      close(out_fd);
      exit(-1);
    }
  }
  reading=true;
  while(reading){
    int n_read = read(fd2, buffer, 32);
    if(n_read==0){
      reading=false;
      continue;
    }
    if(write(out_fd, buffer,n_read)!=n_read){
      char msg[] = "[ ERROR ] An error occured while writing foo1 to foo12\n";
      write(2, msg, sizeof(msg));
      close(fd1);
      close(fd2);
      close(out_fd);
      exit(-1);
    }
  }
  close(fd1);
  close(fd2);
  close(out_fd);
  return 0;
}
