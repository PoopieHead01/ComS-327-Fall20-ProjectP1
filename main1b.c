#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gensnd.h"

// Method to check if "str" is fully numeric
int is_number(char* str) {
    char* nums = "0123456789*#abcdABCD";
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

int main(int argc, char * argv[]) {
    if (argc < 2) {
        printf("Usage: ./dtmf <phone_number> | ./dtmf <phone_number> <output_file.wav>\n");
        return 1;
    } else if (argc > 3) {
        printf("Too many agrument. Only up to 2 arguments is valid.\n");
        printf("Usage: ./dtmf <phone_number> | ./dtmf <phone_number> <output_file.wav>\n");
        return 1;
    } else {
        if(argc == 2) {
            if(!is_number(argv[1])) {
                printf("%s\n", argv[1]);
                printf("Invalid parameter!");
                printf("Usage: ./dtmf <phone_number> | ./dtmf <phone_number> <output_file.wav>\n");

                return 1;
            }

            sound *silence = genSilence(8000, 0.25);
            sound *temp;

            for(int i = 0; i < strlen(argv[1]); i++) {
                temp = genDTMF(argv[1][i], 8000, 0.5);
                for(int j = 0; j < temp->length; j++)
                    printf("%f\n", temp->samples[j]);
                for(int j = 0; j < silence->length; j++) {
                    if(i + 1 != strlen(argv[1]))
                        printf("%f\n", silence->samples[j]);
                }
                free(temp->samples);
                free(temp);
            }
            free(silence);
        } else if(argc == 3) {
            if(!is_number(argv[1])) {
                printf("Invalid parameter!");
                printf("Usage: ./dtmf <phone_number> | ./dtmf <phone_number> <output_file.wav>\n");
                return 1;
            }

            FILE  *file = fopen(argv[2], "w");
            sound *silence = genSilence(8000, 0.25);
            sound *temp;

            for(int i = 0; i < strlen(argv[1]); i++) {
                temp = genDTMF(argv[1][i], 8000, 0.5);
                outputSound(temp, file);
                if(i + 1 != strlen(argv[1]))
                    outputSound(silence, file);
                free(temp->samples);
                free(temp);
            }
            fclose(file);
            free(silence);
        }
    }
    return 0;
}
