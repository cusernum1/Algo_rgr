#include <iostream>
#include <set>
#include <unordered_set>
#include <chrono>
#include <random>
#include <string>

using namespace std;
using namespace chrono;

// Генератор случайных строк длиной 16 символов
string generateStr() {
    string str;
    for (int i = 0; i < 16; ++i) {
        str.push_back('a' + rand() % 26);
    }
    return str;
}

// Функция для измерения времени добавления N элементов в set
long long setT(int N) {
    set<string> s;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        s.insert(generateStr());
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}

// Функция для измерения времени добавления N элементов в unordered_set
long long uSetT(int N) {
    unordered_set<string> us;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        us.insert(generateStr());
    }
    auto stop = high_resolution_clock::now();
    return duration_cast<nanoseconds>(stop - start).count();
}
