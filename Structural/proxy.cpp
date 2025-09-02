//Proxy Pattern - provides placeholder for another object, allowing you to control access to it
//Useful in situations where we need to add an extra layer of control, lazy loading, or remote access to objects
#include <iostream>
using namespace std;
class Image {
    public:
    virtual void display() = 0;
};

class RealImage : public Image {
    string filename_;
    public:
    RealImage(const string filename) : filename_(filename) {
        cout << "Loading Image : " << filename_ << endl;
    }
    void display() override {
        cout << "Display Image : " << filename_ << endl;
    }
};

class ImageProxy : public Image {
    RealImage* realImage;
    string filename_;
    public:
    ImageProxy(const string filename) : filename_(filename), realImage(nullptr) {}
    void display() override {
        if(realImage == nullptr) {
            realImage = new RealImage(filename_);
        }
        realImage->display();
    }
};

int main() {
    // Create a proxy to an image
    Image* image = new ImageProxy("example.jpg");
    // Display the image (the Proxy will load the Real Object if necessary)
    image->display();
    // Displaying the image again (the Proxy won't reload it)
    image->display();
    // Displaying the image again (the Proxy won't reload it)
    image->display();
    delete image; // Clean up
    return 0;
}