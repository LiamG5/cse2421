/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF THE
** WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN THIS
** FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE INSTRUCTOR
** OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE TENURES OF THE
** OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"

// DMA for the titles
void getTitles(char **titles, int n) {

	printf("enter the %d book titles lind by line: ", n);
	//get char till new line
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	
	char **current = titles;
	for (int i = 0; i < n; i++, current++) {
		*current = malloc(61 * sizeof(char));
		if (*current == NULL) {
			fprintf(stderr, "Faild!\n");
			return;
		}
		fgets(*current, 61, stdin);

	}
}
// DMA for the favorites
void getFavorites(char **favorites, int m, char **titles, int n) {
	printf("which number books? : ");

	char **current = favorites;
	for (int i = 0; i < m; i++, current++) {
		int k;
		scanf("%d", &k);
		*current = *(titles + (k - 1));
	}
}
// creates file
void saveFile(char **titles, int tCount, char **favorites, int fCount, char *filename) {

	FILE *out = fopen(filename, "w");
	if (!out) {
		perror("failed!");
		return;
	}
    //write books
	fprintf(out, "books:\n");
	char **current = titles;
	for (int i = 0; i < tCount; i++, current++) {
		fprintf(out, "%s\n", *current);
	}
    //write favorites
	fprintf(out, "\nfavorites :\n");
	current = favorites;
	for (int i = 0; i < fCount; i++, current++) {
		fprintf(out, "%s\n", *current);
	}
    //close
	fclose(out);
}

int main() {
	//sizes from user
	int n, m;

	printf("how many books? ");
	scanf("%d", &n);

	//alloacte Memory for books array 
	char **titles = malloc(n * sizeof(char *));
	if (titles == NULL) {
		perror("failed!");
		return 1;
	}

	getTitles(titles, n);

	//print books
	printf("\nbooks:\n");
	char **current = titles;
	for (int i = 0; i < n; i++, current++) {
		printf("%d %s", i + 1, *current);
	}

	printf("\nOf the %d books, how many for your favorites list? ", n);
	scanf("%d", &m);

	//set up favorites array
	char **favorites;
	if (m > 0) {
	    //alloacte space and set to favorites
		favorites = malloc(m * sizeof(char *));
		if (favorites == NULL) {
			//free and exit
			current = titles;
			for (int i = 0; i < n; i++, current++) {
				free(*current);
			}
			free(titles);
			return 1;
		}
		getFavorites(favorites, m, titles, n);
	}
    //print out favorites
	if (m > 0) {
		printf("\nfavorites books are:\n");
		current = favorites;
		for (int i = 0; i < m; i++, current++) {
			printf("%d. %s\n", i + 1, *current);
		}
	} else {
		printf("\nno favorites :(\n");
	}
	//set up file save
	int choice;
	printf("\nsave a file? 1 yes, 2 no: ");
	scanf("%d", &choice);
	//if saving file
	if (choice == 1) {
		char filename[100];
		printf("name for file? ");
		scanf("%s", filename);
		saveFile(titles, n, favorites, m, filename);
		printf("saved to %s!\n", filename);
	}

    //free all books prevents leak
	current = titles;
	for (int i = 0; i < n; i++, current++) {
		free(*current);
	}
    //free rest of Memory
	free(titles);

	if (m > 0) {
		free(favorites);
	}

	return 0;
}
