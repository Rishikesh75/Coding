#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n = 9;
vector<vector<int>> sudoko(9, vector<int>(9, 0));

void createSudoko() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sudoko[i][j];
        }
    }
}

void display() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << sudoko[i][j] << "\t";
        }
        cout << "\n";
    }
}

void RemoveRowValues(set<int> &values, int row) {
    for (int j = 0; j < 9; j++) {
        values.erase(sudoko[row][j]);
    }
}

void RemoveColumnValues(set<int> &values, int column) {
    for (int i = 0; i < 9; i++) {
        values.erase(sudoko[i][column]);
    }
}

void RemoveSquareValues(set<int> &values, int row, int column) {
    int startRow = (row / 3) * 3;
    int startCol = (column / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            values.erase(sudoko[i][j]);
        }
    }
}

// Backtracking function
bool Recurssion(int row, int column);

bool FindNextplace(int rowindex, int columnindex) {
    for (int i = rowindex; i < n; i++) {
        for (int j = (i == rowindex ? columnindex : 0); j < n; j++) {
            if (sudoko[i][j] == 0) { // find empty cell
                return Recurssion(i, j);
            }
        }
    }
    return true; // no empty cell found -> solved
}

bool Recurssion(int row, int column) {
    set<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    RemoveRowValues(values, row);
    RemoveColumnValues(values, column);
    RemoveSquareValues(values, row, column);

    for (auto it = values.begin(); it != values.end(); ++it) {
        sudoko[row][column] = *it;

        if (FindNextplace(row, column))
            return true; // solution found

        sudoko[row][column] = 0; // backtrack
    }

    return false; // no valid number found, backtrack
}

int main() {
    createSudoko();
    cout << "\nInitial Sudoku:\n";
    display();

    if (FindNextplace(0, 0)) {
        cout << "\nSolved Sudoku:\n";
        display();
    } else {
        cout << "\nNo solution exists.\n";
    }

    return 0;
}
