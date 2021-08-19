OBJS	= main.o functions.o
SOURCE	= main.c functions.c
HEADER	= functions.h
OUT	= calculator
CC	 = gcc
FLAGS	 = -g -c -Wall -lm
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) -lm

main.o: main.c
	$(CC) $(FLAGS) main.c 

functions.o: functions.c
	$(CC) $(FLAGS) functions.c 


clean:
	rm -f $(OBJS) $(OUT)
