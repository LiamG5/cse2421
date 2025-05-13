/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>
#include<string.h>


void printById(Node **list_head_ptr, int idNum, char *CategoryNames) {
    
	Node *traverse_ptr = *list_head_ptr;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		    if(traverse_ptr->Student.student_ID == idNum){
		    printf("Id Found");
		    printHeader(CategoryNames);
		    //formating
		    if(strlen(traverse_ptr->Student.student_name) < 16){
		    printf("%s        \t",traverse_ptr->Student.student_name);
		    }else{
			printf("%s\t",traverse_ptr->Student.student_name);
		    }
		    //id
			printf("%d\t",traverse_ptr->Student.student_ID);
			//scores go through printNa whichs subs out the -1 for N/a
			printNa(traverse_ptr->Student.Cat1.score1);
			printNa(traverse_ptr->Student.Cat1.score2);
			printNa(traverse_ptr->Student.Cat1.score3);
			printNa(traverse_ptr->Student.Cat1.Cumulative);
			
			
			printNa(traverse_ptr->Student.Cat2.score1);
			printNa(traverse_ptr->Student.Cat2.score2);
			printNa(traverse_ptr->Student.Cat2.score3);
            printNa(traverse_ptr->Student.Cat2.Cumulative);
            
			printNa(traverse_ptr->Student.Cat3.score1);
			printNa(traverse_ptr->Student.Cat3.score2);
			printNa(traverse_ptr->Student.Cat3.score3);
			printNa(traverse_ptr->Student.Cat3.Cumulative);

			printNa(traverse_ptr->Student.Cat4.score1);
			printNa(traverse_ptr->Student.Cat4.score2);
			printNa(traverse_ptr->Student.Cat4.score3);
			printNa(traverse_ptr->Student.Cat4.Cumulative);
			printNa(traverse_ptr->Student.Current_Grade);
			printNa(traverse_ptr->Student.Final_Grade);
			
			printf("\n");
		    }
			traverse_ptr = traverse_ptr ->next;
		}
	}




}