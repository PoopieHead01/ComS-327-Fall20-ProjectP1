#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gensnd.h"

// void gensine(float frequency, float sampleRate, float duration) {
//     int samplesAmount = duration * sampleRate;
//     for(int i = 0; i < samplesAmount; i++){
//        printf("%.6lf\n", sin(2.0 * M_PI * frequency * i / sampleRate));
//   }
// }

/*
 A function that will compute a specific hertz sound tone and then stores it in a sound pointer samples array member.
 This method will be use for testing.
 */
sound *gensine(float hertz, float sample_rate, float duration) {
    sound *gensine2 = (sound*)malloc(sizeof(sound));
    gensine2->rate = sample_rate;
    gensine2->length = sample_rate * duration;
    gensine2->samples = (float *)malloc(sizeof(float)*sample_rate*duration);
    int samplesAmount = duration * sample_rate;
    for(int i = 0; i < samplesAmount; i++) {
        gensine2->samples[i] = sin(2.0 * M_PI * hertz * i / sample_rate);
    }
    return gensine2;
}

// void DTMF(float freq1, float freq2) {
//     int samplesAmount = 0.5 * 8000;
//     for(int i = 0; i < samplesAmount; i++) {
//         printf("%.6lf\n", (sin(2.0 * M_PI * freq1 * i / 8000) + sin(2.0 * M_PI * freq2 * i / 8000))/2.0);
//     }
// }

/*
 A function that will compute the phone pad character sound tone and then stores it in a sound pointer samples array member.
 This method will be use in main1b.c for printing to standardout or write to file.
 */
sound *genDTMF(char key, float sample_rate, float duration){
    float freq1, freq2 = 0;
    switch (key) {
        case '1':
            freq1 = 697;
            freq2 = 1209;
            break;
        case '2':
            freq1 = 697;
            freq2 = 1336;
            break;
        case '3':
            freq1 = 697;
            freq2 = 1477;
            break;
        case '4':
            freq1 = 770;
            freq2 = 1209;
            break;
        case '5':
            freq1 = 770;
            freq2 = 1336;
            break;
        case '6':
            freq1 = 770;
            freq2 = 1477;
            break;
        case '7':
            freq1 = 852;
            freq2 = 1209;
            break;
        case '8':
            freq1 = 852;
            freq2 = 1336;
            break;
        case '9':
            freq1 = 852;
            freq2 = 1477;
            break;
        case 'a':
        case 'A':
            freq1 = 697;
            freq2 = 1633;
            break;
        case 'b':
        case 'B':
            freq1 = 770;
            freq2 = 1633;
            break;
        case 'c':
        case 'C':
            freq1 = 852;
            freq2 = 1633;
            break;
        case 'd':
        case 'D':
            freq1 = 941;
            freq2 = 1633;
            break;
        case '*':
            freq1 = 941;
            freq2 = 1209;
            break;
        case '0':
            freq1 = 941;
            freq2 = 1336;
            break;
        case '#':
            freq1 = 941;
            freq2 = 1477;
            break;
        default:
            printf("Not in the phone pad\n");
    }
    sound *genDTMF2 = (sound*)malloc(sizeof(sound));
    genDTMF2->rate = sample_rate;
    genDTMF2->length = sample_rate * duration;
    genDTMF2->samples = (float *)malloc(sizeof(float)*sample_rate*duration);
    int samplesAmount = duration * sample_rate;
    for(int i = 0; i < samplesAmount; i++){
    genDTMF2->samples[i] = (sin(2.0 * M_PI * freq1 * i / sample_rate) + sin(2.0 * M_PI * freq2 * i / sample_rate))/2.0;
  }
  return genDTMF2;
}

// void phone_pad(char ch) {
//     switch (ch) {
//         case '1':
//             DTMF(697, 1209);
//             break;
//         case '2':
//             DTMF(697, 1336);
//             break;
//         case '3':
//             DTMF(697, 1477);
//             break;
//         case '4':
//             DTMF(770, 1209);
//             break;
//         case '5':
//             DTMF(770, 1336);
//             break;
//         case '6':
//             DTMF(770, 1477);
//             break;
//         case '7':
//             DTMF(852, 1209);
//             break;
//         case '8':
//             DTMF(852, 1336);
//             break;
//         case '9':
//             DTMF(852, 1477);
//             break;
//         case 'a':
//         case 'A':
//             DTMF(697, 1633);
//             break;
//         case 'b':
//         case 'B':
//             DTMF(770, 1633);
//             break;
//         case 'c':
//         case 'C':
//             DTMF(852, 1633);
//             break;
//         case 'd':
//         case 'D':
//             DTMF(941, 1633);
//             break;
//         case '*':
//             DTMF(941, 1209);
//             break;
//         case '0':
//             DTMF(941, 1336);
//             break;
//         case '#':
//             DTMF(941, 1477);
//             break;
//         default:
//             printf("Not in the phone pad\n");
//     }
// }
//
// void make_silence(float sampleRate, float duration) {
//     for(int i = 0; i < sampleRate * duration; i++) {
//         printf("%d\n", 0);
//     }
// }

/*
 Generates a bunch of 0s that represent silence tones and stores it the samples array.
 Returns the sound pointer
 */
sound *genSilence(float sample_rate, float duration){
    sound *silence = (sound*)malloc(sizeof(sound));
    silence->rate = sample_rate;
    silence->length = sample_rate * duration;
    silence->samples = (float*)malloc(sizeof(float)*sample_rate * duration);
    for(int i = 0; i < sample_rate  * duration; i++) {
        silence->samples[i] = 0;
    }
    return silence;
}

// int outputSound(sound *s, FILE *f) {
//
//     // File doesn't exist
//     if(f == NULL)
//         return 1;
//
//     for(int i=0; i<s->length;i++)
//         fprintf(f, "%f\n", s->samples[i]);
//
//     return 0;
// }

/*
 A function that will compute a specific hertz square sound tone and then stores it in a sound pointer samples array member.
 This method will be use for testing.
 */
sound *genSquare( float hertz, float sample_rate, float duration){
  sound *square = (sound*)malloc(sizeof(sound));
  square->rate = sample_rate;
  square->length = sample_rate * duration;
  square->samples = (float*)malloc(sizeof(float)*sample_rate * duration);
  for(int i = 0; i < sample_rate  * duration; i++) {
    square->samples[i] = 2*(2*floor(hertz * i / sample_rate)-floor(2* hertz * i / sample_rate))+1;
  }
  return square;
}

/*
 A function that will compute a specific hertz triangle sound tone and then stores it in a sound pointer samples array member.
 This method will be use for testing.
 */
sound *genTriangle( float hertz, float sample_rate, float duration){
  sound *triangle = (sound*)malloc(sizeof(sound));
  triangle->rate = sample_rate;
  triangle->length = sample_rate * duration;
  triangle->samples = (float*)malloc(sizeof(float)*sample_rate * duration);
  for(int i = 0; i < sample_rate  * duration; i++) {
    triangle->samples[i] = 2*(fabs(2*((i *hertz/sample_rate)-floor(0.5 + (i *hertz/sample_rate)))))-1;
  }
  return triangle;
}

/*
 A function that will compute a specific hertz sawtooth sound tone and then stores it in a sound pointer samples array member.
 This method will be use for testing.
 */
sound *genSawtooth( float hertz, float sample_rate, float duration){
  sound *sawTooth = (sound*)malloc(sizeof(sound));
  sawTooth->rate = sample_rate;
  sawTooth->length = sample_rate * duration;
  sawTooth->samples = (float*)malloc(sizeof(float)*sample_rate * duration);
  for(int i = 0; i < sample_rate  * duration; i++) {
    sawTooth->samples[i] = 2*((i *hertz/sample_rate)-floor(0.5 + (i *hertz/sample_rate)));
  }
  return sawTooth;
}
