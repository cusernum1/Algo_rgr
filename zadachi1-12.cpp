#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

class Matrix {
private:
    int rows;
    int cols;
    vector<double> data;

public:
    // Конструктор
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(numRows * numCols, 0) {}

    // Оператор доступа к элементам матрицы
    double& operator()(int i, int j) {
        return data[i * cols + j];
    }

    double operator()(int i, int j) const {
        return data[i * cols + j];
    }

    // Получение количества строк
    int getRows() const {
        return rows;
    }

    // Получение количества столбцов
    int getCols() const {
        return cols;
    }

    // Операция сложения матриц
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Ошибка: невозможно сложить матрицы разных размеров." << endl;
            return Matrix(0, 0); 
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }

        return result;
    }
};

// Функция для заполнения матрицы случайными значениями
void Random(Matrix& matrix) {
    srand(time(nullptr)); 

    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            matrix(i, j) = rand() % 100 + 1; 
        }
    }
}
