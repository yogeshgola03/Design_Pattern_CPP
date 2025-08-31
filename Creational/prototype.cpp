//Prototype Pattern - focuses on creating objects by copying an existing object, which we call the Prototype
#include <iostream>
using namespace std;
class Shape {
    public:
    virtual Shape* clone() = 0;
    virtual void printShape() = 0;
};

class Circle : public Shape {
    private:
    float radius;

    public:
    Circle(const float r) {
        radius = r;
    }
    void printShape() override {
        cout << "Circle - Radius : " << radius << endl;
    }
    Shape* clone() override {
        return new Circle(*this);
    }
};

class Square : public Shape {
    private:
    float side;

    public:
    Square(const float s) {
        side = s;
    }
    void printShape() override {
        cout << "Square - Side : " << side << endl;
    }
    Shape* clone() override {
        return new Square(*this);
    }
};

int main() {
    Circle circlePrototype = Circle(5.5);
    Square squarePrototype = Square(2.5);

    Shape* s1 = circlePrototype.clone();
    Shape* s2 = squarePrototype.clone();
    Shape* s3 = circlePrototype.clone();
    Shape* s4 = squarePrototype.clone();

    s1->printShape();
    s2->printShape();
    s3->printShape();
    s4->printShape();

    return 0;
}