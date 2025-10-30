/*
    CSC 325-your_section_here
    Lab 6 - stringtester.c
    Name: Etienne Damoah
    Email: damoahe1@tcnj.edu
*/

#include "my_strings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    char str1[] = "StriNg";
    char str2[] = "string";

    char str3[] = "1234";
    char str4[] = "123456";

    char str5[] = "Pi";
    char str6[] = "rho";
    
    char str7[] = "pi*r^2";
    char str8[] = "(n)!/n!*(n-r)!";

    char str9[20] = "works";
    char str10[] = " now";
    
    char str11[] = "Yhorm";
    char str12[] = "Gael";

    char str13[] = "Dismas";
    char str14[strlen(str13)+1];
    strcpy(str14, "______");
    char str15[] = "Bigby";
    char str16[strlen(str15)+1];
    strcpy(str16, "_____");
    

    srand(time(NULL));
    int num;
    
    
    printf("\nTesting string functions:\n\n");

    // tests strcmp
    printf("strcmp(\"%s\", \"%s\")\n", str1, str2);

    if(my_strcmp(str1, str2) != strcmp(str1, str2)) {
        printf("\n!!!%s and %s breaks my_strcmp()\n\n", str1, str2);
    }
    
    printf("strcmp(\"%s\", \"%s\")\n", str1, str1);
    if(my_strcmp(str1, str1) != strcmp(str1, str1)) {
        printf("\n!!!%s and %s breaks my_strcmp()\n\n", str1, str1);   
    }

    printf("strcmp(\"%s\", \"%s\")\n", str2, str1);
    if(my_strcmp(str2, str1) != strcmp(str2, str1)) {
        printf("\n!!!%s and %s breaks my_strcmp()\n\n", str2, str1);   
    }
        
    // tests strlen
    printf("strlen(\"%s\")\n", str3);
    if(my_strlen(str3) != strlen(str3)) {
        printf("\n!!!%s breaks my_strlen()\n\n", str3); 
    }

    printf("strlen(\"%s\")\n", str4);
    if(my_strlen(str4) != strlen(str4)) {
        printf("\n!!!%s breaks my_strlen()\n\n", str4); 
    }

    
    // tests strchr

    num = rand()%(strlen(str5));

    printf("strchr(\"%s\", '%c')\n", str5, str5[num]);
    if(my_strchr(str5, str5[num]) != strchr(str5, str5[num])) {
        printf("\n!!!%s breaks my_strchr(\"%s\", '%c')\n\n", str5, str5, str5[num]);
    }

    num = rand()%(strlen(str6));
    printf("strchr(\"%s\", '%c')\n", str6, str6[num]);
    if(my_strchr(str6, str6[num]) != strchr(str6, str6[num])) {
        printf("\n!!!%s breaks my_strchr(\"%s\", '%c')\n\n", str6, str6, str6[num]);
    }

    num = rand()%(126-33+1);
    printf("strchr(\"%s\", '%c')\n", str5, (char)num);
    if(my_strchr(str5, (char)num) != strchr(str5, (char)num)) {
        printf("\n!!!%s breaks my_strchr(\"%s\", '%c')\n\n", str5, str5, (char)num);
    }

    num = rand()%(126-33+1);
    printf("strchr(\"%s\", '%c')\n", str6, (char)num);
    if(my_strchr(str6, (char)num) != strchr(str6, (char)num)) {
        printf("\n!!!%s breaks my_strchr(\"%s\", '%c')\n\n", str6, str6, (char)num);
    }
    
    // tests strstr

    num = rand()%(strlen(str7)-1);
    char temp[3];
    temp[0] = str7[num];
    temp[1] = str7[num+1];
    temp[2] = '\0';

    printf("strstr(\"%s\", \"%s\")\n", str7, temp);
    if(my_strstr(str7, temp) != strstr(str7, temp)) {
        printf("\n!!!%s and %s breaks my_strstr()\n\n", str7, temp);
    }

    num = rand()%(strlen(str8)-1);
    temp[0] = str8[num];
    temp[1] = str8[num+1];
    temp[2] = '\0';

    printf("strstr(\"%s\", \"%s\")\n", str8, temp);
    if(my_strstr(str8, temp) != strstr(str8, temp)) {
        printf("\n!!!%s and %s breaks my_strcat()\n\n", str8, temp);
    }
    
    // tests strcat
    printf("strcat(\"%s\", \"%s\")\n", str9, str10);
    if(strcmp(my_strcat(str9, str10), strcat(str9, str10)) != 0) {
        printf("\n!!!%s and %s breaks my_strcat()\n\n", str9, str10);   
    }

    
    // tests strdup
    printf("strdup(\"%s\")\n", str11);
    char* x = my_strdup(str11);
    if(strcmp(str11, x) != 0) {
        printf("\n!!!%s breaks my_strcat()\n\n", str11);
    }
    
    free(x);
    x = NULL;

    printf("strdup(\"%s\")\n", str12);
    char* y = my_strdup(str12);
    if(strcmp(str12, y) != 0) {
        printf("\n!!!%s breaks my_strcat()\n\n", str12);
    }

    free(y);
    y = NULL;

    // tests strcpy
    printf("strcpy(NULL, \"%s\")\n", str13);
    if(strcmp(str13, my_strcpy(str14, str13)) != 0) {
        printf("\n!!!%s breaks my_strcpy()\n\n", str13);
    }
    
    printf("strcpy(NULL, \"%s\")\n", str15);
    if(strcmp(str15, my_strcpy(str16, str15)) != 0) {
        printf("\n!!!%s breaks my_strcpy()\n\n", str15);
    }
    
     
}
