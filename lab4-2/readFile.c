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

int readFile(Node **list_head_ptr, const char *fileIn, char *CategoryNames,int *size) {
    int num = 0;
    FILE *f = fopen(fileIn, "r");
    
    if (f == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read category names
    char line[100];
    fgets(line, sizeof(line), f);
    
    sscanf(line,"%s %s %s %s",CategoryNames,(char*)CategoryNames+15,(char *)CategoryNames+30,(char *)CategoryNames+45);
    //loop until null, breaks needs as EOF has been unrelaibale 
    //if the line is null while loop will break, no issues even though it has to be checked every time. 
    while (1) {
        char name[60];
        int id;
        //get a line, exit if fails
        if (fgets(line, sizeof(line), f) == NULL) {
            break; 
        }
        //set null terminator 
        line[strcspn(line, "\n")] = '\0';
        strcpy(name, line); 
        
        //get a line for id, exit if fail
        if (fgets(line, sizeof(line), f) == NULL) {
            break;
        }
        sscanf(line, "%d", &id);
        
        // Read the scores, exit if fail
        float scores[4][3];
        for (int i = 0; i < 4; i++) {
            if (fgets(line, sizeof(line), f) == NULL) {
                break;
            }
            sscanf(line, "%f %f %f", &scores[i][0], &scores[i][1], &scores[i][2]);
        }
        
        Node *n = createNode(name, id, scores); 
        insertById(list_head_ptr, n);
        num++;
        //printf("%s %d\n", name, id);
        //for (int i = 0; i < 4; i++) {
        //   printf("%.2f %.2f %.2f\n", scores[i][0], scores[i][1], scores[i][2]);
        //}
        
    }
    fclose(f);
    return num;
    
}