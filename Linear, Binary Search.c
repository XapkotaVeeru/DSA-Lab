#include <stdio.h>

void swap(int *firstElement, int *secondElement) {
    int temp = *firstElement;
    *firstElement = *secondElement;
    *secondElement = temp;
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (array[j] < array[minIndex])
                minIndex = j;
        swap(&array[minIndex], &array[i]);
    }
}

int linearSearch(int arr[], int size, int x) {
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int inputArray[50], arraySize, i;

    printf("Enter the size of the array: ");
    scanf("%d", &arraySize);

    printf("Enter the array elements:\n");
    for (i = 0; i < arraySize; i++) {
        scanf("%d", &inputArray[i]);
    }

    // Sorting array using Selection Sort
    selectionSort(inputArray, arraySize);

    int choice;
    printf("\nChoose search operation:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");

    scanf("%d", &choice);

    int x, result;

    switch (choice) {
        case 1:
            printf("Enter the element to search: ");
            scanf("%d", &x);
            result = linearSearch(inputArray, arraySize, x);
            (result == -1)
            ? printf("Element is not present in array\n")
            : printf("Element is present at index %d\n", result);
            break;

        case 2:
            printf("Enter the element to search: ");
            scanf("%d", &x);
            result = binarySearch(inputArray, 0, arraySize - 1, x);
            (result == -1)
            ? printf("Element is not present in array\n")
            : printf("Element is present at index %d\n", result);
            break;

        default:
            printf("Invalid choice\n");
            return 1;
    }

    return 0;
}
