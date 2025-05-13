/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>
#include<string.h>

void addStudent(Node **list_head_ptr, char *CategoryNames) {
	printf("Enter the Student's Name:");
	char name[60];
	
	//flush input stream
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	//get
    fgets(name,sizeof(name),stdin);
    //remove \n
    name[strcspn(name, "\n")] = '\0';
    //gets id num
	printf("Enter the Student's ID Number: ");
	int ID;
	int loop = 1;
	float scores[4][3];
	scanf("%d", &ID);

//look for duplicate id, only one to check because its the only to cause problems
	Node *traverse_ptr = *list_head_ptr;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
			if(traverse_ptr->Student.student_ID == ID) {
				printf("Student ID Number entered was a duplicate.\n");
				printf("Enter the Student's ID Number: ");
				scanf("%d", &ID);
				//restart if new id isn't found
				traverse_ptr = *list_head_ptr;
			}
			traverse_ptr = traverse_ptr->next;
		}

	}
    //get scores
	printf("Enter first %s score (use -1 if there is no score): ",CategoryNames);
	scanf("%f", &scores[0][0]);
	printf("Enter second %s score (use -1 if there is no score): ",CategoryNames);
	scanf("%f", &scores[0][1]);
	printf("Enter third %s score (use -1 if there is no score): ",CategoryNames);
	scanf("%f", &scores[0][2]);

	printf("Enter first %s score (use -1 if there is no score): ",(char *)CategoryNames+15);
	scanf("%f", &scores[1][0]);
	printf("Enter second %s score (use -1 if there is no score): ",(char *)CategoryNames+15);
	scanf("%f", &scores[1][1]);
	printf("Enter third %s score (use -1 if there is no score): ",(char *)CategoryNames+15);
	scanf("%f", &scores[1][2]);

	printf("Enter first %s score (use -1 if there is no score): ",(char *)CategoryNames+30);
	scanf("%f", &scores[2][0]);
	printf("Enter second %s score (use -1 if there is no score): ",(char *)CategoryNames+30);
	scanf("%f", &scores[2][1]);
	printf("Enter third %s score (use -1 if there is no score): ",(char *)CategoryNames+30);
	scanf("%f", &scores[2][2]);
	printf("Enter first %s score (use -1 if there is no score): ",(char *)CategoryNames+45);
	scanf("%f", &scores[3][0]);
	printf("Enter second %s score (use -1 if there is no score): ",(char *)CategoryNames+45);
	scanf("%f", &scores[3][1]);
	printf("Enter third %s score (use -1 if there is no score): ",(char *)CategoryNames+45);
	scanf("%f", &scores[3][2]);
    //create, insert, and print node with new data
	Node *n = createNode(name, ID, scores);
	insertById(list_head_ptr, n);
	printById(list_head_ptr,ID, CategoryNames);




}