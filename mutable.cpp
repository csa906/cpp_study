#include <iostream>
using namespace std;

class A{
    private: 
        mutable int data;
    
    public:
        A(int value) : data(value) {} 
        void ChangeData(int value) const;
        void PrintData() const;
};

void A::ChangeData(int value) const {
    data = value;
}

void A::PrintData() const {
    cout << data << endl;
}
int main() {
    A a(10);
    a.PrintData();

    a.ChangeData(5);
    a.PrintData();
    
    return 0;
}