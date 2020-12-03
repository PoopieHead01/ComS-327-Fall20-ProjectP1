#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gensnd.h"

// Returns 1 if it's invalid, 0 otherwise
int check_validity(char* str) {
    char* key_pad = "0123456789*#abcdABCD";

    for(int i = 0; i < strlen(str); i++) {
        for(int j = 0; j < strlen(key_pad); j++) {
            if(key_pad[j] == str[i])
                break;
            if(j == strlen(str) + 1)
                return 1;
        }
    }

    return 0;
}

int main() {
    // Allocate size of 10
    char* str = (char*)malloc(10);

    printf("Enter a 10-digit Phone number: \n");
    scanf("%s", str);

    // Repeat until the user inputs 10 digits & checks validity
    while(strlen(str) != 10 || check_validity(str)) {
        printf("Error! Enter a 10-digit Phone number: \n");
        scanf("%s", str);
    }

    // Loop
    for(int i = 0; i < strlen(str); i++) {
        //phone_pad(str[i]);
        //if(i + 1 != strlen(str))
            //make_silence(8000, 0.25);
    }

    free(str);
	return 0;
}
