# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
 
# ****************************************************
# Targets needed to bring the executable up to date
main: ass5.o
	$(CC) -o main ass5.o
 
# The main.o target can be written more simply
 
ass5.o: ass5.cpp Customer.h Queue.h QueueADT.h Simulation.h
	$(CC) -c ass5.cpp

clean:
	rm -vf *.o *.exe *.obj *.pdb *.ilk