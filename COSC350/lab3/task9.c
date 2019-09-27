/* A palindrome is a word, phrase, number or other sequence of units that can be read the same way in either direction. WRite a c-function int palind(int fd1, int fd2) that takes two independent file descriptors fd1 and fd2 that are already opened to the same file. The function palind() uses lseek to scan the file and returns 1 if the file contains a palindrome (reads the same forward and reverse) and 0 if not. You may assume that the file is well-formed and contains just lower-case alphabetic characters on a single line. You also need write a main function to test your palind() function works properly. The main function accepts a file name as an argument. The main() function opens the file once and creates duplicate file descriptors and calls the function palind() to  heck whether the file contains a palindrome or not. */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>


// I didn't see the point in using two file descriptors since they share a single seek offset in the file table.
int palind(int fd1){
  //Get our two offsets. Using -2 from SEEK_END of file because EOF is at -1 I believe.
  int first=0, last=lseek(fd1, -2, SEEK_END);
  //Our buffers.
  char b1, b2;
  //We can loop until we hit the mid point(first==last)
  //or until we encounter a mismatch.
  while(first<last){
    //Set seek to first offset and read into a buffer. Check for errors.
    lseek(fd1, first, SEEK_SET);
    if(read(fd1, &b1, 1)!=1){
      printf("[ ERROR ] Encountered an error when reading\n");
      return 0;
    }
    //Set seek to last offset and read into a buffer. Check for errors.
    lseek(fd1, last, SEEK_SET);
    if(read(fd1, &b2, 1)!=1){
      printf("[ ERROR ] Encountered an error when reading\n");
      return 0;
    }
    if(b1!=b2)
      return 0;
    first++;
    last--;

  }
  return 1;
}


int main(int argc, char **argv){
  //Input checking to see if we passed a file name.
  if(argc!=2){
    printf("[ ERROR ] Please input a file name to check for palindrome status.\n");
    return -1;
  }
  //Open the file and check for errors.
  int fd1 = open(argv[1], O_RDONLY);
  if(fd1==-1){
    printf("[ ERROR ] An error occurred when opening %s for reading.\n", argv[1]);
    return -1;
  }
  //File is opened, now let's duplicate the file descriptor.
  int fd2 = dup(fd1);

  printf("[ INFO ] Checking if %s is a palindrome...%s\n", argv[1], palind(fd1) ? "true" : "false");

  close(fd1);
  close(fd2);
  return 0;
}
