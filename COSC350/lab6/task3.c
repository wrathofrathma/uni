/*
A. Copy your modified fork1.c to a file named forkWait.c

B. Modify forkWait.c so the parent process waits for the child to finish. Use the code from BLP 4th edition in page 475 (page 458 in BLP 3rd edition), for the wait portion.

C. Print your modified forkWait.c to hand in.

D. Run your forkWait with Nc = 5, Np = 3, Tc = 1, and Tp = 1

E. Briefly describe how your result differs from the original program in Task2. Explain.

*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if(argc!=5){
    printf("[ ERROR ] Please use the syntax: task2 Nc Np Tc Tp\nNc = Number of iterations for child process\nNp = Number of iterations for parent process\nTc = Sleep time for child process\nTp = Sleep time for parent process\n");
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
      n = Nc;
      stime = Tc;
      break;
    default:
      message = "This is the parent";
      n=Np;
      stime = Tp;
      break;
    }

    for(; n > 0; n--) {
      puts(message);
      sleep(stime);
    }
    if(pid!=0){
      printf("Waiting for child to terminate\n");
      waitpid(0);
      printf("Child termated\n");
    }
    exit(0);
}

/* The primary difference here is that the terminated child in the previous task becomes a zombie process since wait was never called. In this task it cleans up the dead child */
