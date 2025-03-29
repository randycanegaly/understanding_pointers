#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int rows = 2;
	int columns = 5;

	
	//Allocating potentially non-contiguous memory
	//Allocate memory for the outer array. The pointer that is returned needs to be a pointer to pointer to int
	//A pointer to int is a pointer to an inner array
	//2 rows, so 2 pointers to int, so allocate memory for rows times sizeof pointer to int
	//int **matrix = (int **) malloc(rows * sizeof(int *));
	
	//Now, walk the rows and allocate memory for the 5 column ints, elements of each inner row array
	
	/*for (int i = 0; i < rows; i++) {//for each row
		//matrix[i] is the pointer to int to the first element of the ith row
		matrix[i] = (int *) malloc(columns * sizeof(int));//set each element of the outer array to a pointer to a block of memory for the 5 inner array elements */
	
	//Allocating contiguous memory, approach 1
	/*int **matrix = (int **) malloc(rows * sizeof(int *));//allocate memory for two int*, pointer to each inner array
		
	matrix[0] = (int *) malloc (rows * columns * sizeof(int ));//allocate the memory for all elements (columns)
															   //of all rows in one go. matrix[0] is a pointer (int *)
															   //to that block of memory for 10 ints, contiguous
	for (int i = 1; i < rows; i++)
			matrix[i] = matrix[0] + i * columns;//starting with the second row, set the value of each element (int *)
												//in the outer array to the address where the 5 ints of the corresponding 
												//row starts
												//if there were 10 rows, each of the 10 elements of the outer array would
												//hold int * pointers into the all in one go block of memory above to the 
												//point where that row's elements started*/
	


	//Allocating contiguous memory approach 2. Allocate all memory for the 2 x 5 array at once.
	int *matrix = (int *) malloc(rows * columns * sizeof(int));//allocate a block of memory for 10 ints.
															   //return a pointer to the first element

	//matrix[0][2] won't work with this, have to calculate to get to the elements you want ...
	for (int i = 0; i < rows; i++) {//walk the rows
		for (int j = 0; j < columns; j++) {//walk the columns
			*(matrix + (i * columns) + j) = i * j;//pointer math to get to matrix[1][2], the 8th element in the contiguous block,
												  //do the math with i = 1 and j = 2, yields matrix address + 5 + 2 = 
												  //the 8th element
		}	
	} 
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			printf("%d\n", *(matrix + (i * columns) + j));
		}	
	} 
}
