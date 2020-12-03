#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gensnd.h"

float frequency;
float sample_rate;
float duration;

// Method to check if "str" is fully numeric
int is_number(char* str) {
    char* nums = "0123456789";
    int count = 0;

    // Loops thru the array to check if str is fully numeric
    for(int i = 0; i < strlen(str); i++) {
        for(int j = 0; j < strlen(nums); j++) {
            if(nums[j] == str[i])
                count += 1;
        }
    }

    // Fully numeric
    if(strlen(str) == count)
        return 1;
    else return 0;
}

int main(int agrc, char * agrv[]) {
    char temp;
    int run = 1;

	printf("Enter a frequency: \n");
    scanf("%s", &temp);

    // Run infinitely until the user inputs a float val
    while(run) {
        if(!is_number(&temp)) {
            printf("Enter a frequency: \n");
            scanf("%s", &temp);
        } else {
            frequency = atof(&temp);
            run = 0;
        }
    }

    // Reset
    run = 1;
    temp = '\n';

    printf("Enter a sample rate: \n");
    scanf("%s", &temp);

    // Run infinitely until the user inputs a float val
    while(run) {
        if(!is_number(&temp)) {
            printf("Enter a sample rate: \n");
            scanf("%s", &temp);
        } else {
            sample_rate = atof(&temp);
            run = 0;
        }
    }

    // Reset
    run = 1;
    temp = '\n';

    printf("Enter the duration: \n");
    scanf("%sc", &temp);

    // Run infinitely until the user inputs a float val
    while(run) {
        if(!is_number(&temp)) {
            printf("Enter a duration: \n");
            scanf("%s", &temp);
        } else {
            duration = atof(&temp);
            run = 0;
        }
    }

    //gensine(frequency, sample_rate, duration);

    return 0;
}
