// Adapter Pattern - used to make two incompatible interfaces work together
// Acts as a bridge between two incompatible interfaces, allowing them to collaborate without modifying source code
// Useful when integrating legacy code or third-party libraries into your application
#include <iostream>
using namespace std;

//Accept text only in upper case
class LegacyPrinter {
    public:
    void printInUpperCase(const string& text){
        cout << "Printing : " << text << endl;
    }
};

//Send command only in lower case
class ModernComputer {
    public:
    void sendCommand(const string& command) {
        cout << "Sending : " << command << endl;
    }
};

//Adapter to send convert data from lower case to upper case
class PrinterAdapter {
    private:
    LegacyPrinter printer;
    public:
    void sendCommand(const string& command) {
        string str;
        for(int i=0; i<command.size(); i++) {
            if(command[i] >= 'a' && command[i] <= 'z') {
                str.push_back(command[i] - ('a' - 'A'));
            } else {
                str.push_back(command[i]);
            }
        }
        printer.printInUpperCase(str);
    }
};

int main() {
    string data = "hello world !!!";
    ModernComputer computer;
    PrinterAdapter adapter;
    computer.sendCommand(data);
    adapter.sendCommand(data);
    return 0;
}