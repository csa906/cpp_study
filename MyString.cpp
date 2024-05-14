#include <iostream>
#include "MyString_class.h"
#include <vector>
using namespace std;


int main() {
    MyString str1("a word");
    MyString str2("sentence");
    MyString str3(str2);
    
    cout << (str1 == str2) << endl;
    cout << (str2 == str3) << endl;
    return 0;
}
