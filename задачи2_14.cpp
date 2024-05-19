#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Cell {
    int x, y; 
    Cell(int _x, int _y) : x(_x), y(_y) {}
};

// Функция для проверки, находится ли клетка в пределах доски
bool isValid(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

// Функция для определения минимального количества ходов коня от начальной до конечной клетки
int minKnightMoves(Cell start, Cell end, vector<vector<bool>>& blackCells) {
    // Массив смещений для возможных ходов коня
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    // Создаем очередь для обхода клеток
    queue<pair<Cell, int>> q;
    q.push({start, 0}); // начальная клетка с 0 шагов

    // Массив для отслеживания посещенных клеток
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Cell curr = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (curr.x == end.x && curr.y == end.y) {
            return steps;
        }
        for (int i = 0; i < 8; ++i) {
            int nextX = curr.x + dx[i];
            int nextY = curr.y + dy[i];
          
  if (isValid(nextX, nextY) && !visited[nextX][nextY] && !blackCells[nextX][nextY]) {
                q.push({{nextX, nextY}, steps + 1});
                visited[nextX][nextY] = true;
            }
        }
    }
    return -1;
}
