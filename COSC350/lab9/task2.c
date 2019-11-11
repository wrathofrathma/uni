/* Pipes across a fork/exec
 * A. Copy pipe3.c from BLP, page 535
 * B. Copy pipe4.c from BLP, pages 536.
 * C. Compile and run the program just to see what it does.
 * D. Modify pipe3.c as follows:
 *  a. Have the parent wait for the child.
 *  b. Close the file descriptor of the write end of the pipe on the parent's side
 *  c. Pass the write end of hte pipe to the child as a command-line argument.
 *  d. Close the file descriptor of the read end of the pipe on the child's side.
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
  int data_processed;
  int file_pipes[2];
  const char some_data[] = "123";
  char buffer[BUFSIZ+1];
  char buffer1[BUFSIZ+1];
  pid_t fork_result;

  memset(buffer,'\0',sizeof(buffer));

  if(pipe(file_pipes)==0){
    fork_result = fork();
    if(fork_result==-1){
      fprintf(stderr, "Fork Failure");
      exit(EXIT_FAILURE);
    }
    if(fork_result==0){
      sprintf(buffer, "%d", file_pipes[0]);
      sprintf(buffer1, "%d",file_pipes[1]);
      (void)execl("pipe4","pipe4", buffer, buffer1, (char*)0);
      exit(EXIT_FAILURE);
    }
    else{
      data_processed=write(file_pipes[1],some_data, strlen(some_data));
      printf("%d - wrote %d bytes\n", getpid(), data_processed);
      wait(NULL);
      close(file_pipes[1]);

    }  
  }
  exit(EXIT_SUCCESS);
}
