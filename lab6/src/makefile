CC=gcc
CFLAGS=-I.

all : MultModulo.c server.c client.c
	gcc -c MultModulo.c -o MultModulo.o
	gcc -shared MultModulo.o -o libMultModulo.so
	gcc server.c -L. -lMultModulo -lpthread -o server
	gcc client.c -L. -lMultModulo -lpthread -o client

clean :
	rm factor.o libMultModulo.so server client