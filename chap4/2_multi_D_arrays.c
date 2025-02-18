#include <stdio.h>

int main(void) {
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};//2 row, 3 column matrix

    for (int i = 0; i < 2; i++) {
        printf("&matrix[%d]: %p  sizeof(matrix[%d]): %ld\n", i, &matrix[i], i, sizeof(matrix[i]));//&matrix[i] means the address of the i'th row
    };
    printf("\n");

    int arr3d[3][2][4] = {//3 rows, 2 columns, rank 4
        {{1, 2, 3, 4}, {5, 6, 7, 8}},//row 1, contains 2 columns, each column contains 4 rank
        {{9, 10, 11, 12}, {13, 14, 15, 16}},//row 1, contains 2 columns, each column contains 4 rank
        {{17, 18, 19, 20}, {21, 22, 23, 24}}//row 1, contains 2 columns, each column contains 4 rank
    };

    for (int j = 0; j < 3; j++) {
        printf("&arr3d[%d]: %p  sizeof(arr3d[%d]): %ld\n", j, &arr3d[j], j, sizeof(arr3d[j]));
    };
    printf("\n");
}
