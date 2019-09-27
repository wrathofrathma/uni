/* Write c code which passes input (text file) and output file name as a command line arguments. Open the input file as read only and open output file with mode rw-rw-rw. Your program encodes each character to ASCII code number and writes to output file. You need consider argument number error and open file error. You must not use any library function to convert a character to ascii number. */



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //close
#include <sys/stat.h> //umask


//Converts an ascii character to the numeric ascii representation in a c-string.
//No libraries allowed, so no sprintf :(
//Input - source_char, c_string result
//Output - number of bytes used
int _itoa(int src, char *out){
  int buf;
  int zero = '0'; //First ascii number.
  int index=0;
  while(src>0){
    buf=src%10;
    out[index]=buf+zero;
    index++;
    src/=10;
  }
  //Now reverse the array.
  int first=0, last=index-1;
  char buffer;
  while(first<last){
    buffer = out[first];
    out[first]=out[last];
    out[last]=buffer;
    first++;
    last--;
  }
  out[index]='\0';
  return index;
}

int main(int argc, char **argv){
  if(argc!=3){
    printf("[ ERROR ] Please input an input and output file name.\n");
    return -1;
  }

  int ifd = open(argv[1], O_RDONLY);
  if(ifd==-1){
    printf("[ ERROR ] An error occurred when attempting to open %s\n", argv[1]);
    return -1;
  }

  umask(0000);
  int ofd = open(argv[2], O_WRONLY | O_CREAT, 0666);
  if(ofd==-1){
    printf("[ ERROR ] An error occurred when attempting to open %s\n", argv[2]);
    close(ifd);
    return -1;
  }

  char cbuffer;
  short ibuffer;
  char space=' ';
  char str[10];
  int ssize=0;
  while(read(ifd, &cbuffer, 1)==1){
    ssize=_itoa(cbuffer, str);
    write(ofd, str, ssize);
    write(ofd, &space, 1);

  }

  close(ifd);
  close(ofd);
  return 0;
}
