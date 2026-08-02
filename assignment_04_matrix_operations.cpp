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

const int MAX = 10;

void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void transpose(int matrix[MAX][MAX], int rows, int cols, int result[MAX][MAX]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX],
                       int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matrix[MAX][MAX], transposed[MAX][MAX];
    int rows, cols;

    cout << "===== PART A: Transpose =====" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    readMatrix(matrix, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    transpose(matrix, rows, cols, transposed);

    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    cout << "\n===== PART B: Matrix Addition =====" << endl;
    int A[MAX][MAX], B[MAX][MAX], sum[MAX][MAX];
    int addRows, addCols;

    cout << "Enter number of rows: ";
    cin >> addRows;
    cout << "Enter number of columns: ";
    cin >> addCols;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(A, addRows, addCols);

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(B, addRows, addCols);

    addMatrices(A, B, sum, addRows, addCols);

    cout << "\nSum Matrix:" << endl;
    printMatrix(sum, addRows, addCols);

    cout << "\n===== PART C: Matrix Multiplication =====" << endl;
    int M[MAX][MAX], N[MAX][MAX], product[MAX][MAX];
    int rowsM, colsM, rowsN, colsN;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsM;
    cout << "Enter columns of Matrix A: ";
    cin >> colsM;

    cout << "\nEnter Matrix A:" << endl;
    readMatrix(M, rowsM, colsM);

    cout << "\nEnter rows of Matrix B (must equal columns of A = " << colsM << "): ";
    cin >> rowsN;
    cout << "Enter columns of Matrix B: ";
    cin >> colsN;

    if (rowsN != colsM) {
        cout << "Error: columns of A must equal rows of B." << endl;
        return 0;
    }

    cout << "\nEnter Matrix B:" << endl;
    readMatrix(N, rowsN, colsN);

    multiplyMatrices(M, N, product, rowsM, colsM, colsN);

    cout << "\nProduct Matrix:" << endl;
    printMatrix(product, rowsM, colsN);

    return 0;
}