# Digital Sound

Sound is simply a wave transmitted through the atmospherethrough changing pressure. To generate a sound wave, we can use a speaker to vibrate which in turn compresses and decompresses the air around it.  Done repeatedly, it produces the changesin pressure that we perceiveas sound. 

### Table of Usage Contents

- [Part 1a](##Part-1a)
- [Part 1b](##Part-1b)
- [Part 1c](##Part-1c)
- [DTMF Reference](###DTMF)

### Usage

Clone the repository. There are **4** executables, gensine, gendial, dtmf, playsong. 

```sh
$ make 
```

```sh
$ make parta
```

```sh
$ make partb
```
```sh
$ make partc
```
## Part 1a

**For gensine,**

```sh
$ ./gensine
```

The program then will ask you to enter frequency, sample rate, and duration.

**For gendial,** 

```sh
$ ./gendial
```

The program then will ask you to enter a 10-digit number.

## Part 1b

**For main1b,**

```sh
$ ./main1b <phone_pad_symbols> 
```

It will print the values on the console.

**OR**

```sh
$ ./main1b <phone_pad_symbols> <output_file_name>
```

It will print the values to the output file.

**OR**

```sh
$ ./main1b
```
It will show a usage message on how to run the program.

**Examples of valid command lines to run the program are:**
```sh
dtmf 5551212 output.wav

dtmf 5551212

dtmf 5aa553\* output2.wav

dtmf
```
## Part 1c

**For playsong,**

```sh
$ ./playsong <mysong.txt> <songsound.txt>
```

<mysong.txt> will be the input sound file 

<songsound.txt> will be the output song sound file

### DTMF

DTMF stands for Dual-Tone Multi-Frequency and is most commonly used in telephone dialing and signaling. The frequencies are as of below:

|        | 1209 Hz | 1336 Hz | 1477 Hz | 1633 Hz |
| ------ | :-----: | :-----: | :-----: | :-----: |
| 697 Hz |    1    |    2    |    3    |    A    |
| 770 Hz |    4    |    5    |    6    |    B    |
| 852 Hz |    7    |    8    |    9    |    C    |
| 941 Hz |    *    |    0    |    #    |    D    |

### Extra 
Additional information will be the developer's file
