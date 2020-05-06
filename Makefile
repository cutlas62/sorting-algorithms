SHELL = /bin/sh

OBJS = 	main.cpp \
		utils.cpp \
		bitonic_sort/bitonic_sort.cpp \
		bubble_sort/bubble_sort.cpp \
		cocktail_shaker_sort/cocktail_shaker_sort.cpp \
		gcc_std_sort/gcc_std_sort.cpp \
		gnome_sort/gnome_sort.cpp \
		heap_sort/heap_sort.cpp \
		merge_sort/merge_sort.cpp \
		radix_sort/radix_sort.cpp \
		shell_sort/shell_sort.cpp \
		gcc_std_stable_sort/gcc_std_stable_sort.cpp \
		gravity_sort/gravity_sort.cpp \
		insertion_sort/insertion_sort.cpp \
		quick_sort/quick_sort.cpp \
		selection_sort/selection_sort.cpp
CFLAG = -Wall -g
CC = g++
STD = -std=c++11
INCLUDE =
LIBS = 
BUILD = 
MKDIR_P = mkdir -p

all:main

directory:${BUILD}

${BUILD}:
	${MKDIR_P} ${BUILD}

main:${OBJ}
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}$@ ${OBJS} ${LIBS}

generator:
	${CC} ${STD} ${CFLAG} ${INCLUDE} -o ${BUILD}test_data_generator test_data_generator.cpp ${LIBS}

clean:
	-rm -rf *.o main test_data_generator

distclean:
	-rm -rf *.o ${OUT} main test_data_generator test_data/