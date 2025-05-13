/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>

void insertScore(Node **list_head_ptr,char *CategoryNames) {
    //get id
    int ID;
    printf("Enter the Student ID #:");
    scanf("%d",&ID);
    printf("Hunting for %d\n",ID);
    //move through list
    Node *traverse_ptr = *list_head_ptr;
	if(traverse_ptr != NULL) {
		while(traverse_ptr != NULL) {
		    if(traverse_ptr->Student.student_ID == ID){ //find id
		    //confirm?
		    printf("Insert a Score for %s ? Enter 1, if yes. Enter 2, if no: ",traverse_ptr->Student.student_name);
		    int confirm;
		    scanf("%d",&confirm);
		    if(confirm == 1){
		        
		        int cat;
		        int numScore;
		        //print cats 
		        printf("Which category?\n");
		        printf("1) %s\n", CategoryNames);
		        printf("2) %s\n",(char*)CategoryNames+15);
		        printf("3) %s\n",(char*)CategoryNames+30);
		        printf("4) %s\n",(char*)CategoryNames+45);
		        //get cat
		        scanf("%d", &cat);
		        //ask for which score
		        printf("Which score? Enter 1, 2, or 3");
		        //get score
		        scanf("%d", &numScore);
		        
		        //array of pointers to Cats, lets us avoid a big conditional mess
		        struct Cat_Grade *categories[] = {
                &traverse_ptr->Student.Cat1,
                &traverse_ptr->Student.Cat2,
                &traverse_ptr->Student.Cat3,
                &traverse_ptr->Student.Cat4};
                
                //array of pointers to scores in cat we wish to edit
                float *scores[] = {
                &categories[cat - 1]->score1,
                &categories[cat - 1]->score2,
                &categories[cat - 1]->score3};
                
		        float score2update;
		        printf("Enter New Score: ");
		        scanf("%f", &score2update);
		        
		        *scores[numScore - 1] = score2update;
		        
		        
		    }
		    //exit if id is found regardless of choice, lets error message send correctly
		    return;
		    }
		    
		    
		    traverse_ptr = traverse_ptr->next;
		}
		printf("Id inputed not found!\n");
	}
}
