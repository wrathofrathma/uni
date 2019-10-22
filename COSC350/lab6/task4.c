/*
This task forks a child process and uses exec to replace its process image with another image. It's very similar to Task3, but the child process is implemented as a separate program.

A. Copy forkWait.c from Task 3 to a file named forkExec.c
B. Modify forkExec.c so the child process image is replaced by the image of a program named child. Use one of the exec family of functions to do this.
C. Write child.c to do the same thing as teh child process did in Task 4.
  - The child should give its pid each time it prints the message
  - The parent should give its pid each time it prints the message
  - The child program should take 3 command-line arguments, the message, Nc, and Tc.
  - To get an intersting exit status from teh child, have it return 37, rather than 0.
  */

  #include <sys/types.h>
  #include <unistd.h>
  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char **argv)
  {
    if(argc!=5){
      printf("[ ERROR ] Please use the syntax: task4 Nc Np Tc Tp\nNc = Number of iterations for child process\nNp = Number of iterations for parent process\nTc = Sleep time for child process\nTp = Sleep time for parent process\n");
      return -1;
    }
    int Nc = atoi(argv[1]);
    int Np = atoi(argv[2]);
    int Tc = atoi(argv[3]);
    int Tp = atoi(argv[4]);

    pid_t pid;
    char *message;
    int n,stime;

    printf("fork program starting\n");
    pid = fork();
    switch(pid)
    {
      case -1:
        perror("fork failed");
        exit(1);
      case 0:
        message = "This is the child";
        // Put exec stuff here.
        printf("Exec return: %d\n", execlp("./child", message, argv[1], argv[3]));
        break;
      default:
        message = "This is the parent";
        n=Np;
        stime = Tp;
        break;
      }

      for(; n > 0; n--) {
        printf("%s pid: %d\n", message, pid);
        sleep(stime);
      }
      if(pid!=0){
        printf("Waiting for child to terminate\n");
        waitpid(0);
        printf("Child termated\n");
      }
      exit(0);
  }
