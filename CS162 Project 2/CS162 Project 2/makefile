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

OBJS = Main.o List.o Item.o dataValidation.o

SRCS = Main.cpp List.cpp Item.cpp dataValidation.cpp

HEADERS = List.hpp Item.hpp dataValidation.hpp

EXEC = "Project2"

#all: Lab3

PROJECT2: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

