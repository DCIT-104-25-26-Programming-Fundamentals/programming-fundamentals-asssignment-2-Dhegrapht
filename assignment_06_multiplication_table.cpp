// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

// PART A: Prints the multiplication table for a single number (1 to 12)
void printTable(int num) {
    // TODO: loop i from 1 to 12
    // print: num << " x " << i << " = " << (num * i)
}

// PART B: Prints multiplication tables for every number from 1 to n
void printAllTables(int n) {
    if (n <= 0) {
        cout << "Error: N must be a positive integer." << endl;
        return;
    }

    // TODO: loop from 1 to n
    // inside the loop:
    //   - print "Multiplication Table for X:"
    //   - call printTable(X) to reuse the function you already wrote
    //   - print a separator line like "---------------------------"
}

int main() {
    // ---------- PART A ----------
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Multiplication Table for " << num << ":" << endl;
    printTable(num);

    // ---------- PART B ----------
    int n;
    cout << "\nEnter N (for tables 1 to N): ";
    cin >> n;

    printAllTables(n);

    return 0;
}