#include <iostream>

// Функция бинарного возведения в степень по модулю M
int bpow(int a, int n, int M) {
    int res = 1;
    a = a % M; // Чтобы результат не превышал M с самого начала
    while (n > 0) {
        if (n % 2 == 1) { // Если n нечетное
            res = (res * a) % M;
        }
        a = (a * a) % M; // Квадрат числа по модулю M
        n /= 2; // Делим n на 2
    }
    return res;
}
