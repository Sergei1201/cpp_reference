/* Dynamic memory allocation with arrays in C */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Decide the size of the array
    int size;
    printf("Enter the size of the array for dynamic memory allocation: ");
    scanf("%d", &size);
    // Dynamic memory allocation on the heap with arrays of integers for the sake of the example
    int *ptr = (int *)malloc(sizeof(int) * size);
    // Make sure the memory has been allocated successfully
    if (ptr == NULL)
    {
        printf("The memory has not been allocated");
        return (-1);
    }
    else
    {
        printf("The memory has been allocated for the array of %d integers\n", size);
    }
    // Fill the array with some numbers
    for (int i = 0; i < size; i++)
    {
        ptr[i] = i * 2;
    }
    // Print the array to the console
    for (int j = 0; j < size; j++)
    {
        printf("%d \t", ptr[j]);
    }
    // Deallocate memory after using it
    free(ptr);
}