#include <iostream>
#include <vector>
#include <list>


using namespace std;

class SparseMatrix {
private:
    int rows;
    int cols;
    vector<list<pair<int, double>>> matrix;

public:
    // Конструктор
    SparseMatrix(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows);
    }

    // Метод для получения элемента матрицы
    double get(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout << "Некорректные индексы." << endl;
            return 0; 
        }
        for (auto& pair : matrix[i]) {
            if (pair.first == j) {
                return pair.second; 
            }
        }
        return 0; 
    }

    // Метод для изменения (добавления) ненулевого элемента
    void set(int i, int j, double v) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            cout << "Некорректные индексы." << endl;
            return;
        }
        // Ищем элемент с индексом j в списке i-й строки
        for (auto& pair : matrix[i]) {
            if (pair.first == j) {
                pair.second = v; 
                return;
            }
        }
        matrix[i].push_back(make_pair(j, v));
    }
};

/*Операция сложения (+):
        ◦ Каждая строка обрабатывается один раз, и все ненулевые элементы двух строк суммируются.
        ◦ Сложность: O(K), где K - общее количество ненулевых элементов.
       Операция умножения ∗:
        ◦ Для каждой строки первой матрицы обрабатываются все ненулевые элементы, которые умножаются на все ненулевые элементы соответствующих столбцов второй матрицы.
        ◦ Сложность: O(K^2), где K - общее количество ненулевых элементов.
Время поиска в get:
    • В get используется линейный поиск, что добавляет O(k) к времени выполнения, где k - количество ненулевых элементов в соответствующей строке. В худшем случае это O(K/rows), но в общем случае это все еще O(K).*/
