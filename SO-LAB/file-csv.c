#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define G 256

void printing_matrix(char *** matrix, int col, int row){
	    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
		    printf("[%s]", matrix[i][j]);
		}
		printf("\n");
	    }
}

void counting_rows(int * row, FILE * file){
	int c;
	int counted_rows = 0;
	while((c = fgetc(file)) != EOF){
		if(c == 10) counted_rows++;
	}
	*row = counted_rows;
}

void counting_cols(int * col, FILE * file){
	int c;
	int counted_cols = 1;
	while((c = fgetc(file)) != 10){
		if(c == 44) counted_cols++;
	}
	*col = counted_cols;
}

void populating_matrix(char *** m, int col, int row, FILE * file){
    int c, i, j, z;
    i = 0; j = 0; z = 0;
    
    while ((c = fgetc(file)) != EOF) {
        if (i < row && j < col) {
            if (c == 44) {
                // Add null terminator at the end of the string
                m[i][j][z] = '\0';
                j++;
                z = 0;
            } else if (c == 10) {
                // Add null terminator at the end of the string
                m[i][j][z] = '\0';
                i++;
                j = 0;
                z = 0;
            } else {
            	if(c != 32){
            		m[i][j][z] = c;
            		z++;
            	}
            }
        } else {
            // Handle the case where i or j exceeds the allocated dimensions
            fprintf(stderr, "Error: Matrix dimensions exceeded\n");
            break;
        }
    }
    // Add null terminator for the last string
    if (i < row && j < col) {
        m[i][j][z] = '\0';
    }
}



char *** generating_matrix(int * row, int * col, FILE * file) {
    counting_rows(row, file);
    fseek(file, 0, SEEK_SET);
    counting_cols(col, file);
    fseek(file, 0, SEEK_SET);

    if (*row <= 0 || *col <= 0) {
        fprintf(stderr, "Invalid matrix dimensions\n");
        return NULL;
    }

    char *** matrix = (char ***)malloc(*row * sizeof(*matrix));
    if (matrix == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < *row; i++) {
        matrix[i] = (char **)malloc(*col * sizeof(**matrix));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // Clean up allocated memory before returning
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }

        for (int j = 0; j < *col; j++) {
            matrix[i][j] = (char *)malloc(64 * sizeof(***matrix));
            if (matrix[i][j] == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                // Clean up allocated memory before returning
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l < j; l++) {
                        free(matrix[k][l]);
                    }
                    free(matrix[k]);
                }
                free(matrix);
                return NULL;
            }
        }
    }

    populating_matrix(matrix, *col, *row, file);

    return matrix;
}

long ** from_char_matrix_to_int_matrix(char *** input, int row, int col){
	char * endptr;
	long ** ris = malloc(row * sizeof(*ris));
	
	for(int i = 0; i < row; i++){
		ris[i] = malloc(col * sizeof(**ris));
	}	
	
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			ris[i][j] = strtol(input[i][j], &endptr, 10);
		}
	}
	
	return ris;
}

void printing_int_matrix(long ** m, int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			printf("[%d]", m[i][j]);
		}
		printf("\n");
	}
}

void free_matrix(long ** m, int row, int col){
	for(int i = 0; i < row; i++){
		free(m[i]);
	}
	free(m);
}

void data_column_process(int * data, int length, int * min, int * max, double * avg){
	*min = data[0];
	*max = data[0];
	double somma = 0;
	double l = length;
	*avg = 0;
	printf("\n[ ");
	for(int e = 0; e < length; e++) printf("%d ", data[e]);
	printf("]\n");
	for(int i = 0; i < length; i++){
		if(data[i] < *min){
			*min = data[i];
		}else if(data[i] > *max){
			*max = data[i];
		}
		somma += data[i];	
	}
	*avg = somma / l;
	printf("min= %d, max= %d, avg= %lf\n", *min, *max, *avg);
}

void calculating(long ** m, int row, int col){
	int * column = malloc(row * sizeof(*column));
	int min, max;
	double avg;
	
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++){
			column[j] = (int) m[j][i];
		}
		printf("colonna %d: ", i+1);
		data_column_process(column, row, &min, &max, &avg);
	}
}	

int main(int argc, char * argv[]){
	FILE * my_f;
	int close_f, row, col;
	
	my_f = fopen(argv[1], "r");
	
	char *** csv_matrix = generating_matrix(&row, &col, my_f);
	//printing_matrix(csv_matrix, col, row);
	
	long ** matrix = from_char_matrix_to_int_matrix(csv_matrix, row, col);
	printing_int_matrix(matrix, row, col);
	calculating(matrix, row, col);
	
	free_matrix(matrix, row, col);
	
	//Operazioni di chiusura files e disallocazione
	close_f = fclose(my_f);
}
