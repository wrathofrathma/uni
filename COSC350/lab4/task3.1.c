/* Write a simple program called hello.c and compile it and create executable file named hello.
 * Write a C program for sequence of following task.
 * * By using system cal build following directory structure
 * * * home/separk/Dir1 home/separk/Dir2/Dir21
 * * By using system calls, copy hello file under ~/Dir2/Dir12/
 * * By using system calls, make a symbolic link named toDir12 to directory Dir12
 * * By using system calls, make a symbolic link named toHello to executable file ~/Dir12/hello
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
// Returns the length of a string in bytes.
unsigned int strlen(const char *s){
  int i = 0;
  while(s[i]!='\0')
    i++;
  return i;
}

// Concatenates two strings into an output string. Returns the size in bytes of the new string.
// Zero checking for if there is a buffer overflow.
unsigned int strappend(const char *s1, const char *s2, char *out){
  int size=0;
  int i=0;
  while(s1[i]!='\0'){
    out[size]=s1[i];
    size++;
    i++;
  }
  i=0;
  while(s2[i]!='\0'){
    out[size]=s2[i];
    i++;
    size++;
  }
  out[size]='\0';
  return size;
}

void zerostr(char *s){
  int i=0;
  while(s[i]!='\0'){
    s[i]=0;
    i++;
  }
}
int main(){
  umask(0);
  const char *username = getenv("USERNAME");
  int user_size = strlen(username);
  printf("Username: %s\nString Length: %d\n", username, user_size);
  //Creating the base home directory string.
  // "/home/" is 6 chars
  char home[strlen(username)+7];
  int home_size = strappend("/home/", username, home);
  home_size = strappend(home, "/", home);
  printf("Home Directory: %s\nString Length: %d\n", home, home_size);

  //Iteratively create the directories.
  char buffer[256];
  //Generate directory path.
  int dsize = strappend(home, "Dir1", buffer);
  //Create directory.
  int rval = mkdir(buffer,0555);
  zerostr(buffer);
  //Create second directory.
  dsize = strappend(home, "Dir2", buffer);
  //Create directory.
  rval = mkdir(buffer,0555);
  //Create third directory.
  dsize = strappend(buffer,"/Dir21/", buffer);
  rval = mkdir(buffer,0555);

  return 0;
}
