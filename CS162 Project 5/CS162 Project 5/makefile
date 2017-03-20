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

OBJS = comroom.o engine.o engineering.o hallway.o intersection.o maintenance.o game.o entrance.o rooms.o  dataValidation.o main.o

SRCS = *.cpp

HEADERS = *.hpp

EXEC = "Project5"

#all: Lab3

Program: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

