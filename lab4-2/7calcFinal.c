/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>

void calcFinal(Node **list_head_ptr, char *CategoryNames,int *size) {
    // go through list
    Node *traverse_ptr = *list_head_ptr;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		//array of Cumulative scores
		float scores[] ={traverse_ptr->Student.Cat1.Cumulative,
		traverse_ptr->Student.Cat2.Cumulative,
		traverse_ptr->Student.Cat3.Cumulative,
		traverse_ptr->Student.Cat4.Cumulative};
		//set to zero if any Cumulative's are -1
		for(int i = 0; i < 3; i++){
		    if(scores[i] == -1){
		       scores[i] == 0;
		    }
		    
		}
		//calcFinal
		traverse_ptr->Student.Final_Grade = scores[0]*0.15 + scores[1]*0.30 + scores[2]*0.20 + scores[3]*0.35;
		//next Student
		traverse_ptr = traverse_ptr->next;
		
		}
		//print when done
		printAll(list_head_ptr,CategoryNames,size);
	}
}	