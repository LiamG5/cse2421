/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/
#include"lab4.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void printByLastName(Node **list_head_ptr, char *CategoryNames, int *size){
    printf("Enter the Student's Last Name:\n");
    char name[60];
    //flush input stream
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	//get
    fgets(name,sizeof(name),stdin);
    //remove \n
    name[strcspn(name, "\n")] = '\0';
    int choice;
    Node *traverse_ptr = *list_head_ptr;
    if(traverse_ptr != NULL) {
        int numOfHits = 0;
        //dont know how many hits we'll get, so using size of the list will work 
        int *hits = (int *)calloc(sizeof(int), *size);
        //go through list to find names that match given keyword
		while(traverse_ptr != NULL) {
            if(strstr(traverse_ptr->Student.student_name, name)!=NULL){
            hits[numOfHits++]= traverse_ptr->Student.student_ID;
            }
		    traverse_ptr = traverse_ptr ->next;
		}
		// go ahead if one name found, check with user if more, exit if none
		if(numOfHits == 1){
		printf("One name found\n"); 
		printById(list_head_ptr,hits[0], CategoryNames);
		}else if(numOfHits > 1){
		numOfHits = 0;
		traverse_ptr = *list_head_ptr;
		printf("There is more than one student by that name.\n"); 
		//print all names
		while(traverse_ptr != NULL) {
            if(strstr(traverse_ptr->Student.student_name, name)!=NULL){
            printf("%d) %s\n",(numOfHits++ + 1),traverse_ptr->Student.student_name);
            }
		    traverse_ptr = traverse_ptr ->next;
		}
		printf("Please indicate which student you want: ");
		scanf("%d",&choice);
		printById(list_head_ptr,hits[choice - 1], CategoryNames);
  
		}else{
		    printf("No name found\n");
		}
	    
		free(hits);
	}


}