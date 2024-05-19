#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minStepsToN(int N) {
    if (N == 1)
        return 0;

    vector<int> steps(N + 1, -1); 
    steps[1] = 0; 

    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Перебираем делители текущего числа
        for (int i = 2; i <= curr; ++i) {
            if (curr % i == 0) {
                int next = curr + i;
                if (next <= N && steps[next] == -1) {
                    steps[next] = steps[curr] + 1;
                    q.push(next);
                }
                next = curr + curr / i;
                if (next <= N && steps[next] == -1) {
                    steps[next] = steps[curr] + 1;
                    q.push(next);
                }
            }
        }

        // Добавляем число curr + 1
        int next = curr + 1;
        if (next <= N && steps[next] == -1) {
            steps[next] = steps[curr] + 1;
            q.push(next);
        }
    }

    return steps[N];
}


