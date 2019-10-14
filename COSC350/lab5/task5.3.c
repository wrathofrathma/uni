/* Write your own function myasctime which operates exactly same as char *asctime(const struct tm *timeptr)

Write a c program to demonstrate your myasctime function
*/
#include <time.h>
#include <stdio.h>
#include <string.h>

char *myasctime(const struct tm *timeptr){
        static char result[26]; // Returned string. Needs to be static because we don't want to dynamically manage memory due to how we'd normally be calling this mid print statement.

        static char weekday[7][3] = {
            "Sun",
            "Mon",
            "Tue",
            "Wed",
            "Thu",
            "Fri",
            "Sat",
        };

        static char month[12][3] = {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
        };
        sprintf(result, "%.3s", weekday[(*timeptr).tm_wday]);
        sprintf(result, "%s %.3s", result, month[(*timeptr).tm_mon]);
    sprintf(result, "%s  %d %.2d:%.2d:%.2d %d\n", result, (*timeptr).tm_mday, (*timeptr).tm_hour, (*timeptr).tm_min, (*timeptr).tm_sec, (*timeptr).tm_year+1900);
    return result;
}

int main(int argc, char **argv){
    struct tm t;
    t.tm_sec=32;
    t.tm_min=10;
    t.tm_hour=3;
    t.tm_mday=5;
    t.tm_mon=6;
    t.tm_year=109;
    t.tm_wday=4;
    t.tm_yday=100;
    t.tm_isdst=0;
        printf("asctime(&t) from time.h\n");
    printf("%s\n",asctime(&t));
        printf("myasctime(&t)\n");
    printf("%s\n",myasctime(&t));

    return 0;
}
