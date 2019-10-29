/* Wait for a thread for concurrent calculations 
 * Thread #1: Get test scores from a keyboard up to 20 and save into the array.
 * Thread #2: Calculate an average score and Medium value and display.
 * Thread #3: get hte minimum and the maximum score and display
 * Thread #4: Clear buffer and set to 0 and display after thread #2, thread #3 finishes its job.
 * Thread #2 and #3 must wait for thread #1 to finish its job. Once thread #1 finishes its job, thread #2 and thread #3 works concurrently. Thread#4 must wait for thread #2 and Thread #3 finishes its job.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void err(char *m){
    printf("[ ERROR ] %s\n", m);
    exit(1);
}

int a[20]; //Array
int n=0; //Array size

void printArr(){
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void getScores(){
    char buf[256];
    int ibuf=0;

    printf("Please enter your score list.\nAscii characters will be treated as 0, and enter -1 to end the loop\n");

    for(int i=0; i<20; i++){
        printf("Score[1] : ");
        scanf("%s", buf);
        ibuf=atoi(buf);
        if(ibuf==-1)
            break;
        else{
            a[i] = ibuf;
            n++;
        }
    }
    
    int x=0;
    int y=0;
    //Sorting, i know it's a trash sorting algorithm, but eh, only 20 elements.
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n; j++){
            if(a[i] > a[j]){
                x=a[i];
                y=a[j];
                a[j]=x;
                a[i]=y;
            }
        }
    }
    printf("Array stats...\nNumber of elements %d\nArray entered: ", n);
    printArr();
}

void average(){
    float avg=0;
    for(int i=0; i<n; i++)
        avg+=a[i];
    avg/=n;    
    printf("Median calced as the middle value value at a[n/2]\n");
    printf("Average Score : %f\nMedian Score %d\n",avg, a[n/2]);
}
void minmax(){
    printf("Min: %d\nMax %d\n", a[0], a[n-1]);
}

void clearbuf(pthread_t *p){
    pthread_join(p[0], NULL);
    pthread_join(p[1], NULL);
    for(int i=0; i<n; i++)
        a[i]=0;
}

int main(int argc, char **argv){
   
    //Creating threads
    pthread_t score_t;
    pthread_t avg_t;
    pthread_t max_t;
    pthread_t buf_t;
    int score_pt = pthread_create(&score_t, NULL, getScores, NULL);
    pthread_join(score_t, NULL);
    int avg_pt = pthread_create(&avg_t, NULL, average, NULL);
    int max_pt = pthread_create(&max_t, NULL, minmax, NULL); 

    pthread_t arr[2] = { avg_t, max_t };

    int buf_pt = pthread_create(&buf_t, NULL, clearbuf, arr); 
    pthread_join(buf_t, NULL); 

    printf("Buffer cleared and execution complete\n");
    printArr();
    exit(0);
}
