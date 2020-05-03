SHELL = /bin/sh

OBJS =  bubble_sort.cpp
OUT = bubble_sort
CFLAG = -Wall -g
CC = g++
STD = -std=c++11
INCLUDE =
LIBS = 
BUILD = 
MKDIR_P = mkdir -p

all:bubble_sort

directory:${BUILD}

${BUILD}:
	${MKDIR_P} ${BUILD}

bubble_sort:${OBJ}
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}${OUT} ${OBJS} ${LIBS}

clean:
	-rm -rf *.o ${OUT} 
