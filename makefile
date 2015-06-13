#makefile for creating the executable

#Linking
prog: main.o list.o graph.o
	gcc -o prog main.o list.o graph.o -L/usr/local/lib/ -lm

#Compiling list.c
list.o: list.c list.h
	gcc -c -g -Wall list.c

#Compiling graph.c
graph.o: graph.c graph.h
	gcc -c -g -Wall graph.c -L/usr/local/lib/ -lm

#Compiling main.c
main.o: main.c list.h graph.h
	gcc -c -g -Wall main.c


clean:
	rm -f prog screen_test *.o *.bak *~ "#"* core
 
