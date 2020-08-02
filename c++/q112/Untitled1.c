/*
Desperation: This program will have that reports how many lines, words, and characters in an input text file with more than 300 words,
and at least 3 paragraphs, and also makes a sorted list of all words found in it. You are required to provide the text file.
Write the sorted list to an output file, along with the number of times each word appeared in the input file.
For the purpose of this program, a word consists of a consecutive sequence of any characters except white space characters
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main(void)
{
	int wordcount = 0, charcount = 0;
	FILE *fptr, *fptr1;
	int i, len, index, isUnique;
	
	char words[MAX][50];
	char temp[50];
	int t;
	char word[50];
	
	int count[MAX];
	
	fptr = fopen("file.txt", "r");
	
	if (fptr == NULL)
	{
		printf("Unable to open file. ");
		exit(1);
	}
	
	for (i = 0; i<MAX; i++)
	count[i] = 0;
	index = 0;
	
	while (fscanf(fptr, "%s", word) != EOF)
	{
		len = strlen(word);
		if (ispunct(word[len - 1]))
			word[len - 1] = '\0'; // old: word[len - 1] = ''; empty character constant is not allowed
			
		// condition to check is there any punctuation character at index 0
		if (ispunct(word[0])){ // if yes
			// remove that punctuation
			for(int i=1; i<len; i++){
				word[i-1] = word[i];
			}
			word[len-1] = '\0';
		}
		
		for (int i = 0; i<len; i++)
		{
			if (word[i] >= 'A' && word[i] <= 'Z')
			{
				word[i] = word[i] + 32;
			}
		}
		
		isUnique = 1;
		for (i = 0; i<index && isUnique; i++)
		{
			if (strcmp(words[i], word) == 0)
			isUnique = 0;
		}
		
		
		if (isUnique)
		{
			strcpy(words[index], word);
			count[index]++;
			index++;
		}
		else
		{
			count[i - 1]++;
		}
	}
	
	fclose(fptr);
	
	fptr1 = fopen("out.txt", "w");
	
	if (fptr1 == NULL)
	{
		printf("Unable to open file. ");
		exit(1);
	}
	for (i = 0; i < index - 1; i++)
	{
		for (int j = i + 1; j < index; j++)
		{
			if (strcmp(words[i], words[j]) > 0)
			{
				strcpy(temp, words[i]);
				strcpy(words[i], words[j]);
				strcpy(words[j], temp);
				
				t = count[i];
				count[i] = count[j];
				count[j] = t;
			}
		}
	}
	wordcount = index;
	for (int i = 0; i<index; i++)
	{
		charcount = charcount + strlen(words[i]);
	}
	printf("Total words=%d", wordcount);
	printf(" Total character=%d", charcount);
	for (i = 0; i<index; i++)
	{
		fprintf(fptr1, "%-15s => %d\n", words[i], count[i]);
	}
	return 0;
}
