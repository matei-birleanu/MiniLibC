#ifndef _TIME_H_
#define _TIME_H_	1

#ifdef __cplusplus
extern "C" {
#endif

#include <internal/types.h>
//Source https://man7.org/linux/man-pages/man2/nanosleep.2.html
struct timespec {
	long tv_sec;
	long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#ifdef __cplusplus
}
#endif

#endif
