#ifndef GENSND_H
#define GENSND_H

#include "sound.h"
#include "iosnd.h"
#include "math.h"

// void gensine(float frequency, float sampleRate, float duration);
//
// void DTMF(float freq1, float freq2);
//
// void phone_pad(char ch);
//
// void make_silence(float sampleRate, float duration);

sound *gensine( float hertz, float sample_rate, float duration);

sound *genDTMF(char key, float sample_rate, float duration);

sound *genSilence(float sample_rate, float duration);

// int outputSound( sound *s, FILE *f);
//=====================Part c===================================
sound * genSquare( float hertz, float sample_rate, float duration);

sound * genTriangle( float hertz, float sample_rate, float duration);

sound * genSawtooth( float hertz, float sample_rate, float duration);

#endif
