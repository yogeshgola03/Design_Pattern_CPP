//Strategy Pattern - defines a family of interchangeable algorithms and allows them to be used interchangeably within a context
//Enables the algorithm to be selected at runtime, providing flexibility and promoting code reusability
#include <iostream>
#include <vector>
using namespace std;
class SortingMethod {
    public:
    virtual void sort(vector<int> &arr) = 0;
};
class BubbleSort : public SortingMethod {
    public:
    void sort(vector<int> &arr) override {
        cout << "Array sorted using Bubble Sort Method" << endl;
    }
};
class QuickSort : public SortingMethod {
    public:
    void sort(vector<int> &arr) override {
        cout << "Array sorted using Quick Sort Method" << endl;
    }
};
class SortContext {
    private:
    SortingMethod* sortingMethod_;
    public:
    SortContext() : sortingMethod_(nullptr) {}
    void setSortingMethod(SortingMethod* sortingMethod) {
        sortingMethod_ = sortingMethod;
    }
    void sort(vector<int> &arr) {
        if(sortingMethod_ == nullptr) {
            cout << "Set Sorting Method !!!" << endl;
            return;
        }
        sortingMethod_->sort(arr);
    }
};

int main() {
    BubbleSort bubbleSort;
    QuickSort quickSort;
    SortContext sortContext;

    vector<int> data = { 5, 2, 7, 1, 9 };
    sortContext.sort(data);

    sortContext.setSortingMethod(&quickSort);
    sortContext.sort(data);

    sortContext.setSortingMethod(&bubbleSort);
    sortContext.sort(data);
    return 0;
}