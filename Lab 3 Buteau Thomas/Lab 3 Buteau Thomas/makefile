# Makefile for CS162 projects
# Author: Thomas Buteau
# Date: 1-14-17
CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x
LDFLAGS = 
#Optional additions
#CXXFLAGS += -g
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = main.o Ant.o Board.o menu.o integerValidation.o

SRCS = main.cpp Ant.cpp Board.cpp menu.cpp integerValidation.cpp

HEADERS = Ant.hpp board.hpp menu.hpp integerValidation.hpp

EXEC = "Assignment1"

all: Assignment1

Assignment1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out

cleanall:
	rm -f ${OBJS} a.out ${EXEC}
