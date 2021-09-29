#include <time.h>
#include <stdio.h>
#include "common.h" 

const char* Time()
{ 
    time_t t = time(NULL);
    struct tm tm = *localtime(&t); 
    static char str[17];      
    
    sprintf(str,"%04d-%02d-%02d %02d:%02d", 
            tm.tm_year+1900, tm.tm_mon+1, 
            tm.tm_mday, tm.tm_hour, 
            tm.tm_min); 
    return str;
} 