#include <iostream>
#include <vector>

using namespace std;

void gaussianElimination(vector<vector<double>>& A, vector<double>& b) {
    setlocale(LC_ALL, "rus");
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[maxRow][i])) {
                maxRow = j;
            }
        }
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        for (int j = i + 1; j < n; j++) {
            double factor = A[j][i] / A[i][i];
            b[j] -= factor * b[i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
        }
    }

    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i] / A[i][i];
        for (int j = i - 1; j >= 0; j--) {
            b[j] -= A[j][i] * x[i];
        }
    }

    cout << "Решение: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Введите количество неизвестных: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Введите коэфиценты расширеной матрицы построчно: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }

    gaussianElimination(A, b);


    return 0;
}
