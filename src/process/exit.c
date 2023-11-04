// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
//Source : https://man7.org/linux/man-pages/man3/exit.3.html
long exit(long exit_code)
{
	return syscall(__NR_exit, exit_code);
}
