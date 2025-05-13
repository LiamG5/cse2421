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

void writeFile(Node **list_head_ptr, char *fileOut, char *CategoryNames) {
    //opens file
	FILE *f = fopen(fileOut, "w");

	if (f == NULL) {
		printf("Failed to open file!\n");
		return;
	}
    //prints CategoryNames
	fprintf(f,"%s %s %s %s \n", CategoryNames,(char*)CategoryNames+15,(char *)CategoryNames+30,(char *)CategoryNames+45);
	//go through list
	Node *prev_ptr = *list_head_ptr;
	Node *traverse_ptr = prev_ptr->next;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		    //print everything to file
			fputs(prev_ptr->Student.student_name, f);
			fprintf(f,"\n");
			fprintf(f,"%d",prev_ptr->Student.student_ID);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat1.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat1.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat1.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat2.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat2.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat2.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat3.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat3.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat3.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat4.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat4.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat4.score3);
			fprintf(f,"\n");
			//free printed node then set it to next node
			free(prev_ptr);
			prev_ptr = traverse_ptr;
			traverse_ptr = traverse_ptr->next;

		}
		//once more because loop termiantes early
		    fputs(prev_ptr->Student.student_name, f);
			fprintf(f,"\n");
			fprintf(f,"%d",prev_ptr->Student.student_ID);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat1.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat1.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat1.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat2.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat2.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat2.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat3.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat3.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat3.score3);
			fprintf(f,"\n");
			fprintf(f,"%.2f ",prev_ptr->Student.Cat4.score1);
			fprintf(f,"%.2f ",prev_ptr->Student.Cat4.score2);
			fprintf(f,"%.2f",prev_ptr->Student.Cat4.score3);
			fprintf(f,"\n");
		//free last node
        free(prev_ptr);

	}

}