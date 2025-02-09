#include <stdio.h>
#include <stdlib.h>

char* getLine(void);


void main(void) {
    /*int matrix[2][3] = {{1,2,3},{4,5,6}};

    //prints out address and size for each row in the 2 x 3 matrix above
    for (int i = 0; i < 2; i++) {
        printf("&matrix[%d]: %p  sizeof(matrix[%d]): %lu\n", i, &matrix[i], i, sizeof(matrix[i]));
    }

    //define (storage for) an array
    //its name points to the first element in the array, the name is like a pointer
    //vector is same as &vector[0]. both are pointers to the first element in the array
    //however, &vector is a pointer to the entire array. &vector can be used to pass entire vectors to function
    int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;
    int *alt_pv;

    printf("address of vector name: %p\n", vector);
    printf("pointer to vector name: %p\n", pv);
    printf("pointer to next vector element: %p\n", pv + 1);
    printf("second element of vector: %d\n", vector[1]);//means pointer math add one and dereference to get the value of the second element of vector
    printf("address of vector: %p\n", &vector);
    printf("another way to get the address of the first element: %p\n", &vector[0]);//means pointer math add one, dereference and then cancel the dereference
                                                                                    //to get the address there

    pv = vector;
    alt_pv = vector;
    int value = 3;
    for(int i=0; i<5; i++) {
        *pv++ *= value;//precedence - dereference pv to get the value it points to, then times equal 3 (value = value * 3), then increment pv (shift to next element)
    }

    for(int i=0; i<5; i++) {
        printf("new 3 times value of vector: %d\n", vector[i]);
    }

    for(int i=0; i<5; i++) {
        printf("alt new 3 times value of vector: %d\n", *(alt_pv + i));
    }
    */
    /*int vector[5] = {1, 2, 3, 4, 5};
    int *pv = vector;

    pv = pv + 1;//this is OK, pointer pv is an lvalue, it can be assigned to
    *///vector = vector + 1; // Syntax error, an array name is not an lvalue, it can't be assigned to

    //pv = vector + 1;//this is OK, vector can be modified, it is a pointer that can be pointer mathed

    /*use malloc to create a one dimensional array
     * allocate memory on the heap for 5 ints
     * cast the void pointer returned by malloc to a pointer to int
     * assign that new pointer to pv, a pointer to int
    */

    /*int *pv = (int*) malloc(5 * sizeof(int));
    for(int i=0; i<5; i++) {
        pv[i] = i+1;
    }

    this is the same as ...
    where the pointer math (pv+i) essentially yields a new pointer pointing to that new location
    pointer pv never is changed, it remains pointing to the front of the newly allocated array.
    for(int i=0; i<5; i++) {
        *(pv+i) = i+1;
    }
    for(int i=0; i<5; i++) {
        printf("element: %d\n", pv[i]);
    }*/

    /*USING REALLOC FUNCTION TO RESIZE AN ARRAY*/
    char* getLine(void);




}

char* getLine(void) {
    const size_t sizeIncrement = 10;//initial size of the buffer and how much to grow it by each time
    char* buffer = malloc(sizeIncrement);//allocate memory in the heap for buffter
    char* currentPosition = buffer;//next spot in the buffer where something can be added
    size_t maximumLength = sizeIncrement;//max number for characters that can be saved in the buffer right now
    size_t length = 0;//number of characters read in
    int character;//last character read in

    if(currentPosition == NULL) { return NULL; }//this means malloc failed and the function failed

    while(1) {//loop until the end of the universe
        character = fgetc(stdin);//get one character from stdin. same as getchar()
        if(character == '\n') { break; }//reached end of line, bail out of the loop

        if(++length >= maximumLength) {//I read in more characters than the buffer can hold, grow the buffer
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);

            if(newBuffer == NULL) {
                free(buffer);
                return NULL;
            }
                        
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;
        }
        *currentPosition++ = character;
    }
    *currentPosition = '\0';
    return buffer;
}
