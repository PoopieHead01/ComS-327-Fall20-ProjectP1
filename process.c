#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "process.h"

/*
 A method that mix two sounds together with sound weights correspond to the sound array.
 Returns a single finished mixed sound structs.
 */
sound* mix(sound *s[],float w[], int c){
  int longestLength = 0;
  float rate = 0;
  for(int i = 0; i < c; i++){
    if(s[i]->length > longestLength)
      longestLength = s[i]->length;
      rate = s[i]->rate;
  }
  if(longestLength == 0){
    return NULL;
  }
  sound *mix = (sound*)malloc(sizeof(sound));
  mix->rate = rate;
  mix->length = longestLength;
  mix->samples = (float *)malloc(sizeof(float)*longestLength);
  for(int i = 0; i < longestLength; i++) {
    mix->samples[i] = 0;
  }
  for(int i = 0; i < c; i++) {
    for (int j = 0; j < s[i]->length; j++) {
      mix->samples[j] += s[i]->samples[j]*w[i];
    }
  }
  return mix;
}

/*
 A method that just multiply point by point two sound signals together.
 Returns a single finished modulated sound.
 */
sound* modulate(sound *s1, sound *s2){
  if(s1->length != s2->length){
    return NULL;
  }
  sound *modulate = (sound*)malloc(sizeof(sound));
  modulate->rate = s1->rate;
  modulate->length = s1->length;
  modulate->samples = (float *)malloc(sizeof(float)*s1->length);
  for(int i = 0; i < s1->length; i++) {
    modulate->samples[i] = s1->samples[i] * s2->samples[i];
  }
  return modulate;
}

/*
 A method that does convolution by summing samples by real numbers.
 Returns a single filtered sound.
 */
sound* filter(sound *s, float fir[], int c){
  if(s->length == 0){
    return NULL;
  }
  sound *filter = (sound*)malloc(sizeof(sound));
  filter->rate = s->rate;
  filter->length = s->length;
  filter->samples = (float *)malloc(sizeof(float)*s->length);
  for(int i = 0; i < s->length; i++) {
    filter->samples[i] = 0;
  }
  for(int i = 0; i < s->length; i++){
    for (int j = 0; j < c; j++){
        if(i-j >= 0){
        filter->samples[i] += s->samples[i-j]*fir[j];
        }
    }
  }
    return filter;
}

/*
 This function calculates the fir array that is to be pass to the filter method that is to be process.
 The delay and the attenuation are use for calculating the fir array.
 It returns a sound array that has been filtered.
 */
sound* reverb(sound *s, float delay, float attenuation){
  if(attenuation >= 1 || attenuation <= 0){
    return NULL;
  }
  if(delay <= 0 || delay >= 0.1){
    return NULL;
  }
  if (s == NULL) {
    return NULL;
  }
  int firArraySize = s->rate * delay;
  float *fir = (float*)malloc(sizeof(float)*firArraySize);
  for(int i = 0; i < firArraySize; i++){
    if (i == 0) {
      fir[i] = 1;
    }
    else if(i == firArraySize - 1){
      fir[i] = attenuation;
    }
    else if(i != 0 || i != firArraySize - 1){
      fir[i] = 0;
    }
  }
  sound *reverb = filter(s, fir, firArraySize);
  free(fir);
  return reverb;
}

/*
 This is somewhat a similar function to reverb but it is using O(n) by processing the the sound in the method directly.
 Returns a pointer sound that has been process.
 */
sound* echo(sound *s, float delay, float attenuation){
    if(attenuation >= 1 || attenuation <= 0){
      return NULL;
    }
    if(delay < 0.1 || delay > 1){
      return NULL;
    }
    if (s == NULL) {
      return NULL;
    }
        int firArraySize = s->rate * delay;
        sound *echo = (sound*)malloc(sizeof(sound));
        echo->rate = s->rate;
        echo->length = s->length;
        echo->samples = (float *)malloc(sizeof(float)*s->length);
        for(int i = 0; i < s->length; i++) {
          echo->samples[i] = 0;
        }
        for(int i = 0; i < s->length; i++){
          if(i-(firArraySize - 1) >= 0){
              echo->samples[i] = s->samples[i] + s->samples[i-(firArraySize - 1)] * attenuation;
          }
          else{
              echo->samples[i] = s->samples[i];
          }
        }
    return echo;
}
