#include <stdio.h>
#include <stdlib.h>

int counting_rows(FILE * file){
	int count = 0;
	int c;
	while((c = fgetc(file)) != EOF){
		if(c == 10) count++;
	}
	fseek(file, 0, SEEK_SET);
	return count;
}

void generating_char_array(char *** lines, FILE * file, int rows){
	int i, row_length, c;
	char ** array = *lines;
	i = 0; row_length = 0;
	while((c = fgetc(file)) != EOF){
		row_length++;
		if(c == 10){
			array[i] = malloc(row_length * sizeof(**array));
			i++;
			row_length = 0;
		}
	}
	fseek(file, 0, SEEK_SET);
}

void populating_char_array(char *** array, FILE * file){
	int i, j, c;
	char ** lines = *array;	
	
	i = 0; j = 0;
	while((c = fgetc(file)) != EOF){
		if(c != 10){
			lines[i][j] += c;
			j++; 
		}else{
			lines[i][j] = 0;
			i++;
			j = 0;
		}
	}
	fseek(file, 0, SEEK_SET);
}

void printing_char_array(char ** lines, int length){
	for(int i = 0; i < length; i++){
		printf("%s\n", lines[i]);
	}
	printf("\n");
}

void shuffling(FILE * input, FILE * output){
	int c, rows, i;
	char ** lines;
	
	rows = counting_rows(input);
	lines = (char **) malloc(rows * sizeof(*lines));
	generating_char_array(&lines, input, rows);
	populating_char_array(&lines, input);
	//printing_char_array(lines, rows);
	
	int count = rows;
	while((c = fgetc(input)) != EOF){
		i = rand() % count;
		fputs(lines[i], output);
		fputc(10, output);
	}
	fseek(input, 0, SEEK_SET);
	rows = counting_rows(input);
	printf("%d", rows);
}

int main(int argc, char * argv[]){
	FILE * first_file;
	FILE * second_file;
	int f_close;
	first_file = fopen(argv[1], "r");
	second_file = fopen(argv[2], "w");
	
	shuffling(first_file, second_file);
	
	f_close = fclose(first_file);
	f_close = fclose(second_file);
}
