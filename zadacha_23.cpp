struct Point 
{
   double x;
   double y;
};
struct Circle 
{
   Point center;
   double radius;
};
struct Line 
{
   double a; 
   double b; 
   double c; 
};
vector<Line> findTangents(const Circle& circle, const Point& point) 
{
   vector<Line> tangents;
   double distanceToCenter = sqrt(pow(point.x - circle.center.x, 2) + pow(point.y - circle.center.y, 2));
   if (distanceToCenter < circle.radius) 
   {
      return tangents; 
   }
   double angle = atan2(point.y - circle.center.y, point.x - circle.center.x);
   double tangentAngle = asin(circle.radius / distanceToCenter);
   double angle1 = angle + tangentAngle;
   double angle2 = angle - tangentAngle;
   Point tangentPoint1 = 
   {
      circle.center.x + circle.radius * cos(angle1),
      circle.center.y + circle.radius * sin(angle1)
   };
   Point tangentPoint2 = 
   {
      circle.center.x + circle.radius * cos(angle2),
      circle.center.y + circle.radius * sin(angle2)
   };
   Line tangent1 = 
   {
      tangentPoint1.y - point.y,
      point.x - tangentPoint1.x,
      tangentPoint1.x * point.y - tangentPoint1.y * point.x 
   };
   Line tangent2 = 
   {
      tangentPoint2.y - point.y,
      point.x - tangentPoint2.x,
      tangentPoint2.x * point.y - tangentPoint2.y * point.x
   };
   tangents.push_back(tangent1);
   tangents.push_back(tangent2);
   return tangents;
}
