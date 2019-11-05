/* Interprocess communication using pipe
 * A parent processs asks two integers from command line and send to child by using pipe. The child process makes sure two inputs are integers.The child process calcuates sum of two integer and output on standard output. The child process continue until input from the parent are EOF.
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
void err(char *m){
  printf("%s\n",m);
  exit(1);
}

int main(){
  int fd[2];
  if(pipe(fd)<0)
    err("Error opening pipe");
  
  pid_t pid = fork();
  if(pid==0){
    //Close the output pipe from the child's side. 
    close(fd[1]);
    int a,b;
    char buf[256];
    bool running=true;
    while(read(fd[0],buf,256)>0){
      printf("[ Child ] Recieved string: %s\n", buf);
      //Convert to integers 
      if(sscanf(buf, "%d %d", &a,&b)!=2)
        err("[ Child ] Data passed wasn't two integers");
      printf("[ Child ] %d + %d = %d\n", a,b, a+b);
    }
    printf("[ Child ] Read 0 bytes and exited read loop\n");
    close(fd[0]);
  }
  else if(pid>0){
    //Close the input pipe from the parent's side.
    close(fd[0]);
    printf("[ Parent ] Input Options\nTwo integers on the same line separated by a space(i.e. 23 2) - Pipes to the child process.\nAnything else - Closes the pipes.\n");
    int a,b;
    bool running=true;
    char buf[256];
    while(running){
      memset(buf, '\0',256); // Need to set the string to null or else we'll get weird loops on single integer inputs. 
      read(0, buf, 256); 
      if(sscanf(buf,"%d %d", &a, &b)!=2){
        printf("[ Parent ] Closing the pipes.\n");
        //In the event that we don't read two objects, then we close our pipes. 
        close(fd[0]); //This should trigger the EOF in the child. Right?
        running=false;
      }
      else{
        //Stuffing it back into a string so we can send it via system calls.
        /*sprintf(buf, "%d %d", a,b);*/
        printf("[ Parent ] Sending to the child...\n");
        write(fd[1], buf, sizeof(buf));
      }
    }
  }
}
