#include <iostream>
#include "MyString_class.h"
#include <vector>
using namespace std;



int main() {
    MyString parent("ababacabacaabacaaba");
    MyString pattern("abacaaba");
    parent.KMP(pattern);
    return 0;
}
