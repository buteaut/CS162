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

OBJS = building.o instructor.o person.o student.o university.o main.o dataValidation.o 

SRCS = building.cpp instructor.cpp person.cpp student.cpp university.cpp  main.cpp dataValidation.cpp

HEADERS = building.hpp instructor.hpp person.hpp student.hpp university.hpp dataValidation.hpp

EXEC = "Lab4"

#all: Lab3

Lab4: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${EXEC}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -f ${OBJS} a.out ${EXEC}

