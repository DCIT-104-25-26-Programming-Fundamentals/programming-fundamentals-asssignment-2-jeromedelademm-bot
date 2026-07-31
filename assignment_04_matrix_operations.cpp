// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;














#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to read matrix elements from the user
void readMatrix(int A[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\n--- Entering elements for Matrix " << name << " (" << rows << "x" << cols << ") ---\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
}

// Helper function to display a matrix in a aligned grid format
void printMatrix(const int A[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << A[i][j];
        }
        cout << endl;
    }
}

// PART A — Transpose a Matrix
void transposeMatrix(const int A[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// PART B — Add Two Matrices (Element-wise)
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C — Multiply Two Matrices (A is M x N, B is N x P)
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0; // Initialize cell accumulator
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    
    cout << "========================================" << endl;
    cout << "       MATRIX OPERATIONS PROGRAM        " << endl;
    cout << "========================================" << endl;
    cout << "1. Transpose a Matrix (Part A)" << endl;
    cout << "2. Add Two Matrices (Part B)" << endl;
    cout << "3. Multiply Two Matrices (Part C)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A: TRANSPOSE ---
        int rows, cols;
        cout << "\nEnter number of rows (1-10): ";
        cin >> rows;
        cout << "Enter number of columns (1-10): ";
        cin >> cols;

        if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rows, cols, "A");

        transposeMatrix(A, result, rows, cols);

        cout << "\nOriginal Matrix (" << rows << "x" << cols << "):\n";
        printMatrix(A, rows, cols);

        cout << "\nTransposed Matrix (" << cols << "x" << rows << "):\n";
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        // --- PART B: ADDITION ---
        int rows, cols;
        cout << "\nEnter number of rows (1-10): ";
        cin >> rows;
        cout << "Enter number of columns (1-10): ";
        cin >> cols;

        if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE) {
            cout << "Error: Dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rows, cols, "A");
        readMatrix(B, rows, cols, "B");

        addMatrices(A, B, result, rows, cols);

        cout << "\nMatrix A:\n";
        printMatrix(A, rows, cols);

        cout << "\nMatrix B:\n";
        printMatrix(B, rows, cols);

        cout << "\nResultant Matrix (A + B):\n";
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        // --- PART C: MULTIPLICATION ---
        int M, N, N_check, P;
        
        cout << "\n[Matrix A] Enter number of rows (M): ";
        cin >> M;
        cout << "[Matrix A] Enter number of columns (N): ";
        cin >> N;

        cout << "[Matrix B] Enter number of rows (N): ";
        cin >> N_check;
        cout << "[Matrix B] Enter number of columns (P): ";
        cin >> P;

        // Check dimension compatibility: columns of A must match rows of B
        if (N != N_check) {
            cout << "Error: Matrix multiplication impossible! Columns of A (" << N 
                 << ") must equal rows of B (" << N_check << ")." << endl;
            return 1;
        }

        if (M < 1 || M > MAX_SIZE || N < 1 || N > MAX_SIZE || P < 1 || P > MAX_SIZE) {
            cout << "Error: All dimensions must be between 1 and 10." << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE];
        int B[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        readMatrix(A, M, N, "A");
        readMatrix(B, N, P, "B");

        multiplyMatrices(A, B, result, M, N, P);

        cout << "\nMatrix A (" << M << "x" << N << "):\n";
        printMatrix(A, M, N);

        cout << "\nMatrix B (" << N << "x" << P << "):\n";
        printMatrix(B, N, P);

        cout << "\nProduct Matrix (A x B, " << M << "x" << P << "):\n";
        printMatrix(result, M, P);

    } else {
        cout << "Invalid choice program terminating." << endl;
    }

    return 0;
}
