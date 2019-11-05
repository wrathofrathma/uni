/* Interprocess communication using popen() and pclose()
 * popen() create a child and pipe. A parent process asks two arguments from commandline: a shell command and a file name. And thensend to child by using popen. Child process will implement the command with file as an input then sent to parent. Parent simply display output from the child on standard output.
 * ex) 
 * ./task4 cat Task4.c
 * ./task4 sort Task4.c
 * ./Task4 cat Task4.c | grep main
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

void err(char *m){
  printf("[ ERROR ] %s\n", m);
  exit(1);
}
int main(int argc, char **argv){
  if(argc!=3)
    err("Please use syntax ./task4 command filename");
  //Not going to check if the command exists. That'd involve use running through the PATH environmental variable and checking for the command in each. 
  //Let's at least check if our input file exist.
  int fd = open(argv[2], O_RDONLY);
  if(fd==-1)
    err("Unable to open input file");
  //Open the pipe
  FILE* p = popen("cat", "w");
  //Check if there are any problems
  if(p==NULL)
    err("Pipe opened to null?");

  char buf[256];
  int n_read=read(fd,buf,256);
  while(n_read>0){
    //Writing to the pipe. 
    //fwrite writes to a file with...
    // arg1 - input 
    // arg2 - size of each element
    // arg3 - number of elements to write
    // arg4 - file to write to.
    fwrite(buf, sizeof(char), n_read, p);
    memset(buf, '\0',256);
    n_read = read(fd,buf,256);
  }
  pclose(p);
}
