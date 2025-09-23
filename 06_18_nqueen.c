#include <stdio.h>
#include <math.h>

#define N 4   // You can change this to any size

int board[N]; // board[i] = column position of queen in row i

// Check if placing queen at (row, col) is safe
int isSafe(int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0; // Same column or same diagonal
    }
    return 1;
}

// Print solution
void printSolution() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i] == j)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Backtracking function
void solveNQueens(int row) {
    int col;
    if (row == N) {
        printSolution(); // Found a valid arrangement
        return;
    }

    for (col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;       // Place queen
            solveNQueens(row + 1);  // Recurse for next row
        }
    }
}

int main() {
    printf("Solutions for %d-Queens problem:\n\n", N);
    solveNQueens(0);
    return 0;
}

