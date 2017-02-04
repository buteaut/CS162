# Makefile for CS162 projects
# Author: Thomas Buteau
# # Date: 1-29-17
CC = gcc
CXX = g++
CFLAGS = -std=c99
CXXFLAGS = -std=c++0x
LDFLAGS = 
#Optional additions
#CXXFLAGS += -g
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors

OBJS = main.o Game.o Die.o LoadedDie.o integerValidation.o

SRCS = main.cpp Game.cpp Die.cpp LoadedDie.cpp integerValidation.cpp

HEADERS = Game.hpp Die.hpp LoadedDie.hpp integerValidation.hpp

EXEC = "Lab3"

#all: Lab3

LAB3: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

