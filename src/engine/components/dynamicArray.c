#include <engine/components/dynamicArray.h>

void DynamicArray_malloc(void **array, int size, size_t typeSize)
{
    if(*array == NULL)
    {
        printf("DynamicArray : cannot allocate memory to a null pointer %s is NULL, memory will be free\n", GET_VARIABLE_NAME(array));
        free(*array);
    }
    else
    {
        *array = malloc(size * typeSize);
    }
    
}

void DynamicArray_realloc(void **array, int size, size_t typeSize)
{
    if(*array == NULL)
    {
        printf("DynamicArray : cannot re-allocate memory to a null pointer %s is NULL, memory will be free\n", GET_VARIABLE_NAME(array));
        free(*array);
    }
    else
    {
        *array = realloc(*array, size * typeSize);
    }
}

