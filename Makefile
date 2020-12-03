all: parta partb partc

parta: main main2

partb: main1b

partc: playsong


main: main.o gensnd.o
	gcc -o gensine main.o gensnd.o -lm

main.o: main.c gensnd.h
	gcc -c main.c

main2: main2.o gensnd.o
	gcc -o gendial main2.o gensnd.o -lm

main2.o: main2.c gensnd.h
	gcc -c main2.c

main1b: main1b.o gensnd.o iosnd.o
	gcc -o dtmf main1b.o gensnd.o iosnd.o -lm

playsong: playsong.o gensnd.o process.o
	gcc -o playsong playsong.o gensnd.o process.o -lm

playsong.o: gensnd.h playsong.c process.h
	gcc -c playsong.c

main1b.o: gensnd.h main1b.c
	gcc -c main1b.c

gensnd.o: gensnd.h gensnd.c iosnd.h
	gcc -c gensnd.c 

iosnd.o: iosnd.h iosnd.c
	gcc -c iosnd.c

process.o: process.h process.c
	gcc -c process.c

clean:
	rm -f gensine gendial dtmf playsong *.o
