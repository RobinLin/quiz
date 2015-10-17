/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


char smallest_character(char str[], char c)
{
    int i = 0;
    while(i != '\0') {
        if(str[i] > c) {
            return str[i];
        }
        i++;
    }
    return str[0];
}

int main()
{
    char a[] = {'c','f','j','p','v'};
    char out = smallest_character(a,'a');
    printf("%c\n", out);

    return 0;
}
