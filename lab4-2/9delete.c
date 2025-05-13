/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>
#include<stdlib.h>

void delete(Node **list_head_ptr,char *CategoryNames) {
	printf("Please enter the student ID number you wish to delete, followed by enter.");
	int id;
	int choice;
	scanf("%d",&id);

	if(*list_head_ptr != NULL) {
		// check first
		Node *prev_ptr = *list_head_ptr;
		if(prev_ptr->Student.student_ID == id) {
			printf("do you really want to delete student ID number %d, %s\n",prev_ptr->Student.student_ID, prev_ptr->Student.student_name);
			printf("If yes, enter 1. If no, enter 2: ");
			scanf("%d",&choice);
			if(choice == 1) {
				*list_head_ptr = prev_ptr -> next;
				free(prev_ptr);
			}
		} else {//check the rest
			
			Node *traverse_ptr =  prev_ptr -> next;
			while(traverse_ptr != NULL) {
				if(traverse_ptr->Student.student_ID == id) {
					printf("do you really want to delete student ID number %d, %s\n",traverse_ptr->Student.student_ID, traverse_ptr->Student.student_name);
					printf("If yes, enter 1. If no, enter 2: ");
					scanf("%d",&choice);
					if(choice == 1) {
					    //removes node from line and frees
						prev_ptr -> next = traverse_ptr-> next;
						free(traverse_ptr);
					}
					break;
				}
				//next
				traverse_ptr = traverse_ptr -> next;
				prev_ptr = prev_ptr -> next;
			}
		}

	}

}


