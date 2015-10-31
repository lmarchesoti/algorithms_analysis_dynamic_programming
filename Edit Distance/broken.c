#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *word1, *word2; // input words

int edit_distance(int size1, int size2); // longest increasing subsequence

int main(){

	int i; // iterator
	int edistance; // final result
	int size1, size2; // word sizes

	/* scan input */
	//while(scanf("%d %d\n", &size1, &size2) != EOF){
	scanf("%d %d\n", &size1, &size2);
		/* input reading */
		// adjust for terminating byte
		++size1; ++size2;
		++size1; ++size2;
		printf("derp");
		// allocate memory for inputs
		//word1 = (char*) malloc(size1);
		//word2 = (char*) malloc(size2);

		// read inputs
		//fgets(word1, size1, stdin);
		//fgets(word2, size2, stdin);
		getline(&word1, NULL, stdin);
		getline(&word2, NULL, stdin);

		// erase newline from string
		word1[strlen(word1) - 1] = '\0';
		word1[strlen(word1) - 1] = '\0';

		// reduce string size
		//--size1; --size2;

		// print inputs
		printf("word1: %s, word2: %s\n", word1, word2);
		/* end */

		edistance = edit_distance(size1, size2);

		printf("Edit distance: %d\n", edistance);

	//}

} // main

int edit_distance(int size1, int size2){
	return 0;
} // edit_distance