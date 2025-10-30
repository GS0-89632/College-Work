// DO NOT MODIFY THIS FILE!

#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>

char *my_strcat(char *restrict dst, const char *restrict src);
char *my_strchr(const char *s, int c);
int my_strcmp(const char *s1, const char *s2);
char *my_strcpy(char *restrict dst, const char *restrict src);
char *my_strdup(const char *s);
size_t my_strlen(const char *s);
char *my_strstr(const char *haystack, const char *needle);

#endif