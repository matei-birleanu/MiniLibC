#include <internal/syscall.h>
#include <time.h>
#include <internal/io.h>
#include <internal/types.h>
#include <errno.h>
// Source https://man7.org/linux/man-pages/man2/nanosleep.2.html
int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int rval = syscall(__NR_nanosleep, req, rem);
    if (rval < 0){
        errno  = -rval;
        return -1;
    }
    return 0;
}
