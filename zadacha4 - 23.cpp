#include <iostream>
using namespace std;
struct Point 
{
   double x, y;
};
struct Line 
{
   Point start, end;
};
bool pointInTriangle(Point A, Point B, Point C, Point P) 
{
   Line AB = {A, B};
   Line BC = {B, C};
   Line CA = {C, A};
   // Проверяем, что точка P лежит по одну сторону от каждой из сторон треугольника
   return (((AB.end.x - AB.start.x) * (P.y - AB.start.y) - (AB.end.y - AB.start.y) * (P.x - AB.start.x) >= 0) &&
           ((BC.end.x - BC.start.x) * (P.y - BC.start.y) - (BC.end.y - BC.start.y) * (P.x - BC.start.x) >= 0) &&
           ((CA.end.x - CA.start.x) * (P.y - CA.start.y) - (CA.end.y - CA.start.y) * (P.x - CA.start.x) >= 0));
}
int main() 
{
   Point A = {0, 0};
   Point B = {4, 0};
   Point C = {2, 3};
   Point P = {2, 1};
   //~ if (pointInTriangle(A, B, C, P)) 
   //~ {
      //~ cout << "Точка P принадлежит треугольнику ABC" << endl;
   //~ }
   //~ else 
   //~ {
      //~ cout << "Точка P не принадлежит треугольнику ABC" << endl;
   //~ }
   return 0;
}