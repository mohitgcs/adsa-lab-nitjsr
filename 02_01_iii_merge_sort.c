#include <stdio.h>
#include <stdlib.h>

// Function declarations
void mergesort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);

int main() {
    int a[] = {10, 2, 4, 14, 6, 15};
    int n = 6;

    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int b[n1], c[n2];

    for (int i = 0; i < n1; i++)
        b[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        c[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        } else {
            a[k++] = c[j++];
        }
    }

    while (i < n1) {
        a[k++] = b[i++];
    }
}

