//Tight Coupling - classes depend directly on each other's implementation
//Loose Coupling - classes depend on abstraction, making code flexible, mantainable & reusable

//Factory Method - Use to simplify creation of object
//Reduce tight coupling, hide class details, allow different types of object creation through common interface

#include<iostream>
using namespace std;

class Shape {
    public:
    virtual void printShape() = 0;
};

class Circle : public Shape {
    public:
    void printShape() override {
        cout << "Shape - Circle\n";
    }
};

class Square : public Shape {
    public:
    void printShape() override {
        cout << "Shape - Square\n";
    }
};

class ShapeFactory {
    public: 
    virtual Shape* CreateShape() = 0;
};

class CircleFactory : public ShapeFactory {
    public:
    Shape* CreateShape() override {
        return new Circle();
    }
};

class SquareFactory : public ShapeFactory {
    public:
    Shape* CreateShape() override {
        return new Square();
    }
};

int main() {
    cout << "Factory Method\n";
    ShapeFactory* factory = new CircleFactory();
    Shape* sh = factory->CreateShape();
    sh->printShape();
    delete sh;
    delete factory;

    factory = new SquareFactory();
    sh = factory->CreateShape();
    sh->printShape();
    delete sh;
    delete factory;

    return 0;
}

// Advantages of Factory pattern
//     Loose Coupling: Client doesn’t depend on concrete classes.
//     Easy to Extend: Add new types by creating new factories.
//     Cleaner Code: Object creation logic is in one place.
//     Supports Polymorphism: You can treat all shapes uniformly.

// Disadvantages of Factory pattern
//     More Classes: One factory per product type increases class count.
//     More Complexity: Not worth using for very simple object creation.
//     Subclassing Needed: Every new type needs a new factory subclass.

// When to Use
// Use the Factory Method pattern when:
//     You have multiple types of related objects to create.
//     You want to hide creation logic from the client.
//     You need to decide object type at runtime.
//     Your object creation code may change or grow in the future.

// When Not to Use
// Avoid it when:
//     Object creation is simple and not likely to change.
//     You don’t need to hide or encapsulate object creation.
//     You're building a very small or one-time-use system.
