#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

int GetElementOfMatrix(const vector<vector<int>> &matrix, int i, int j) {
    if ((i + j) < matrix.size())
        return matrix[i][j];
    return matrix[-j + matrix.size() - 1][-i + matrix.size() - 1];
}

int main() {
    int size;
    cout << "Enter the size of matrix:";
    cin >> size;
    if (size < 0 || size > 10) {
        cout << "Error!";
        return 1;
    }
    cout << "Your empty matrix:\n";
    for (int q = size, k = 0; q >= 1; q--, k++) {
        for (int p = 0; p < q; p++)
            cout << "# ";
        for (int p = 0; p < k; p++)
            cout << "* ";
        cout << endl;
    }

    vector<vector<int>> matrix(size, vector<int>());
    cout << "How do you want to enter matrix:\n1.From keyboard\n2.With random numbers\n";
    int operation;
    cin >> operation;
    srand(time(0));
    switch (operation) {
        case 1: {
            cout << "Enter empty matrix elements(#) from keyboard line by line:\n";
            for (int i = size - 1, k = 0; i >= 0; i--, k++) {
                for (int j = 0; j <= i; ++j) {
                    int val;
                    cin >> val;
                    matrix[k].push_back(val);
                }
            }
            break;
        }
        case 2: {
            for (int i = size - 1, k = 0; i >= 0; i--, k++) {
                for (int j = 0; j <= i; ++j) {
                    matrix[k].push_back(rand());
                }
            }
            break;
        }
    }

    cout << "Your source matrix:\n";

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setw(5) << left << GetElementOfMatrix(matrix, i, j) << " ";
        }
        cout << endl;

    }
    for (int i = 0; i < size; i++) {
        int proizv = GetElementOfMatrix(matrix, i, 0);
        int negative_amount = 0;
        if (GetElementOfMatrix(matrix, i, 0) < 0)
            negative_amount++;
        for (int k = 1; k < size; k++) {
            proizv = proizv * GetElementOfMatrix(matrix, i, k);
            if (GetElementOfMatrix(matrix, i, k) < 0)
                negative_amount++;
        }
        if (negative_amount == 0)
            cout << "Composition of elements in row " << i + 1 << " without negative elements: " << proizv << "\n";
    }

    int min_sum =
            GetElementOfMatrix(matrix, 0, size - 1) < GetElementOfMatrix(matrix, size - 1, 0) ? GetElementOfMatrix(
                    matrix, 0, size - 1) : GetElementOfMatrix(matrix, size - 1, 0);
    for (int q = size - 2; q >= 1; q--) {
        int sum_top = 0, sum_bottom = 0;
        for (int p = q, k = 0; p < size; p++, k++) {
            sum_top += GetElementOfMatrix(matrix, k, p);
            sum_bottom += GetElementOfMatrix(matrix, p, k);
        }
        int min_of_two = (sum_bottom < sum_top ? sum_top : sum_bottom);
        if (min_sum > min_of_two)
            min_sum = min_of_two;
    }
    cout << "The minimum among the sums of elements of diagonals parallel to the main diagonal of the matrix:"
         << min_sum;
}
