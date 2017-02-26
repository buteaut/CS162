# Makefile for CS162 projects
# Author: Thomas Buteau
# Date: 2-26-17
CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x
LDFLAGS = 
#Optional additions
#CXXFLAGS += -g
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = Queue.o menu.o dataValidation.o main.o

SRCS = Queue.cpp menu.cpp dataValidation.cpp main.cpp

HEADERS = Queue.hpp menu.hpp dataValidation.hpp

EXEC = "Lab7"

#all: Lab3

Lab6: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

