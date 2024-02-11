#include<stdio.h>

void swap(int *firstElement, int *secondElement)
{
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void selectionSort(int array[], int size)
{
    int i, j, minIndex;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[minIndex])
                minIndex = j;

        swap(&array[minIndex], &array[i]);
    }
}

int main()
{
    int inputArray[50], arraySize, i;

    printf("Enter the size of the array\n");
    scanf("%d", &arraySize);

    printf("Enter the array\n");
    for (i = 0; i < arraySize; i++)
    {
        scanf("%d", &inputArray[i]);
    }

    selectionSort(inputArray, arraySize);

    printf("Sorted array:\n");
    for (i = 0; i < arraySize; i++)
    {
        printf("%d \t", inputArray[i]);
    }

    return 0;
}
