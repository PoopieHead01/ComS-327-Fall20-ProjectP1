#ifndef SOUND_H
#define SOUND_H

typedef struct sound_t {
    float* samples;
    int length;
    float rate;
} sound;

#endif
