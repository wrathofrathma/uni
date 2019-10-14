/*
A.Write a function named openUtmpFile that opens the utmp file and returns its file descriptor. If the file can't be opened, the function writes an error message and exits.

B. Call openUtmpFile in the main function. Compile your program to check for errors. */
/*
A. Add code in your main function to loop through the utmp file, reading each record. For each record, just print the user name.

B. Add code in the loop to count the number of records that are USER_PROCESS records(logged-in user). When the loop is done, print the number of logged-in users found. Check your results for correctness.

*/

#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int openUtmpFile(){
    int file = open("/var/run/utmp", O_RDONLY);
    if(file < 0){
        write(2, "Unable to open utmp file\n", 30);
        exit(-1);
    }
    return file;
}
int main(int argc, char **argv){
    int f = openUtmpFile();
    struct utmp buf;
    int login_num = 0;
    while(read(f, &buf, sizeof(buf))){
        printf("Username : %s\n", buf.ut_user);
        if(buf.ut_type==7)
            login_num++;
    }
    printf("%d number of USER_PROCESSes found\n", login_num);
    close(f);
    return 0;
}
