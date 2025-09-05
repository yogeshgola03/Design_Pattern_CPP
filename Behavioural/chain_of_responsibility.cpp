//Chain Of Responsibility - Allows an object to send a request to other objects without knowing who is going to handle
//Used in the chain of multiple objects, where each object either handles the request or passes it on to the next object in the chain if it is unable to handle that request
#include <iostream>
using namespace std;
class AuthenticationHandler {
    public:
    virtual void setNextHandler(AuthenticationHandler* handler) = 0;
    virtual void handleRequest(const string &msg) = 0;
};
class UsernamePasswordAuth : public AuthenticationHandler {
    private:
    AuthenticationHandler* next_handler;
    public:
    UsernamePasswordAuth() : next_handler(nullptr) {}
    void setNextHandler(AuthenticationHandler* handler) override {
        next_handler = handler;
    }
    void handleRequest(const string &msg) override {
        if(msg == "username_password") {
            cout << "Authenticated using Username Password\n";
        } else if (next_handler != nullptr) {
            next_handler->handleRequest(msg);
        } else {
            cout << "Invalid Authentication\n";
        }
    }
};
class OAuth : public AuthenticationHandler {
    private:
    AuthenticationHandler* next_handler;
    public:
    OAuth() : next_handler(nullptr) {}
    void setNextHandler(AuthenticationHandler* handler) override {
        next_handler = handler;
    }
    void handleRequest(const string &msg) override {
        if(msg == "oauth_token") {
            cout << "Authenticated using OAuth Token\n";
        } else if (next_handler != nullptr) {
            next_handler->handleRequest(msg);
        } else {
            cout << "Invalid Authentication\n";
        }
    }
};
int main() {
    AuthenticationHandler* user_passwd_auth = new UsernamePasswordAuth();
    AuthenticationHandler* oauth_token = new OAuth();
    user_passwd_auth->setNextHandler(oauth_token);
    user_passwd_auth->handleRequest("oauth_token");
    user_passwd_auth->handleRequest("username_password");
    user_passwd_auth->handleRequest("invalid_method");
    delete user_passwd_auth;
    delete oauth_token;
    return 0;
}