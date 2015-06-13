#This is a Makefile for Kindergarten
CCC=g++
CXXFLAGS=-Wall -g
CXXLINK=$(CCC)
OBJS=main.o Child.o Class.o Office.o Person.o Room.o Teacher.o
RM=rm -f

#Default target (usually "all")
all: Kindergarten

#Creating the executables
Kindergarten:$(OBJS)
	$(CXXLINK) -o Kindergarten $(OBJS)  


#Creating object files using default rules
Person.o: Person.C Person.H 
Child.o: Child.C Child.H Person.H defs.H
Teacher.o: Teacher.C Teacher.H  Person.H
Room.o: Room.C Room.H defs.H 
Class.o: Class.C Class.H defs.H Room.H Child.H Teacher.H
Office..o: Office.C Office.H Room.H defs.H Class.H
main.o: main.C Office.H Class.H Child.H Teacher.H

#Cleaning old files before new make
clean:  
	$(RM) Kindergarten *.o *.bak *~ "#"* core
