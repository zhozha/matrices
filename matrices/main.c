#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "matrix.a"

#define BUFFER_SIZE 5

/**
Reads matrix from text file
first line contains matrix dimensions
example:
3 3
1 2 3
4 5 6
7 8 9
*/
TMatrix *mx_from_file(char *filename) {
	FILE *f;
	int colCount, rowCount;
	int n;
	int i, j;
	double value;
	TMatrix *M;

	f = fopen(filename, "rt");

	n = fscanf(f, "%d %d\n", &rowCount, &colCount);
	//TODO: check if parameter count is not 2

	//TODO: check malloc for NULL
	M = (TMatrix*)malloc(sizeof(TMatrix));

	M->m = rowCount;
	M->n = colCount;
	M->a = (double*)malloc(sizeof(double)*colCount*rowCount);

	for (i = 0; i < rowCount; i++)
	{
		for (j = 0; j < colCount; j++)
		{
			fscanf(f, "%lf", &value);
//print intermediate resulst only in debug configuration
#ifdef _DEBUG
			printf("%lf ", value);
#endif
			M->a[i * colCount + j] = value;
		}

#ifdef _DEBUG
		printf("\n");
#endif

	}

	fclose(f);

	return M;

}

int main(int argc, char **argv) {
	TMatrix *m;

	if (argc != 2) {
		printf("Usage: .exe <input.txt>\n");
		return -1;
	}

	if (!(m = mx_from_file(argv[1]))) {
		printf("Cannot read file %s\n", argv[1]);
		return -1;
	}

	mx_print(m);
    printf("\n");

    mx_sort(m);

    mx_print(m);

    mx_free(m);

	return 0;
}