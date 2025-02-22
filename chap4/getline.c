#include <stdio.h>
#include <stdlib.h>

char* my_getline(void);

int main(void) {
    char* line = my_getline();
    printf("%s\n", line);
}

char* my_getline(void) {
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
            char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);//new buffer size is incremenented by sizeIncrement

            if(newBuffer == NULL) {//if the realloc failed, leave
                free(buffer);
                return NULL;
            }
                        
            //belows are all addresses
            //if realloc moves things in the address space
            //then the new current position needs to be
            //the start of the new buffer plus
            //the offset of the old current position amongst the old buffer (which may have been in some other location) 
            currentPosition = newBuffer + (currentPosition - buffer);
            buffer = newBuffer;//realloc could have moved things in address space, so set pointer to the start of the buffer
            //to wherever the start of the new buffer is
            //printf("New maximum length: %ld\n", maximumLength);
        }
        *currentPosition++ = character;//set the value that currentPosition points to to be the new character read in
    }
    *currentPosition = '\0';//we've bailed out of the loop because we saw the end of the line, so need to add a terminating 'NUL' to the buffer we're building
    return buffer;
}

