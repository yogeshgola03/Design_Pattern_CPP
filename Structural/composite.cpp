//Composite Pattern - Treat individual object (Leaves) and composition of objects (composites) uniformly through common interface
//used when a tree-like structure and we want to treat singe object and group of object same way
#include <iostream>
#include <vector>
using namespace std;
class PageObject {
    public:
    virtual void Add(PageObject p) {

    }
    virtual void Remove() {

    }
};

class Page : public PageObject {
    public:
    void Add(PageObject p) {
        cout << "something added to page\n";
    }
    void Remove() {
        cout << "something removed from page\n";
    }
};

class NoteBook : public PageObject {
    vector<PageObject> noteBookPages;
    public:
    void AddPage(PageObject p) {
        noteBookPages.push_back(p);
    }
    void Add(PageObject p) {
        cout << "something added to notebook\n";
    }
    void Remove() {
        cout << "something removed from notebook\n";
    }
};

int main() {
    Page a;
    Page b;
    NoteBook copy;
    copy.AddPage(a);
    copy.AddPage(b);

    copy.Add(a);
    a.Add(b);

    copy.Remove();
    b.Remove();
    return 0;
}