/* Write code to copy the content of any readable file (foo) to a file (clone1) with open files. (Created output file mode will be rw-rw-rw). Read byte by byte.
*/

#include <fcntl.h>  //open(), close()
//Umask includes
#include <sys/types.h>
#include <sys/stat.h>
int main(){
  //set our umask
  umask(0000);
  //Open files & check for errors(-1 as a file descriptor)
  int foo_fd = open("foo", O_RDONLY);
  if(foo_fd==-1){
    char msg[] = "[ ERROR ] Unable to open file \"foo\"\n";
    write(2, msg, sizeof(msg));
    return -1;
  }

  int clone_fd = open("clone1", O_WRONLY|O_CREAT, 0666);
  if(clone_fd==-1){
    char msg[] = "[ ERROR ] Unable to open file \"clone1\"\n";
    write(2, msg, sizeof(msg));
    return -1;
  }

  //Read 1 byte at a time of foo and write 1 byte at a time to clone1
  char c;
  while(read(foo_fd, &c, 1)==1){
    if(write(clone_fd, &c, 1)!=1){
      char msg[] = "[ ERROR ] Unable to write byte to clone1\n";
      close(foo_fd);
      close(clone_fd);
      return -1;
    }
  }
  //Close our open file descriptors
  close(foo_fd);
  close(clone_fd);
  return 0;
}
