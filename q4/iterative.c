/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

int maxSubArray(int A[], int n)
{
    int max_sum = 0, sum = 0;
    for (int i=0; i<n; ++i) {
        sum += A[i];            // 累計總和
        if (sum < 0) sum = 0;   // 零總比負數好

        // 隨時紀錄最大值
        if (sum > max_sum) max_sum = sum;
    }
    return max_sum;

}

int main()
{
    struct timespec start, end;
    double cpu_time;

    int a[9] = { -2,1,-3,4,-1,2,1,-5,4 };
    int ans;

    clock_gettime(CLOCK_REALTIME, &start);
    ans = maxSubArray(a,9);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diff_in_second(start, end);

    printf("ans = %d execution time = %lf nsec\n", ans, cpu_time);

    return 0;
}
