#include <stdio.h>

int main(void) {
    //int vector[5];//vector is the name of an array 5 int elements
    int vector[] = {1, 2, 3, 4, 5};
    printf("%ld\n", sizeof(vector)/sizeof(int));


    for(int i=0; i<5; i++) {
        printf("%d\n", vector[i]);
    }


}
