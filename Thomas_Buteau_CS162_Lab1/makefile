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

OBJS = Lab1Main.o determinant.o readMatrix.o

SRCS = Lab1Main.cpp determinant.cpp readMatrix.cpp

HEADERS = determinant.hpp readMatrix.hpp

EXEC = "Lab1"

all: Lab1

Lab1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out

cleanall:
	rm -f ${OBJS} a.out ${EXEC}
