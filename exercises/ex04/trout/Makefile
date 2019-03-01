trout: trout.o util.o main.o
	gcc trout.o util.o main.o -o trout -Wall

trout.o: trout.c trout.h util.h
	gcc -c trout.c -Wall

util.o: util.c trout.h util.h
	gcc -c util.c -Wall

main.o: main.c trout.h util.h
	gcc -c main.c -Wall
