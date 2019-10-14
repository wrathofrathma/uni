/* Write your own mv named MyMv
 * By using bash command mv, you can move a file from current directory to another directory. Write your own mv called MyMv by using system calls link() and unlink(). Your program receives two arguments: File name and path to a directory where the file need to move, or file name and path to directory with a file name.
 * If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to directory as a file name.
EX)
Move a file foo to under directory ~/separk/cosc350
 * ./MyMv foo ~/separk/cosc350
Move a file foo to under directory ~/separk/cosc350 named abc if there is no directory named abc.
 * ./MyMv foo ~/separk/cosc350/abc
Move a file foo to under directory ~/separk/cosc350 named foo if there is no directory named foo.
 * ./MyMv foo ~/separk/cosc350/foo



 LITERALLY the same as lab 4 task 4
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <limits.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
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
 void getFileName(char *input, char *out){
   int i=0;
   int j=0;
   while(input[i]!='\0'){
     if(input[i]=='/'){
       if(input[i+1]=='\0')
         break;
       zerostr(out);
       j=0;
     }
     else{
       out[j]=input[i];
       j++;
     }
     i++;
   }
 }
 int main(int argc, char **argv){
   if(argc!=3){
     printf("[ ERROR ] Please structure your command as \'MyMv input_dest output_dest\'\n");
     return -1;
   }
   //Verify the input file exists.
   if(access(argv[1], F_OK)==-1){
     printf("[ ERROR ] An issue occured while trying to access the input file.\n");
     return -1;
   }

   //Check if the output is a directory
   struct stat sbuf;
   stat(argv[2], &sbuf);
   if(S_ISDIR(sbuf.st_mode)){
     char buf[PATH_MAX];
     char filename[PATH_MAX];
     getFileName(argv[1], filename);
     sprintf(buf, "%s/%s", argv[2], filename);
     link(argv[1], buf);
     unlink(argv[1]);
   }
   else{
     link(argv[1], argv[2]);
     unlink(argv[1]);
   }

   return 0;
 }
