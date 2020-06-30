#include<stdio.h>
#include<string.h>

void analyze_file(char *in_file, char* out_file){
	FILE *inFile = fopen(in_file, "r");
	FILE *ouFile = fopen(out_file, "a+");
	
	if(inFile == NULL){
		fprintf(ouFile,"Error(analyze_file): Could not open file %s",in_file);
		return;
	}

	
	char data[200];
	int i=0;
	
	int isEmptyLine = false; // flag to check is previous line is empty or not
	int isSpace = false; // flag to check previous space
	int isNewLine = true; //flag to check is current line is new line of not
	int countPara = 0; // para counter variable
	int countLines = 0; // lines counter variable
	int countWords = 0; // words counter variable
	int countChar = 0; // char counter variable
	int countAplpha = 0; // Alphacharacter counter variable
	int countNum = 0; // Numerical char counter variable
	int countOther = 0; // other then alpha numeric counter variable
	
	while (fgets(data, 200, inFile) != NULL){
		int len = strlen(data); //calcluate length of current line
		if( len == 1 || countChar == 0){
			isEmptyLine = true;
		}
		int lineCharCount = 0;
		for (int i = 0; i<len; i++){
			
			if(data[i] == '\n'){
				isNewLine = true;
			}else if (data[i] != ' '){
				
				if( (data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')){
					countAplpha++; // counts alphabets 
				}else if(data[i] >= '0' && data[i] <= '9'){
					countNum++; // counts numeric
				}else{
					countOther++; // counts other char
				}
				
				lineCharCount++;
				
				// counts words if line is new
				if(isNewLine == true && lineCharCount == 1){
					countWords++;
					isNewLine = false;
				}
				
				// counts words inside a line
				if(isSpace){
					countWords++;
					isSpace = false;
				}
				
				// counts para if line is new and has no previous empty line
				if(isEmptyLine == true && lineCharCount ==1){
					countPara++;
					isEmptyLine = false;
				}
				
				// count para inside the document
				if(isEmptyLine == true){
					countPara++;
					isEmptyLine = false;
				}
				
			}else{
				isSpace = true;
			}
		}
		
		countChar+=lineCharCount;
		
		countLines++;
		i++;
	}
	if (countChar == 0){
		countPara = 0;
		countLines = 0;
		countWords = 0;
	}
	
	// write all results to output file
	fputs("Analyse file ", ouFile);
	fputs(out_file, ouFile);
	fputs("\n", ouFile);
	fprintf(ouFile,"\n#Paragraphs = %d",countPara);
	fprintf(ouFile,"\n#lines = %d",countLines);
	fprintf(ouFile,"\n#Words = %d",countWords);
	fprintf(ouFile,"\n#Characters = %d",countChar);
	fprintf(ouFile,"\nAlpha = %d",countAplpha);
	fprintf(ouFile,"\nNumerical = %d",countNum);
	fprintf(ouFile,"\nOther = %d",countOther);
	fprintf(ouFile,"\n\n");
}

int main(int argc, char *argv[]){
	analyze_file(argv[1], argv[2]);
}
