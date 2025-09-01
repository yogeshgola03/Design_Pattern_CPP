//Decorator Pattern - enables the dynamic addition of new behaviors/responsibilities to individual objects
//It achieves this without altering the underlying class structure
//Creates a set of decorator classes that are used to wrap concrete components, which represent the core functionality
#include <iostream>
using namespace std;

class IceCream {
    public:
    virtual string getDescription() = 0;
    virtual float getCost() = 0;
};

class VanillaIceCream : public IceCream {
    public:
    string getDescription() override {
        return "Vanilla Ice Cream";
    }
    float getCost() override {
        return 10.0;
    }
};

class ChocolateIceCream : public IceCream {
    public:
    string getDescription() override {
        return "Chocolate Ice Cream";
    }
    float getCost() override {
        return 15.0;
    }
};

class IceCreamDecorator : public IceCream {
    protected:
    IceCream *iceCream_;
    public:
    IceCreamDecorator(IceCream *iceCream) : iceCream_(iceCream) {}
    string getDescription() override {
        return iceCream_->getDescription();
    }
    float getCost() override {
        return iceCream_->getCost();
    }
};

class CreamDecorator : public IceCreamDecorator {
    public:
    CreamDecorator(IceCream *iceCream) : IceCreamDecorator(iceCream) {}
    string getDescription() override {
        return iceCream_->getDescription() + " with Extra Cream";
    }
    float getCost() override {
        return iceCream_->getCost() + 10.0f;
    }
};

class DryFruitDecorator : public IceCreamDecorator {
    public:
    DryFruitDecorator(IceCream *iceCream) : IceCreamDecorator(iceCream) {}
    string getDescription() override {
        return iceCream_->getDescription() + " with Dry Fruit";
    }
    float getCost() override {
        return iceCream_->getCost() + 15.0f;
    }
};

int main() {
    IceCream* vanillaBase = new VanillaIceCream();
    IceCream* vanillaCream = new CreamDecorator(vanillaBase);
    IceCream* vanillaCreamFruit = new DryFruitDecorator(vanillaCream);

    cout << "Order : " << vanillaBase->getDescription() << ", Cost : " << vanillaBase->getCost() << endl;
    cout << "Order : " << vanillaCream->getDescription() << ", Cost : " << vanillaCream->getCost() << endl;
    cout << "Order : " << vanillaCreamFruit->getDescription() << ", Cost : " << vanillaCreamFruit->getCost() << endl;

    delete vanillaBase;
    delete vanillaCream;
    delete vanillaCreamFruit;

    IceCream* chocolateBase = new ChocolateIceCream();
    IceCream* chocolateCream = new CreamDecorator(chocolateBase);
    IceCream* chocolateCreamFruit = new DryFruitDecorator(chocolateCream);

    cout << "Order : " << chocolateBase->getDescription() << ", Cost : " << chocolateBase->getCost() << endl;
    cout << "Order : " << chocolateCream->getDescription() << ", Cost : " << chocolateCream->getCost() << endl;
    cout << "Order : " << chocolateCreamFruit->getDescription() << ", Cost : " << chocolateCreamFruit->getCost() << endl;

    delete chocolateBase;
    delete chocolateCream;
    delete chocolateCreamFruit;
    return 0;
}