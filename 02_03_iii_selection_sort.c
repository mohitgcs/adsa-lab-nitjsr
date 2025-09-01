#include <stdio.h>

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[m])
                m = j;
        }
        int temp = arr[i];
        arr[i] = arr[m];
        arr[m] = temp;
    }

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

