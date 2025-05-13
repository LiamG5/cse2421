# BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
#THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
#THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
#INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
#TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
# comments in a Makefile start with sharp 

# target all means all targets currently defined in this file
all: lab4.zip lab4 

# this target is the .zip file
lab4.zip: Makefile lab4main.c readFile.c createNode.c insertById.c printNa.c printHeader.c 1printById.c 2printByName.c 3printAll.c 4updateScore.c 5updateAll.c 6newScore.c 7calcFinal.c 8addStudent.c 9delete.c 10writeFile.c lab4.h
	zip lab4.zip Makefile *.c lab4.h

# compile the program 
lab4: lab4main.c readFile.c createNode.c insertById.c printNa.c printHeader.c 1printById.c 2printByName.c 3printAll.c 4updateScore.c 5updateAll.c 6newScore.c 7calcFinal.c 8addStudent.c 9delete.c 10writeFile.c lab4.h
	gcc -std=c99 -pedantic -g *.c -o lab4 

# run the program with two command-li
run:
	./lab4 filename1 filename2

# this target deletes all files produced from the Makefile
clean:
	rm -rf *.o lab4 lab4.zip
