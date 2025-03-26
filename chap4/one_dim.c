#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int* arr[5];
    for(int i=0; i<5; i++) {
        *(arr+i) = (int*)malloc(sizeof(int));//arr+i is the address of an element of the array
        //the thing at that address is a pointer to (the address of) an int - *(arr+i) gets that pointer to int
        //**(arr+i) dereferences again and gets the pointed to by that pointer to int - the int
        **(arr+i) = i;
        printf("%d\n", **(arr+i));
    }
}





