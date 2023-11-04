// SPDX-License-Identifier: BSD-3-Clause
// Source : https://man7.org/linux/man-pages/dir_all_by_section.html
// Source: https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/string.3.html
#include <string.h>

char *strcpy(char *destination, const char *source)
{
	int i = 0;
	while(1){
		*(destination + i) = *(source + i);
		if(destination[i] == '\0')
			break;
		i++;
	}
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	size_t i;

    for (i = 0; i < len && source[i] != '\0'; i++)
        destination[i] = source[i];
    for ( ; i < len; i++)
        destination[i] = '\0';

    return destination;
}

char *strcat(char *destination, const char *source)
{
	size_t dest_len = strlen(destination);
    size_t i;
	for (i = 0 ;source[i] != '\0' ; i++)
        destination[dest_len + i] = source[i];
    destination[dest_len + i] = '\0';
	return destination;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	size_t dest_len = strlen(destination);
    size_t i;
	for (i = 0 ; i < len && source[i] != '\0' ; i++)
        destination[dest_len + i] = source[i];
    destination[dest_len + i] = '\0';
	return destination;
	return destination;
}

int
strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2++)
		if (*s1++ == '\0')
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}
int strncmp(const char *str1, const char *str2, size_t len)
{
	int k = 0;
	long unsigned int i;
	while(k == 0 && i < len){
		if(str1[i] < str2[i])
			k = -1;
		else if (str1[i] > str2[i])
				k = 1;
		i++;
	}
	return k;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i = 0;
	while(str[i] != '\0') {
		if(str[i] == (char)c)
			return (char *)str + i;
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	int i = 0;
	char *ptr = NULL;
	while(str[i] != '\0') {
		if(str[i] == (char)c)
			ptr = (char *)str + i;
		i++;
	}
	return ptr;
}

char *strstr(const char *haystack, const char *needle)
{
	int i = 0;
	while(haystack[i] != '\0'){
		if(haystack[i] == *needle){
			int j = i, k = 0;
			while(haystack[j] == needle[k])
				{j++; k++;}
			if(needle[k] == '\0')
				return (char *)haystack + i;
		}
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	if (!haystack || !needle)
        return NULL;

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len == 0)
        return (char *)(haystack + haystack_len);

    const char *haystack_ptr = haystack + haystack_len - 1;
    const char *needle_ptr = needle + needle_len - 1;

    while (haystack_ptr >= haystack) {
        if (*haystack_ptr == *needle_ptr) {
            if (needle_ptr == needle) {
                // Found a matching substring
                return (char *)haystack_ptr;
            }
            haystack_ptr--;
            needle_ptr--;
        } else {
            haystack_ptr--;
            needle_ptr = needle + needle_len - 1;
        }
    }

    return NULL;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest = (char*)destination;
	char *src = (char *)source;
	for(long unsigned int i = 0 ; i < num; i++)
		dest[i] = src[i];
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest = (char*)destination;
	char *src = (char *)source;
	if (dest <= src) {
		for(long unsigned int i = 0;i < num; i++)
			dest[i] = src[i];
	} else {
		for(int i = num; i > 0; i--)
			dest[i-1] = src[i-1];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char *s1 = (unsigned char *)ptr1;
	unsigned char *s2 = (unsigned char *)ptr2;
	if(s1 == s2)
		return 0;
	while(num) {
		if(*s1 < *s2)
			return -1;
		if(*s1 > *s2)
			return 1;
		num--;
		s1++;
		s2++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	char * src = (char*) source;
	char vl = (char)value;
	int i = 0;
	while(num) {
		src[i] = vl;
		num--;
		i++;
	}
	return source;
}
