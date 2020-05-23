#include <iostream>
#include <algorithm>
#include <cmath>
#include "Rectangle.h"
using namespace std;



void PointArray::resize(int size) {
    Point* pts = new Point[size];
    if (size > this->size) {
        copy(points, points + this->size, pts);
        //delete[] points;
        points = pts;
    }

    else {
        copy(points, points + size, pts);
        //delete[] points;
        points = pts;
    }



}

PointArray::PointArray() : size(0) {
    points = new Point[size];
}
PointArray::PointArray(const Point pts[], const int size) : size(size) {
    points = new Point[size];
    copy(pts, pts + size, points);

}
PointArray::PointArray(const PointArray& pv) : size(pv.size) {
    points = new Point[size];
    copy(pv.points, pv.points + size, points);
}

PointArray::~PointArray() {
    delete[] points;
}
void PointArray::clear() {
    resize(0);
}

void PointArray::push_back(const Point& p) {
    resize(++size);
    points[size - 1] = p;
}
void PointArray::insert(const int pos, const Point& p) {
    Point temp[100] = { 0 };
    for (int i = pos; i < size; ++i) {
        temp[i] = points[i];
    }
    points[pos] = p;
    size++;
    for (int i = pos + 1; i < size; ++i) {
        points[i] = temp[i - 1];
    }

}
void PointArray::remove(const int pos) {
    Point temp[100];
    for (int i = pos + 1; i < size; ++i) {
        temp[i] = points[i];
    }
    size--;
    for (int i = pos; i < size; ++i) {
        points[i] = temp[i + 1];
    }
}
Point* PointArray::get(const int pos) {
    return points + pos;
}
const Point* PointArray::get(const int pos) const {
    return points + pos;
}


int Polygon::numPolygons = 0;

Polygon::Polygon() {
    numPolygons++;
}
Polygon::Polygon(const PointArray& pa) {
    numPolygons++;
}
Polygon::Polygon(const Point points[], const int numPoints) {
    numPolygons++;
}



Rectangle::Rectangle(const Point& a, const Point& b) {

    x_len = abs(a.getX() - b.getX());
    y_len = abs(a.getY() - b.getY());

}
Rectangle::Rectangle(const int a, const int b, const int c, const int d) {

    x_len = abs(a - b);
    y_len = abs(a - b);
}
double Rectangle::area() const {

    return abs(this->x_len * this->y_len);
}

int main() {
    Point pt[2];
    pt[0].setX(1);
    pt[0].setY(1);
    pt[1].setX(3);
    pt[1].setY(3);

    PointArray pa(pt, sizeof(pt) / sizeof(Point));
    pa.push_back(Point(5, 5));
    pa.remove(2);
    pa.insert(1, Point(4, 4));
    //cout << pa.get(2)->getX() << " " << pa.get(2)->getY();



    for (int i = 0; i < pa.getSize(); ++i) {
        cout << pa.get(i)->getX();
    }


    Rectangle rt(Point(1, 1), Point(3, 3));
    cout << rt.area();


    return 0;
}