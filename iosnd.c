#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "iosnd.h"

int outputSound(sound *s, FILE *f) {
    // File doesn't exist
    if(f == NULL)
        return 1;

    for(int i=0; i<s->length;i++)
        fprintf(f, "%f\n", s->samples[i]);

    return 0;
}
