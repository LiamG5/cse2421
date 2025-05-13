/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/
//info for students
struct Cat_Grade {
	float score1;
	float score2;
	float score3;
	float Cumulative;
};

struct Data {
	char student_name[40];
	int student_ID;
	struct Cat_Grade Cat1;
	struct Cat_Grade Cat2;
	struct Cat_Grade Cat3;
	struct Cat_Grade Cat4;
	float Current_Grade;
	float Final_Grade;
};

typedef struct Node {
	struct Data Student;
	struct Node *next;
} Node;

//funtions 
Node* createNode(char *name, int id, float scores[4][3]);
void insertById( Node **list_head_ptr, Node *newNodePtr);
void printHeader(char *CategoryNames);
void printAll(Node **list_head_ptr,char *CategoryNames, int *size);
void printNa(float score);
void printById(Node **list_head_ptr, int idNum,char *CategoryNames);
void printByLastName(Node **list_head_ptr, char *CategoryNames,int *size);
int readFile(Node **list_head_ptr, const char *fileIn,char *CategoryNames,int *size);
void updateScoreById(Node **list_head_ptr, int ID, char *CategoryNames);
void updateAll(Node **list_head_ptr,char *CategoryNames);
void insertScore(Node **list_head_ptr,char *CategoryNames);
void calcFinal(Node **list_head_ptr,char *CategoryNames,int *size);
void addStudent(Node **list_head_ptr,  char *CategoryNames);
void delete(Node **list_head_ptr, char *CategoryNames);
void writeFile(Node **list_head_ptr, char *fileOut,char *CategoryNames);