# Makefile for CS162 projects
# Author: Thomas Buteau
# # Date: 2-12-17
CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x
LDFLAGS = 
#Optional additions
#CXXFLAGS += -g
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = recArrSum.o recString.o recTriNum.o  main.o menu.o dataValidation.o dynArr.o

SRCS = recArrSum.cpp recString.cpp recTriNum.cpp  main.cpp menu.cpp dataValidation.cpp dynArr.cpp

HEADERS = recArrSum.hpp recString.hpp recTriNum.hpp menu.hpp dataValidation.hpp dynArr.hpp

EXEC = "Lab5"

#all: Lab3

Lab5: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

