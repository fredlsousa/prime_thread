#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/times.h>
#include <time.h>

#ifndef COUNT
#define COUNT 100
#endif



int counter;


int main(){

    struct tms time1,time2;
    times(&time1);

    int count = COUNT;
    pid_t pid;
    while(count--){
        if((pid=fork())<0){
            printf("fork error\n");
        } else if(pid==0){ /* child */
            int i;
            for (i=0; i<10000; i++) {
                printf("in child %i\n", getpid());
            }
            exit(0);
        } else {
            waitpid(pid,NULL,0); /*wait()*/
        }
    }
    printf("COUNTER: %d\n",counter);



    times(&time2);

    printf("%lu %lu %lu %lu\n", time2.tms_utime, time2.tms_stime, time2.tms_cutime, time2.tms_cstime);

    long double clktck=sysconf(_SC_CLK_TCK);
    double user=(time2.tms_utime-time1.tms_utime)/(double)clktck;
    double system=(time2.tms_stime-time1.tms_stime)/(double)clktck;
    double cuser=(time2.tms_cutime-time1.tms_cutime)/(double)clktck;
    double csystem=(time2.tms_cstime-time1.tms_cstime)/(double)clktck;

    printf("USER:%lf\nSYSTEM:%lf\n",user,system);
    printf("CUSER:%lf\nCSYSTEM:%lf\n",cuser,csystem);



    return 0;
}