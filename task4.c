#include <stdio.h>

void main() {
    int arr[50] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
    int key = 21; // Element to search
    int moy, low = 0, end = 49;
    while (low <= end) {
        moy = (low + end) / 2;
        if (arr[moy] < key) {
            low = moy + 1;
        } else if (arr[moy] > key) {
            end = moy - 1;
        } else {
            printf("The element %d is found at index %d\n", key, moy);
            return;
        }
    }
    printf("The element %d was not found\n", key);
}