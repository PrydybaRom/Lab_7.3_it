#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using namespace std;

int** create(int k, int n) {
    int** matrix = new int* [k];
    for (int i = 0; i < k; ++i) {
        matrix[i] = new int[n];
    }

    srand(time(0));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 20;
        }
    }

    return matrix;
}

void print(int** matrix, int k, int n) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int countColumns(int** matrix, int k, int n) {
    int count = 0;
    for (int j = 0; j < n; ++j) {
        bool hasZero = false;
        for (int i = 0; i < k; ++i) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) {
            count++;
        }
    }
    return count;
}

void deleteM(int** matrix, int k) {
    for (int i = 0; i < k; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int k, n;

    cout << "Enter k: ";
    cin >> k;
    cout << "Enter n: ";
    cin >> n;

    int** matrix = create(k, n);

    print(matrix, k, n);

    int nonZeroColumns = countColumns(matrix, k, n);
    cout << "Count Columns without ZERO: " << nonZeroColumns << endl;

    deleteM(matrix, k);

    return 0;
}
