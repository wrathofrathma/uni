/* Write a c program that receives a sequence of integers on the command line and prints their sum to the screen. Define your own function to convert string to integer instead of using atoi function.

Exit the program with an appropriate error message under the following condition: There is not at least one integer on the command line.
*/

#include <stdio.h>
#include <stdlib.h>
//Converts a single digit character to an integer number.
int _ctoi(char c_num){
  int zero = '0';
  int num = c_num-zero;
  if(num<=9 && num>=0)
    return num;
  else
    return -1;
}

//Converts a character array representation of a number to an integer.
int _atoi(char *s_num){
  int index = 0;
  int total=0;
  while(s_num[index]!='\0'){
    int ci = _ctoi(s_num[index]);
    if(ci==-1){
      printf("[ ERROR ] Encountered an error in conversion. Likely not a number detected.\n");
      exit(-1);
    }
    total+=ci;
    index++;
    total*=10;
  }
  total/=10;
  return total;
}


int main(int argc, char **argv){
  if(argc<2){
    printf("[ ERROR ] Insufficient number of parameters. Please input numbers as arguments.\n");
    return -1;
  }
  int sum=0;
  for(int i=1; i<argc; i++){
    sum+=_atoi(argv[i]);
  }
  printf("Sum of input numbers: %d\n", sum);

  return 0;
}
