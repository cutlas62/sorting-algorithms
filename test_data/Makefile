SHELL = /bin/sh

OBJS =  randomness_generator.cpp
OUT = random
CFLAG = -Wall -g
CC = g++
STD = -std=c++11
INCLUDE =
LIBS = 
BUILD = 
MKDIR_P = mkdir -p

all:random

directory:${BUILD}

${BUILD}:
	${MKDIR_P} ${BUILD}

random:${OBJ}
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}${OUT} ${OBJS} ${LIBS}

clean:
	-rm -rf *.o ${OUT} 

clean-all:
	-rm -rf *.o ${OUT} generated