#include <stdio.h>

int n, W;
int maxProfit = 0;
int bestSet[100], include[100], wt[100], val[100];

// Utility function to return max of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Backtracking function
void knapsack(int i, int weight, int profit) {
    if (weight <= W && profit > maxProfit) {
        maxProfit = profit;

        // Save current selection of items
        for (int j = 0; j < n; j++)
            bestSet[j] = include[j];
    }

    // If we already considered all items
    if (i == n)
        return;

    // Include item i
    include[i] = 1;
    knapsack(i + 1, weight + wt[i], profit + val[i]);

    // Exclude item i
    include[i] = 0;
    knapsack(i + 1, weight, profit);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // Start backtracking
    knapsack(0, 0, 0);

    printf("\nMaximum Profit = %d\n", maxProfit);
    printf("Items included (1 = taken, 0 = not taken):\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: %d\n", i + 1, bestSet[i]);
    }

    return 0;
}

