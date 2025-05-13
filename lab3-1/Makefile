# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab3.zip lab3

# this target is the .zip file that must be submitted to Carmen
lab3.zip: Makefile lab3.c lab3.h
	zip lab3.zip Makefile lab3.c lab3.h

# runs lab 3
run_lab3: lab3.c lab3.h
	gcc -std=c99 -pedantic lab3.c -o lab3 

# this target deletes all files produced from the Makefile
# so that a completely new compile of all items is required
clean:
	rm -rf *.o  lab3.zip run_lab3
