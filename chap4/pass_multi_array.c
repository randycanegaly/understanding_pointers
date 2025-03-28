#include <stdio.h>

void display2DArray(int (*arr)[5], int rows);
void display2DArrayUnknownSize(int *arr, int rows, int cols);

int main(void) {
	int matrix[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
	printf("matrix is at address %p\n", &matrix);
	
	display2DArray(matrix, 2);
	display2DArrayUnknownSize(&matrix[0][0], 2, 5);//matrix[0][0] is the first element of the entire array
												   //pass its address
}

//if this was just int arr[5], then arr would be a pointer to the first element in an array of
//5 ints
//In (*arr), arr points to the first element of an array. That is an array of arrays.
//When I dereference arr .... (*arr), then I am describing what that first element looks like,
//it is an array of 5 ints
//so when I say int (*arr)[5], I am saying arr is the name of, and points to an array of arrays,
//where each of those arrays has 5 ints as elements.
void display2DArray(int (*arr)[5], int rows) {
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<5; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

void display2DArrayUnknownSize(int *arr, int rows, int cols) {
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", *(arr + (i*cols) + j));
        }
        printf("\n");
    }
}
