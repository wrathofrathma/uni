/* Write code to copy the content of any readable file (foo) to a file (clone2) with open files using a buffer with size 32bytes (created output file mode will be rwx-rwx---). */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

int main(){
  //Let's set our usermask so we can handle permissions.
  umask(0000);


  //Opening the files and check to see if we get valid file descriptors. If not, write to stderr, clean up, and exit.
  int foo_fd = open("foo", O_RDONLY);
  if(foo_fd==-1){
    char msg[] = "[ ERROR ] Unable to open file foo for reading.\n";
    write(2, msg, sizeof(msg));
    return -1;
  }
  int clone_fd = open("clone2", O_WRONLY | O_CREAT, 0770);
  if(clone_fd==-1){
    char msg[] = "[ ERROR ] Unable to open file clone2 for writing.\n";
    write(2, msg, sizeof(msg));
    close(foo_fd);
    return -1;
  }

  //Read 32 bytes at a time from foo and write to clone.
  char buffer[32];
  bool reading=true;
  while(reading){
    int n_read = read(foo_fd, buffer, 32);
    //If we read more than 0 bytes, then we still need to write.
    if(n_read > 0){
      write(clone_fd, buffer, n_read);
    }
    else
      reading=false;
  }
  //Cleanup our file descriptors
  close(foo_fd);
  close(clone_fd);
  return 0;
}
