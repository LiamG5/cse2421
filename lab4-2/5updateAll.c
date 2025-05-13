/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/


#include "lab4.h"
#include <stdio.h>
#include <string.h>


void updateAll(Node **list_head_ptr, char *CategoryNames) {
    //go through list
	Node *traverse_ptr = *list_head_ptr;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		    //format names
            printf("Student name: ");
			if(strlen(traverse_ptr->Student.student_name)  <18) {
				printf("%s\t\t",traverse_ptr->Student.student_name);
			} else {
				printf("%s\t",traverse_ptr->Student.student_name);
			}
			//get new scores
			float scores[4][3];

			scores[0][0] = traverse_ptr->Student.Cat1.score1;
			scores[0][1] = traverse_ptr->Student.Cat1.score2;
			scores[0][2] = traverse_ptr->Student.Cat1.score3;
			// all loops are to calc Cumulative and total scores
			float tot1 = 0;
			int j = 0;
			for(int i = 0; i < 3; i++) {
				// count what to divid by
				if(scores[0][i] != -1) {
					j++;
					tot1 +=scores[0][i];
				}

			}
			if(j!= 0) {
				traverse_ptr->Student.Cat1.Cumulative = (tot1/(float)j);
			} else {
				traverse_ptr->Student.Cat1.Cumulative = -1;
			}
			printf("%s Cumlative: %.2f\t",CategoryNames, traverse_ptr->Student.Cat1.Cumulative);


			scores[1][0] = traverse_ptr->Student.Cat2.score1;
			scores[1][1] = traverse_ptr->Student.Cat2.score2;
			scores[1][2] = traverse_ptr->Student.Cat2.score3;
			float tot2 = 0;
			j = 0;
			for(int i = 0; i < 3; i++) {
				if(scores[1][i] != -1) {
					j++;
					tot2 += scores[1][i];
				}
			}
			if(j != 0) {
				traverse_ptr->Student.Cat2.Cumulative = (tot2/(float)j);
			} else {
				traverse_ptr->Student.Cat2.Cumulative = -1;
			}
			printf("%s Cumlative: %.2f\t",(char*)CategoryNames+15, traverse_ptr->Student.Cat2.Cumulative);

			scores[2][0] = traverse_ptr->Student.Cat3.score1;
			scores[2][1] = traverse_ptr->Student.Cat3.score2;
			scores[2][2] = traverse_ptr->Student.Cat3.score3;
			float tot3 = 0;
			j = 0;
			for(int i = 0; i < 3; i++) {
				if(scores[2][i] != -1) {
					j++;
					tot3 += scores[2][i];
				}
			}
			if(j != 0) {
				traverse_ptr->Student.Cat3.Cumulative = (tot3/(float)j);
			} else {
				traverse_ptr->Student.Cat3.Cumulative = -1;
			}
			printf("%s Cumlative: %.2f\t",(char*)CategoryNames+30, traverse_ptr->Student.Cat3.Cumulative);

			scores[3][0] = traverse_ptr->Student.Cat4.score1;
			scores[3][1] = traverse_ptr->Student.Cat4.score2;
			scores[3][2] = traverse_ptr->Student.Cat4.score3;
			float tot4 = 0;
			j = 0;
			for(int i = 0; i < 3; i++) {
				if(scores[3][i] != -1) {
					j++;
					tot4 += scores[3][i];
				}
			}
			if(j != 0) {
				traverse_ptr->Student.Cat4.Cumulative = (tot4/(float)j);
			} else {
				traverse_ptr->Student.Cat4.Cumulative = -1;
			}
			printf("%s Cumlative: %.2f\t",(char*)CategoryNames+45, traverse_ptr->Student.Cat4.Cumulative);
            //get Cumulative that was calcualted
			float c1 = traverse_ptr->Student.Cat1.Cumulative;
			float c2 = traverse_ptr->Student.Cat2.Cumulative;
			float c3 = traverse_ptr->Student.Cat3.Cumulative;
			float c4 = traverse_ptr->Student.Cat4.Cumulative;
            
            //set Cumulative to 100 if -1, only to calc Current_Grade
			if(c1 == -1) {
				c1 = 100;
			}
			if(c2 == -1) {
				c2 = 100;
			}
			if(c3 == -1) {
				c2 = 100;
			}
			if(c4 == -1) {
				c3 = 100;
			}

            //calc Current_Grade
			traverse_ptr->Student.Current_Grade = (c1*0.15) + (c2*0.30) + (c3*0.20) + (c4*0.35);
			printf("Current Grade is: %.2f\n",traverse_ptr->Student.Current_Grade);


            //next Student
			traverse_ptr = traverse_ptr->next;

		}

	}
}