// Ankit Vishwakarma 
#include <iostream>
using namespace std;

// Function to check if a queen can be placed at a specific row and column
bool isSafe(int** board, int N, int row, int col) {
    // Check for queens in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }

    // Check for queens in diagonals (upward)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check for queens in diagonals (downward)
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(int** board, int N, int col) {
    // Base case: If all queens are placed (all columns are filled)
    if (col >= N)
        return true;

    // Try placing queen in all possible rows of this column
    for (int i = 0; i < N; i++) {
        // Check if queen can be placed safely in this row
        if (isSafe(board, N, i, col)) {
            // Place the queen in this row
            board[i][col] = 1;

            // Recursively try placing queens in subsequent columns
            if (solveNQueens(board, N, col + 1))
                return true;

            // If placing queen in current row and moving to next column doesn't lead to a solution,
            // backtrack and remove queen from this row
            board[i][col] = 0;
        }
    }

    // If no safe position is found in current column, then return false
    return false;
}

// Function to print the N Queens solution
void printSolution(int** board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;

    // Solve for 4-Queens
    N = 4;
    int** board4 = new int*[N];
    for (int i = 0; i < N; i++) {
        board4[i] = new int[N];
        for (int j = 0; j < N; j++) {
            board4[i][j] = 0;
        }
    }

    if (solveNQueens(board4, N, 0)) {
        cout << "Solution for " << N << " Queens:" << endl;
        printSolution(board4, N);
    } else {
        cout << "Solution does not exist for " << N << " Queens." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < N; i++) {
        delete[] board4[i];
    }
    delete[] board4;

    cout << endl;

    // Solve for 8-Queens
    N = 8;
    int** board8 = new int*[N];
    for (int i = 0; i < N; i++) {
        board8[i] = new int[N];
        for (int j = 0; j < N; j++) {
            board8[i][j] = 0;
        }
    }

    if (solveNQueens(board8, N, 0)) {
        cout << "Solution for " << N << " Queens:" << endl;
        printSolution(board8, N);
    } else {
        cout << "Solution does not exist for " << N << " Queens." << endl;
    }

    // Deallocate memory
    for (int i = 0; i < N; i++) {
        delete[] board8[i];
    }
    delete[] board8;

    return 0;
}
