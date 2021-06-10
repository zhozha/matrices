# Dynamic memory usage

Write a program that does the required processing of an array of values. Arrays must be declared as local variables in the main function. The program should be implemented as a set of functions that take an array as a parameter. The number of array elements is not known in advance, the array must be stored in dynamic memory that will be reallocated as it is read data from the file. Data for arrays is read from the text file "input.txt", located in the current project directory, and saved to the file "output.txt" (when necessary).

Sort the array in ascending order of the elements of the first row.

How to use:

- create a file with a matrix, where the first row is the dimension of the matrix;
- compile the project ```gcc main.c matrix.c -o matrix```
- run app ```./matrix <file>```
