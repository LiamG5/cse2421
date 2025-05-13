# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
#THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
#THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
#INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
#TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab6 lab6.zip 

# this target is the .zip file
lab6.zip: Makefile lab6main.c lab6.s
	zip lab6.zip Makefile lab6main.c lab6.s

# compile the program 
lab6: lab6main.c lab6.s 
	gcc lab6.s lab6main.c -o lab6 

# run the program 
run:
	./lab6 

# this target deletes all files produced from the Makefile
clean:
	rm -rf *.o lab6 lab6.zip
