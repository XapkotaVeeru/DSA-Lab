#include <stdio.h>

int stepCount = 1;

void towerOfHanoi(int numDiscs, char towerA, char towerB, char towerC);

int main() {
    int numberOfDiscs;

    printf("Enter the number of discs: ");
    scanf("%d", &numberOfDiscs);

    towerOfHanoi(numberOfDiscs, 'A', 'B', 'C');

    return 0;
}

void towerOfHanoi(int n, char towerA, char towerB, char towerC) {
    if (n == 1) {
        printf("\nStep %d: Move the topmost disc from %c to %c", stepCount++, towerA, towerC);
        return;
    } else {
        towerOfHanoi(n - 1, towerA, towerC, towerB);

        printf("\nStep %d: Move the topmost disc from %c to %c", stepCount++, towerA, towerC);

        towerOfHanoi(n - 1, towerB, towerA, towerC);
    }
}
