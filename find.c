#include"find.h"
#include <stdio.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LEN 1000
char*lineptr[MAX_LINES];
int results[MAX_LINES];
char *cLineArguments;
char *pattern;
int nlines;
char *lineptrCopy[MAX_LINES];

char* strstr_fully_matched(char* haystack, char* needle){
	char* rv;
	char padded_needle[strlen(needle) + 3];
	padded_needle[0] = ' ';
	strcpy(padded_needle + 1, needle);
	padded_needle[strlen(needle) + 1] = ' ';
	padded_needle[strlen(needle) + 2] = '\0';
	if(!strncmp(haystack, padded_needle + 1, strlen(needle) + 1))
		return haystack;//needle is at the beginning
	if((rv = strstr(haystack, padded_needle)) != NULL)
		return rv + 1;//needle is at the middle.
	padded_needle[strlen(needle) + 1] = '\0';
	if((rv = strstr(haystack, padded_needle)) != NULL)
		return rv + 1;//needle is at the end.
}
int getline2(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n';i++)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}
int readlines(char** lineptr, int maxlines){
	int len;
	char*p, line[MAX_LEN];

	nlines = 0;
	while((len = getline2(line, MAX_LEN)) > 0)
		if(nlines >= maxlines || (p = malloc(len)) == NULL)
			return -1;
		else{
			if(line[len - 1] == '\n')
				line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}


int main(int argc, char *argv[])
{

  cLineArguments = argv[1];
  pattern = argv[2];

  int *except = 0;//0 or 1             CLA: -x
	int *sorted = 0;//0 or 1             CLA: -s
	int *reversed = 0;//0 or 1           CLA: -r
	int *partial = 0;//0 or 1            CLA: -p
	int *numbered = 0;//0 or 1           CLA: -n
	int *first_occurrence = 0;//0 or 1   CLA: -f
	int *matched = 0;//0 or 1            CLA: -m
  int *case_ignore = 0; //0 or 1       CLA: -c


	//....handle command line arguments...
  except = strstr(cLineArguments,"x");
  sorted = strstr(cLineArguments,"s");
  partial = strstr(cLineArguments,"p");
  reversed = strstr(cLineArguments,"r");
  numbered = strstr(cLineArguments,"n");
  first_occurrence = strstr(cLineArguments,"f");
  matched = strstr(cLineArguments,"m");
  case_ignore = strstr(cLineArguments,"c");

	if(reversed && sorted || first_occurrence && except || partial && except){
		printf("Error. Invalid operation.\n");
		exit(0);
	}


	//similar to #41 of Chapter 5 partII.pptx
	int nlines = readlines(lineptr, MAX_LINES);// # of lines, similar, but not the same as the slide #23 of Chapter 5 partII.pptx
	int no_of_results = 0;

	if(numbered && case_ignore){
			for (int i = 0; i < nlines; i++){
				if(strcasestr(lineptr[i], pattern)){
					printf("Line: %i\n", i+1);
				}
			}
	}

		if(matched && !first_occurrence){
			char d[] = " \n";
			for(int i = 0; i < nlines; i++){

					char *token = strtok(lineptr[i], d);
				while(token!=NULL){
					if(strcmp(token, pattern) == 0){
						printf("Exact \"%s\" Match Found in Line: %i\n", pattern, i+1);
					}
					token = strtok(NULL, d);
				}
			}

		}else{
			for(int i = 0; i < nlines;i++){
			if((strstr(lineptr[i], pattern) != NULL) != except)
				results[no_of_results++] = i;
		}
	}

	if(except && case_ignore){
		for(int i = 0; i < nlines;i++){
		if(strcasestr(lineptr[i], pattern) == NULL){
			printf("No match \"%s\" in line %i: \n", pattern, lineptr[i]);
		}

	}
	}


    if(except && !case_ignore){
			for(int i = 0; i < nlines;i++){
      if(strstr(lineptr[i], pattern) == NULL){
				printf("No match: %s\n", lineptr[i]);
        //printf("No match: \"%s\"\n", pattern, i);
      }

    }
}

if(partial && !case_ignore){
	char dest[256];
	for (int i = 0; i <= nlines-1; i++){
		if(strstr(lineptr[i], pattern) != NULL){
				strncpy(dest, lineptr[i], 100);
				for (int i = 0; i < 10; i++){
						printf("%c", dest[i]);
				}
				printf("...%s...", pattern);
				printf("\n");
		}
	}
}


	print_results(pattern, matched, first_occurrence, numbered, sorted, partial, reversed, no_of_results, case_ignore);
    return 0;
}
