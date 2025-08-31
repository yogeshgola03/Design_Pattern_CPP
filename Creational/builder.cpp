//Builder Pattern - separate the construction of an object from its representations
//This separation enables us to create different representations of an object using the same construction process
#include <iostream>
using namespace std;

class Computer {
    private:
    string cpu_;
    string mem_;
    string storage_;
    public:
    void setCPU(const string& cpu) {
        cpu_ = cpu;
    }
    void setMem(const string& mem) {
        mem_ = mem;
    }
    void setStorage(const string& storage) {
        storage_ = storage;
    }
    void display() {
        std::cout << "CPU: " << cpu_ << std::endl;
        std::cout << "Memory: " << mem_ << std::endl;
        std::cout << "Storage: " << storage_ << std::endl;
    }
};

class ComputerBuilder {
    public:
    virtual void buildCPU(const string& cpu) = 0;
    virtual void buildMem(const string& mem) = 0;
    virtual void buildStorage(const string& storage) = 0;
    virtual Computer getResult() = 0;
};

class DesktopBuilder : public ComputerBuilder {
    private:
    Computer desktop_;

    public:
    void buildCPU(const string& cpu) override {
        desktop_.setCPU(cpu);
    }
    void buildMem(const string& mem) override {
        desktop_.setMem(mem);
    }
    void buildStorage(const string& storage) override {
        desktop_.setStorage(storage);
    }
    Computer getResult() override {
        return desktop_;
    }
};

class ComputerAssembler {
    public:
    Computer assembleComputer(ComputerBuilder& computerBuilder) {
        computerBuilder.buildCPU("Intel i7 13th gen");
        computerBuilder.buildMem("16GB");
        computerBuilder.buildStorage("1TB");
        return computerBuilder.getResult();
    }
};

int main() {
    DesktopBuilder desktopBuilder;
    ComputerAssembler computerAssembler;
    Computer desktop = computerAssembler.assembleComputer(desktopBuilder);
    cout << "Desktop Computer Configuration \n";
    desktop.display();
    return 0;
}

// Computer: The product class that we want to build
// ComputerBuilder : An abstract class defining the builder interface
// DesktopComputerBuilder: A concrete builder class implementing the ComputerBuilder interface for building desktop computers
// ComputerAssembler: The director class responsible for construction process