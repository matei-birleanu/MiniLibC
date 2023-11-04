// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	void * adr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(adr, size);
	return adr;
}

void *calloc(size_t nmemb, size_t size)
{
	void *adr = mmap(NULL, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	mem_list_add(adr, size * nmemb);
	return adr;
}

void free(void *ptr)
{
	struct mem_list *start = mem_list_find(ptr);

	if (start == NULL)
		exit(0);
	void * adr = ptr;
	int size = start->len;
	mem_list_del(ptr);
	munmap(adr, size);
}

void *realloc(void *ptr, size_t size)
{
	return mmap(ptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return mmap(ptr, size * nmemb, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	return NULL;
}
