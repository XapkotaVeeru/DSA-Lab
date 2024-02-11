#include <stdio.h>

void swap(int *firstElement, int *secondElement) {
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void selectionSort(int array[], int size) {
    int i, j, minIndex;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++)
            if (array[j] < array[minIndex])
                minIndex = j;
        swap(&array[minIndex], &array[i]);
    }
}

void insertionSort(int array[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

int main() {
    int inputArray[50], arraySize, i;

    printf("Enter the size of the array\n");
    scanf("%d", &arraySize);

    printf("Enter the array\n");
    for (i = 0; i < arraySize; i++) {
        scanf("%d", &inputArray[i]);
    }

    int choice;
    printf("Choose sorting algorithm:\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Quick Sort\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectionSort(inputArray, arraySize);
            printf("Sorted array using Selection Sort:\n");
            break;

        case 2:
            insertionSort(inputArray, arraySize);
            printf("Sorted array using Insertion Sort:\n");
            break;

        case 3:
            quickSort(inputArray, 0, arraySize - 1);
            printf("Sorted array using Quick Sort:\n");
            break;

        default:
            printf("Invalid choice\n");
            return 1;
    }

    for (i = 0; i < arraySize; i++) {
        printf("%d \t", inputArray[i]);
    }

    return 0;
}
