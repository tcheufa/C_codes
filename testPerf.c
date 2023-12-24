#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <float.h>

uint64_t get_prog_clock_time()
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == 0) {
        return (uint64_t) (tv.tv_sec * 1000000 + tv.tv_usec);
    }
    return 0;
}

uint64_t get_posix_clock_time()
{
    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
        return (uint64_t) (ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
}

int max (int a, int b, int c)
{
    if (a < b)
        a = b;
    if (a < c)
        a = c;
    return a;
}

int main ()
{
    uint64_t start = get_posix_clock_time();

//    for (int i = 3; i <= 1000; i += 2) {
//        printf("%d  ", i);
//        if (i % 3 == 0) {
//            printf("Fizz");
//        }
//        if (i % 5 == 0) {
//            printf("Buzz");
//        }
//        printf("\n");
//    }

//    for (int i = 0; i < 1000; i++) {
//        printf("%d : ", i);
//        if (i % 15 == 0) {
//            printf("FizzBuzz");
//        }
//        else if (i % 5 == 0) {
//            printf("Buzz");
//        }
//        else if (i % 3 == 0) {
//            printf("Fizz");
//        }
//        printf("\n");
//    }
    int a = 4, b = 5, c = 6;
    printf("min(%d, %d, %d) = %d", a, b, c,  max(a,b,c));
    uint64_t end = get_posix_clock_time();
    printf("\n\nEnd of program. Number of milliseconds elapsed : %.3f", (end - start) / 1000.);
    return 0;
}
