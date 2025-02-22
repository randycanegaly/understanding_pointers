#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim(char* phrase) {
    char* old = phrase;
    char* new = phrase;
    
    while(*old == ' ') {
        old++;//pointer math - walk the char array while I see spaces, pointer will wind up pointing to first non-space char
    }
    
    while(*old) {//while the thing old points to is not false (is something)
        *(new++) = *(old++);//assign the value of what old points to to the value of what new points to
                            //increment both old and new pointers
    }
    *new = 0;//pointer new was advanced past the last non-space character, assign 0 (same as array terminator) to the thing that new points to
    //below, strlen is now 3, because spaces removed and '/0' placed after 't'. new buffer is now shorter 
    return (char*) realloc(phrase,strlen(phrase)+1);    
}

int main() {
    size_t len = strlen("  cat");
    char* buffer = (char*)malloc(len + 1);//allocate a buffer one more than the length of the string - for the '\0' end marker
    strcpy(buffer,"  cat");
    printf("len at first: %ld, string:--%s--\n", len, buffer);
    char* trimmed = trim(buffer);
    printf("len after trim: %ld, trimmed string:--%s--\n", strlen(trimmed), trimmed);
    //printf("%s\n",trim(buffer));
}
