/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include <stdio.h>


int main(int argc, char *argv[])
{
	char *fileIn = argv[1];
	printf("Reading student information from file \"%s\"\n",fileIn);
	char *fileOut = argv[2];
	char CategoryNames[90];
    int size;

	Node *head = NULL;
	
	size = readFile(&head, fileIn, CategoryNames, &size);
	printf("A total of %d student records were read from the file %s\n", size,fileIn);
	int choice = 0;
	int on = 1;
	int idNum;
	while(on) {
		printf("Please enter an option between 1 and 10:\n1) Print Student Scores by Student ID\n");
		printf("2) Print Student Scores by Last Name\n3) Print Student Scores for All Students\n");
		printf("4) Recalculate Student Scores for a Single Student ID\n5) Recalculate All Student Scores\n");
		printf("6) Insert a score for a specific Student ID\n7) Calculate Final Grades\n");
		printf("8) Add a new student\n9) Delete a student\n10) Exit Program\n:");

		scanf("%d", &choice);
		switch(choice)
		{
		case 1:
		    //moved from printById to let printByLastName use
		    printf("ID to print: ");
            scanf("%d",&idNum);
            printf("Hunting for ID\n");
		    printById(&head,idNum,CategoryNames);
			break;
		case 2:
            printByLastName(&head,CategoryNames, &size);
			break;
		case 3:
			printAll(&head,CategoryNames, &size);
			break;
		case 4:
		    //
		    printf("ID to update: ");
            scanf("%d",&idNum);
            printf("Hunting for ID\n");
            updateScoreById(&head,idNum,CategoryNames);
			break;
		case 5:
		    updateAll(&head,CategoryNames);
			break;
		case 6:
            insertScore(&head, CategoryNames);
			break;
		case 7:
		    calcFinal(&head,CategoryNames, &size);
			break;
		case 8:
            addStudent(&head, CategoryNames);
			break;
		case 9:
		    delete(&head, CategoryNames);
			break;
		case 10://all cases 
		    writeFile(&head, fileOut,CategoryNames);
			on = 0;
			break;
		default:
		    writeFile(&head, fileOut,CategoryNames);
		    on = 0;
			break;
		}

	}
	return 0;
}
