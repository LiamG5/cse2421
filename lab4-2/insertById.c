/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY.
*/

#include"lab4.h"
#include<stdio.h>

void insertById(Node **head, Node *newNodePtr) {
    //empty list
    if (*head == NULL) {
        *head = newNodePtr;
        newNodePtr->next = NULL;
    } else {
        // check first node
        if (newNodePtr->Student.student_ID < (*head)->Student.student_ID) {
            newNodePtr->next = *head;
            *head = newNodePtr;
        } else {
            //check rest
            Node *prev = *head;
            Node *current = prev->next;

            while (current != NULL && current->Student.student_ID < newNodePtr->Student.student_ID) {
                prev = current;
                current = current->next;
            }
            //move
            prev->next = newNodePtr;
            newNodePtr->next = current;
        }
    }
}
