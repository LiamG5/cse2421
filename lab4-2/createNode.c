/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/
#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node* createNode(char *name, int id, float scores[4][3]) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	if (!newNode) {
		perror("Memory allocation failed");
		return NULL;
	}

	//set name
	strcpy(newNode->Student.student_name, name);
	//set id
	newNode->Student.student_ID = id;

	//sets all scores
	newNode->Student.Cat1.score1 = scores[0][0];
	newNode->Student.Cat1.score2 = scores[0][1];
	newNode->Student.Cat1.score3 = scores[0][2];
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
		newNode->Student.Cat1.Cumulative = (tot1/(float)j);
	} else {
		newNode->Student.Cat1.Cumulative = -1;
	}

	newNode->Student.Cat2.score1 = scores[1][0];
	newNode->Student.Cat2.score2 = scores[1][1];
	newNode->Student.Cat2.score3 = scores[1][2];
	float tot2 =0;
	j =0;
	for(int i = 0; i < 3; i++) {

		if(scores[1][i] != -1) {
			j++;
			tot2 +=scores[1][i];
		}


	}
	if(j!= 0) {
		newNode->Student.Cat2.Cumulative = (tot2/(float)j);
	} else {
		newNode->Student.Cat2.Cumulative = -1;
	}


	newNode->Student.Cat3.score1 = scores[2][0];
	newNode->Student.Cat3.score2 = scores[2][1];
	newNode->Student.Cat3.score3 = scores[2][2];
	float tot3 =0;
	j= 0;
	for(int i = 0; i < 3; i++) {


		if(scores[2][i] != -1) {
			j++;
			tot3 +=scores[2][i];
		}


	}
	if(j!= 0) {
		newNode->Student.Cat3.Cumulative = (tot3/(float)j);
	} else {
		newNode->Student.Cat3.Cumulative = -1;
	}

	newNode->Student.Cat4.score1 = scores[3][0];
	newNode->Student.Cat4.score2 = scores[3][1];
	newNode->Student.Cat4.score3 = scores[3][2];
	float tot4 =0;
	j=0;
	for(int i = 0; i < 3; i++) {


		if(scores[3][i] != -1) {
			j++;
			tot4 +=scores[3][i];
		}

	}
	if(j!= 0) {
		newNode->Student.Cat4.Cumulative = (tot4/(float)j);
	} else {
		newNode->Student.Cat4.Cumulative = -1;
	}
	// if all scores are -1 then set to 100
	float c1 = newNode->Student.Cat1.Cumulative;
	float c2 = newNode->Student.Cat2.Cumulative;
	float c3 = newNode->Student.Cat3.Cumulative;
	float c4 = newNode->Student.Cat4.Cumulative;
	
	
	
	
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


	newNode->Student.Current_Grade = (c1*0.15) + (c2*0.30) + (c3*0.20) + (c4*0.35);
	newNode->Student.Final_Grade = -1;
	newNode->next = NULL;

	return newNode;
}