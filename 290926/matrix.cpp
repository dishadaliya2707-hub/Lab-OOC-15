#include <iostream>
using namespace std;
class Matrix {
private:
    int mat[10][10];
    int rows, cols;
public:
    Matrix(int r = 0, int c = 0) {
        rows = r;
        cols = c;
    }
    void accept() {
        cout << "Enter elements for " << rows << "x" << cols << " matrix:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> mat[i][j];
            }
        }
    }
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
    Matrix operator+(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix addition not possible (Dimensions mismatch)!\n";
            return Matrix(0, 0);
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return temp;
    }
    Matrix operator-(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            cout << "Matrix subtraction not possible (Dimensions mismatch)!\n";
            return Matrix(0, 0);
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp.mat[i][j] = mat[i][j] - m.mat[i][j];
            }
        }
        return temp;
    }
    bool operator==(const Matrix& m) {
        if (rows != m.rows || cols != m.cols) {
            return false;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] != m.mat[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows and columns for matrices: ";
    cin >> r >> c;
    Matrix m1(r, c), m2(r, c);
    cout << "\n--- Input Matrix 1 ---\n";
    m1.accept();
    cout << "\n--- Input Matrix 2 ---\n";
    m2.accept();
    cout << "\nMatrix 1:\n";
    m1.display();
    cout << "\nMatrix 2:\n";
    m2.display();
    Matrix mAdd = m1 + m2;
    cout << "\nResult of Addition (Matrix 1 + Matrix 2):\n";
    mAdd.display();
    Matrix mSub = m1 - m2;
    cout << "\nResult of Subtraction (Matrix 1 - Matrix 2):\n";
    mSub.display();
    if (m1 == m2) {
        cout << "\nComparison Result: Both matrices are EQUAL.\n";
    } else {
        cout << "\nComparison Result: Both matrices are NOT EQUAL.\n";
    }
    return 0;
}