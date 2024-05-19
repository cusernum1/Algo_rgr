#include <iostream>
#include <cmath>

// Структура для представления точки на плоскости
struct Point {
    double x;
    double y;

    Point(double _x, double _y) : x(_x), y(_y) {}
};

// Структура для представления отрезка на плоскости
struct Segment {
    Point start;
    Point end;

    Segment(Point _start, Point _end) : start(_start), end(_end) {}
};

// Функция для расчета расстояния между двумя точками
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Функция для определения расстояния от точки до отрезка
double distanceToSegment(const Point& point, const Segment& segment) {
    Point A = segment.start;
    Point B = segment.end;
    Point P = point;

    double lengthSquaredAB = pow(B.x - A.x, 2) + pow(B.y - A.y, 2);
    double dotProduct = ((P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y)) / lengthSquaredAB;
    double distanceSquared = 0.0;
    Point C;

    if (dotProduct < 0.0) {
        C = A;
    } else if (dotProduct > 1.0) {
        C = B;
    } else {
        C = Point(A.x + dotProduct * (B.x - A.x), A.y + dotProduct * (B.y - A.y));
    }

    distanceSquared = pow(P.x - C.x, 2) + pow(P.y - C.y, 2);
    return sqrt(distanceSquared);
}
