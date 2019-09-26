/* Write code to copy a content of any readable file (foo) to a file (clone) without opening the input file (use standard input and output (file descriptor 0 and 1) with input output redirection)
This uses redirection of the terminal to standard input.
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char **argv){
  //Set our mask so we can do permissions properly.
  umask(0000);
  //First let's open our output file and create it. If there are errors opening, write to stderr and exit.
  int clone_fd = open("clone", O_CREAT | O_WRONLY, 0666);
  if(clone_fd==-1){
    char msg[] = "[ ERROR ] Unable to open clone file for writing.\n";
    write(2, msg, sizeof(msg));
    return -1;
  }

  //Loop through standard input 32bytes at a time, writing to our output file.
  char buffer[32];
  bool reading=true;
  while(reading){
    //Read in 32 bytes from standard in and track the number actually read.
    int n_read=read(0, buffer,32);
    //If we read more than 0, then we haven't finished. So we write the number of bytes we read.
    if(n_read>0){
      write(clone_fd, buffer, n_read);
    }
    else
      reading=false;
  }
  //Cleanup file descriptor
  close(clone_fd);
  return 0;
}
