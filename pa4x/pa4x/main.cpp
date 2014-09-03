////
////  main.cpp
////  pa4x
////
////  Created by Tyler Weimin Ouyang on 8/27/14.
////  Copyright (c) 2014 FT: Felicia Truong & Tyler Weimin Ouyang. All rights reserved.
////
//#include <iostream>
//
//using std::cout;
//
//// To compile it with "override" keywords present, you
//// will need a compiler that supports C++11. g++ supports
//// "override" starting from version 4.7.
//
//class Shape {
//public:
//    virtual void draw() { cout << "Shape::draw()\n"; }
//};
//
//class Triangle : public Shape {
//public:
//    void draw() override { cout << "Triangle::draw()\n"; }
//};
//
//class Circle : public Shape {
//public:
//    void draw() override { cout << "Circle::draw()\n"; }
//};
//
//int main() {
//    Triangle triangle;
//    Circle circle;
//    
//    Shape shape1(triangle);
//    shape1.draw();
//    cout << "-------------------------------\n\n";
//    
//    Shape &shape2 = circle;
//    shape2.draw();
//    cout << "-------------------------------\n\n";
//    
//    Shape *pshape3 = &triangle;
//    pshape3->draw();
//    cout << "-------------------------------\n\n";
//    
//    return 0;
//}