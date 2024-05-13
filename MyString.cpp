#include <iostream>
#include "MyString_class.h"
using namespace std;



int main() {
    MyString str1("abc");
    MyString str2("1234");

    str1.print();
    str2.print();

    str1.insert(1, "123");
    str1.print();

    str1.erase(1, 2);
    str1.print();
    return 0;
}