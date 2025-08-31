// Singleton - ensures a class has only one instance throughout the entire program
// Provides a global point of access to that instance, useful when need only one object
#include<iostream>
using namespace std;

class Singleton {
    private:
    static Singleton* instance;
    Singleton() {
        cout << "Constructor Called !!!\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton1 = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    Singleton* singleton3 = Singleton::getInstance();
    cout << (singleton1 == singleton2) << endl;
    cout << (singleton2 == singleton3) << endl;
    cout << (singleton3 == singleton1) << endl;
    return 0;
}

// The class has a private constructor and a static pointer to ensure only one instance is created
// The getInstance() method checks if the instance exists; if not, it creates and returns it
// Copy constructor and assignment operator are deleted to prevent copying the Singleton instance