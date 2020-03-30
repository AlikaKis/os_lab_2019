#include "revert_string.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void RevertString(char *str)
{
    int i;
    int k = 0;
    char temp;
    for(i = strlen(str)-1; i >= strlen(str)/2; i--)
        {
            temp = str[i];
            str[i]=str[k];
            str[k]=temp;
            k = k + 1;
        }
}
