#include "find.h"
#include <string.h>
#include <stdio.h>


	char temp[10][100];
void print_results(char* pattern, int matched, int first_occurrence, int numbered, int sorted, int partial, int reversed, int no_of_results, int case_ignore){
	char** sentences = (char**) malloc(no_of_results*sizeof(char*));
	for(int i = 0; i < no_of_results;i++){
		sentences[i] = strdup(lineptr[results[i]]);
	}



	if(sorted && !reversed){
		printf("Sorting...\n"); //call qsort on sentences...
		for (int i = 0; i <= nlines-1; i++){

			int j_min = i;
				for(int j = i + 1; j <= nlines-1; j++){
					if(strcmp(lineptr[j],lineptr[j_min]) < 0){
						j_min = j;
					}

					if(j_min != i){
						strcpy(temp, lineptr[i]);
						strcpy(lineptr[i], lineptr[j_min]);
						strcpy(lineptr[j_min], temp);
					}
				}
		}

			for (int i = 0; i < nlines; i++ ){
				printf("%s\n", lineptr[i]);
			}


	}if (reversed && !sorted){

		printf("Reversing...");
		printf("\n");
		for (int i = nlines-1; i >= 0; i--){
			printf("%s\n", lineptr[i]);
		}

	}

	for(int i = 0; i < no_of_results;i++){
		if(numbered && !case_ignore)
			printf("Line: %d \n", results[i] + 1);
		if(first_occurrence)
			if(matched){
				printf("@%d: \n", strstr_fully_matched(sentences[i], pattern) - sentences[i]);
			}
			else
				printf("@%d: \n", strstr(sentences[i], pattern) - sentences[i]);
				//printf("%s\n", sentences[i]);
	}
}
