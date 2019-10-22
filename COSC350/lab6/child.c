#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if(argc!=3){
    printf("[ ERROR ] Please use the syntax: child Message Nc Tc\nMessage = child message\nNc = Number of iterations for child process\nTc = Sleep time for child process\n");
    return -1;
  }
  char *message = argv[0];
  int Nc = atoi(argv[1]);
  int Tc = atoi(argv[2]);

  pid_t pid = getpid();
  int n=Nc;

  for(; n > 0; n--) {
    printf("%s pid: %d\n", message, pid);
    sleep(Tc);
  }
  exit(37);
}
