#include "darray.h"
#include <stdlib.h>

//Looking at the assingment it didnt say anything about what this needed to include so i looked up parts of the code to include everything so it can run 
// and to make sure the actual part you asked for is working. Hopefully this is okay.

struct darray {
    size_t size;      
    size_t capacity;  
    int *data;       
};

darray *da_create() {
    darray *array = malloc(sizeof(darray));
    if (array == NULL) {
        return NULL; 
    }

    
    array->size = 0;
    array->capacity = 1; 
    array->data = malloc(array->capacity * sizeof(int)); 
    if (array->data == NULL) {
        free(array); 
        return NULL; 
    }

    return array;
}

void da_delete(darray *array) {
    if (array) {
        free(array->data); 
        free(array);       
    }
}


size_t da_size(darray *array) {
    return array ? array->size : 0; 
}

int *da_get(darray *array, size_t index) {
    if (array == NULL || index >= array->size) {
        return NULL; 
    }
    return &array->data[index]; 
}
int da_append(darray *array, int value) {
    if (array == NULL) {
        return 0; 
    }

 
    if (array->size >= array->capacity) {
        size_t new_capacity = array->capacity * 2; 
        int *new_data = realloc(array->data, new_capacity * sizeof(int));
        if (new_data == NULL) {
            return 0; 
        }
        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size++] = value; 
    return 1;
}

