/*
    CSC 325-your_section_here
    Lab 6 - my_strings.c
    Name: Etienne Damoah
    Email: damoahe1@tcnj.edu
*/

#include "my_strings.h"
#include <stdlib.h>

// compares two char via difference
int cmp(char c1, char c2) {
    int diff = c1-c2;
    return diff;

}

// iterates through string to find address of the first instance of c in s
char* my_strchr(const char *s, int c) {
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == c) {
            return (char*)&s[i];
        }
    }

    return NULL;
}

// exhaustively iterates through haystack to find an instanse of needle 
//ie the pointer where the needle is first found
char *my_strstr(const char *haystack, const char *needle) {
    int needLen = my_strlen(needle);

    for(int i = 0; my_strlen(haystack)-i >= my_strlen(needle); i ++) {
        char temp[needLen+1];
        for(int j = 0; needle[j] != '\0'; j++) {
            temp[j] = haystack[i+j];
        }
        temp[needLen] = '\0';
        if(my_strcmp(temp, needle) == 0) {
           return (char*) &haystack[i];
        }
    }


    return NULL;

}

// takes two strings and trys to find one instance where cmp doesn't return 0 (a char of s1 in index n isn't equal to a char of s2 in index n)
int my_strcmp(const char *s1, const char *s2) {
    int verdict = 0;
    for(int i = 0; s1[i] != '\0'; i++) {
        verdict = cmp(s1[i], s2[i]);
        if(verdict != 0) {
            break;
        }  
    }

    return verdict;
}

// copies data from src and puts it into dst which is a static string
char* my_strcpy(char *restrict dst, const char *restrict src) {
    for(int i = 0; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }

    return dst;
}

// creates and returns a string stored in the heap to then takes the data from s
char *my_strdup(const char *s) {
    char* dupe = malloc(sizeof(s)*my_strlen(s));
    
    int i = 0;
    for(; s[i] != '\0'; i++) {
        dupe[i] = s[i];
    }
    dupe[i] = '\0';

    return dupe;

}

// attaches src to dst starting from dst's empty char, src includes emtpy char
// function doesn't do detect if there's enoungh space alloacted for src
char *my_strcat(char *restrict dst, const char *restrict src) {
    int dstLen = my_strlen(dst);

    for(int i = dstLen; i < dstLen+my_strlen(src); i++) {
        dst[i] = src[i-dstLen];
    }

    dst[my_strlen(dst)+1] = '\0';

    return dst;
}

// returns the length of string excluding the empty string
size_t my_strlen(const char *s) {
    size_t count = 0;
    char x = s[count];

    while(x != '\0') {
        count++;
        x = s[count];
    }

    return count;
}
