#include <stdio.h>

//Pointer Notation and Arrays

int main(void) {
    int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;//array name by itself is the address of the array. can assign that address to a pointer to int (the first item in the array)

    printf("%p\n", vector);
    printf("%p\n", &vector[0]);
    printf("%p\n", &vector);

    printf("%d\n", *(pv + 1)); //same as pv[1]
    printf("%d\n", pv[1]);
    


}
