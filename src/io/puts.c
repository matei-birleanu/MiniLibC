// SPDX-License-Identifier: BSD-3-Clause
#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>
#include <string.h>
// Source https://man7.org/linux/man-pages/man3/puts.3.html
int puts(const char *s) {
    size_t len = strlen(s);
    ssize_t bytes_written = write(1, s, len);
    if (bytes_written < 0) {
        return -1;
    }
    write(1, "\n", 1);
    return 0;
}
