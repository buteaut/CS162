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

OBJS = barbarian.o battle.o blueMen.o fighter.o harryPotter.o medusa.o vampire.o main.o dataValidation.o

SRCS = barbarian.cpp battle.cpp blueMen.cpp fighter.cpp harryPotter.cpp medusa.cpp vampire.cpp main.cpp dataValidation.cpp

HEADERS = barbarian.hpp battle.hpp blueMen.hpp fighter.hpp harryPotter.hpp medusa.hpp vampire.hpp dataValidation.hpp

EXEC = "Project3"

#all: Lab3

PROJECT3: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

