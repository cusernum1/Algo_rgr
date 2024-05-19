#include <iostream>
#include <vector>

using namespace std;

// Проверка находится ли данная вершина внутри границ матрицы
bool isValid(int i, int j, int rows, int cols) {
    return (i >= 0 && i < rows && j >= 0 && j < cols);
}

// DFS для поиска компоненты связности
void dfs(vector<vector<char>>& matrix, int i, int j, char target, vector<vector<bool>>& visited) {
    // Помечаем текущую клетку как посещенную
    visited[i][j] = true;

    // Проверяем соседние клетки
    static const int dr[] = {-1, 0, 1, 0};
    static const int dc[] = {0, -1, 0, 1};
    for (int k = 0; k < 4; ++k) {
        int ni = i + dr[k];
        int nj = j + dc[k];
        if (isValid(ni, nj, matrix.size(), matrix[0].size()) && matrix[ni][nj] == target && !visited[ni][nj]) {
            dfs(matrix, ni, nj, target, visited);
        }
    }
}

// Функция для подсчета числа компонент связности
int countConnectedComponents(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Массив для отслеживания посещенных вершин
    int count = 0; // Счетчик компонент связности

    // Проходим по каждой клетке матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!visited[i][j]) {
                // Если клетка не посещена, запускаем DFS из неё
                dfs(matrix, i, j, matrix[i][j], visited);
                ++count; // Увеличиваем счетчик компонент связности
            }
        }
    }

    return count;
}
