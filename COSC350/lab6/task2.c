/*
a. Copy fork1.c from BLP 4th edition page 474 (page 457 in BLP 3rd edition).

b. Compile and run it to be sure you understand what it does.

c. Modify your fork1.c to take four command-line arguments:
  1. Nc - number of iterations for child processs
  2. Np - number of iterations for parent process
  3. Tc - Sleep time for child process
  4. Tp - Sleep time for parent process

  Then modify the code accordingly.

d. Run the program as fork1 5 3 1 1. You should get the same result as running the original version.

E. Run the program with the following values (and any other values you find interesting):

Nc - Np - Tc - Tp
5  - 3  - 1  - 5
5  - 3  - 5  - 1
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
    exit(0);
}
