// 找点A到线段BC上的交点坐标

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Point {
public:
    float x;
    float y;
    Point(): x(0), y(0) {}
    Point(float x, float y) : x(x), y(y) {}
    Point minus(Point p1, Point p2) {
        return Point(p1.x - p2.x, p1.y - p2.y);
    }
    Point norm(Point p1) {
        float len = sqrt(p1.x * p1.x + p1.y * p1.y);
        // float len = pow(p1.x * p1.x + p1.y * p1.y, 0.5);
        return Point(p1.x / len, p1.y / len);
    }
};


int main() {
    Point b(0,0), c(0,2), a(1,1);
    
    // 单位向量
    Point diff = Point().minus(c, b);
    Point norm = Point().norm(diff);
    cout << norm.x << norm.y << endl;
    
    // 长度 点乘
    Point ba = Point().minus(a, b);
    float dot = ba.x * norm.x + ba.y * norm.y;
    cout << dot << endl;

    // 求点
    Point midDist(norm.x * dot, norm.y * dot);  
    Point mid(b.x + midDist.x, b.y + midDist.y);
    cout << mid.x << mid.y << endl;
}