/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


char smallest_character(char str[], char c)
{
    int i = 0;
    while(i != '\0') {
        if(str[i] > c) {
            return str[i];
        }
        i++;
    }
    return str[0];
}

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

int main()
{
    struct timespec start, end;
    double cpu_time;
    char a[] = {'c','f','j','p','v'};
    clock_gettime(CLOCK_REALTIME, &start);
    char out = smallest_character(a,'a');
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("execution time of iterative : %lf sec\n", cpu_time);
    return 0;
}
