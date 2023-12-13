#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <structs/structs.h>

/* Allocate memory for a dynamic array
* @param array The dynamic array to allocate memory to
* @param size The size of the dynamic array
* @param typeSize The type of the dynamic array (sizeof(type)) 
*/
void DynamicArray_malloc(void **array, int size, size_t typeSize);
/* Re-allocate memory for a dynamic array
* @param array The dynamic array to re-allocate memory to
* @param size The new size of the dynamic array
* @param typeSize The type of the dynamic array (sizeof(type))
*/
void DynamicArray_realloc(void **array, int size, size_t typeSize);



#endif // DYNAMIC_ARRAY_H