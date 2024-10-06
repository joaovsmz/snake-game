#include <stdlib.h>
#include "../include/array.h"

void insertElement(int* array, int new_element){
    for(int i = MAX_LENGTH-1; i>0; i--){
        array[i] = array[i-1];
    }
    array[0] = new_element;
    return;
}