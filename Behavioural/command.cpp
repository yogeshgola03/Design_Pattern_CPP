//Command Pattern - Focuses on encapsulating a request as an object,
//thereby decoupling the sender of the request from the receiver
#include <iostream>
using namespace std;
class Receiver {
    public:
    void performAction() {
        cout << "Receiver is performing action\n";
    }
};

class Command {
    public:
    virtual void execute()= 0;
};

class RequestCommand : public Command {
    private:
    Receiver &receiver;
    public:
    RequestCommand(Receiver &rec) : receiver(rec) {}
    void execute () override {
        receiver.performAction();
    }
};

class Sender {
    private:
    Command* command;
    public:
    void setCommand(Command* cmd) {
        command = cmd;
    }
    void executeCommand() {
        command->execute();
    }
};

int main() {
    Receiver rec;
    Command* cmd = new RequestCommand(rec);
    Sender sender;
    sender.setCommand(cmd);
    sender.executeCommand();
    delete cmd;
    return 0;
}