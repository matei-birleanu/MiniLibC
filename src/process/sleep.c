#include <time.h>
#include <unistd.h>
// Source https://man7.org/linux/man-pages/man3/sleep.3.html
unsigned int sleep(unsigned int seconds){
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) == -1) {
        req = rem;
    }
    return rem.tv_sec;
}
