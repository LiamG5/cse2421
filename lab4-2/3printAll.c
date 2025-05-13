/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/
#include"lab4.h"
#include<stdio.h>
#include<string.h>


void printAll(Node **list_head_ptr,char *CategoryNames, int *size) {
    printHeader(CategoryNames);
	Node *traverse_ptr = *list_head_ptr;
	//cats
	float CatAvg1 = 0.0;
    float CatAvg2 = 0.0;
    float CatAvg3 = 0.0;
    float CatAvg4 = 0.0;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		    //to get everything to line up
		    if(strlen(traverse_ptr->Student.student_name) < 16){
		    printf("%s        \t",traverse_ptr->Student.student_name);
		    }else{
			printf("%s\t",traverse_ptr->Student.student_name);
		    }
			printf("%d\t",traverse_ptr->Student.student_ID);
			printNa(traverse_ptr->Student.Cat1.score1);
			printNa(traverse_ptr->Student.Cat1.score2);
			printNa(traverse_ptr->Student.Cat1.score3);
			printNa(traverse_ptr->Student.Cat1.Cumulative);
			CatAvg1 = CatAvg1 + traverse_ptr->Student.Cat1.Cumulative;
			
			printNa(traverse_ptr->Student.Cat2.score1);
			printNa(traverse_ptr->Student.Cat2.score2);
			printNa(traverse_ptr->Student.Cat2.score3);
            printNa(traverse_ptr->Student.Cat2.Cumulative);
            CatAvg2 = CatAvg2 + traverse_ptr->Student.Cat2.Cumulative;
            
			printNa(traverse_ptr->Student.Cat3.score1);
			printNa(traverse_ptr->Student.Cat3.score2);
			printNa(traverse_ptr->Student.Cat3.score3);
			printNa(traverse_ptr->Student.Cat3.Cumulative);
			CatAvg3 = CatAvg3 + traverse_ptr->Student.Cat3.Cumulative;

			printNa(traverse_ptr->Student.Cat4.score1);
			printNa(traverse_ptr->Student.Cat4.score2);
			printNa(traverse_ptr->Student.Cat4.score3);
			printNa(traverse_ptr->Student.Cat4.Cumulative);
			CatAvg4 = CatAvg4 + traverse_ptr->Student.Cat4.Cumulative;
			
			printNa(traverse_ptr->Student.Current_Grade);
			printNa(traverse_ptr->Student.Final_Grade);
			
			printf("\n");
			traverse_ptr = traverse_ptr ->next;
		}
		CatAvg1 = CatAvg1/(*size);
		CatAvg2 = CatAvg2/(*size);
		CatAvg3 = CatAvg3/(*size);
		CatAvg4 = CatAvg4/(*size);
		
		
		printf("Class Averages for %s : %.2f, %s : %.2f, %s : %.2f, %s : %.2f\n", 
		CategoryNames,CatAvg1,(char*)CategoryNames+15,CatAvg2,(char *)CategoryNames+30,CatAvg3,(char *)CategoryNames+45,CatAvg4);
	}




}