//Bridge Pattern - used to separate an object's abstraction from its implementation
//Useful when we need to avoid a permanent binding between an abstraction and its implementation
//Promotes flexibility and allows us to change both the abstraction and the implementation independently
#include <iostream>
using namespace std;

class DrawType {
    public:
    virtual void make() = 0; 
};

class Method1 : public DrawType {
    public:
    void make() override {
        cout << "Make Using Method 1 \n";
    }
};

class Method2 : public DrawType {
    public:
    void make() override {
        cout << "Make Using Method 2 \n";
    }
};

class Shape {
    public:
    virtual void draw() = 0; 
};

class Circle : public Shape {
    private:
    DrawType &method;
    public:
    Circle(DrawType& type) : method(type) {}
    void draw() override {
        cout << "Draw Circle : ";
        method.make();
    }
};

class Square : public Shape {
    private:
    DrawType &method;
    public:
    Square(DrawType& type) : method(type) {}
    void draw() override {
        cout << "Draw Square : ";
        method.make();
    }
};

int main() {
    Method1 method1;
    Method2 method2;

    Circle C = Circle(method1);
    Square S = Square(method2);

    C.draw();
    S.draw();

    return 0;
}