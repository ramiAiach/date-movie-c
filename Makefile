
CC=gcc
CFLAGS=-Wall -std=c99 -g
LDFLAGS=-g
TARGET=test_date_movie

all: $(TARGET)

$(TARGET): main.o date.o movie.o
	$(CC) $(LDFLAGS) $^ -o $@ 
main.o movie.o : movie.h date.h
date.o : date.h

%.o : %.c	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o
mrproper: clean
	rm -f $(TARGET)
