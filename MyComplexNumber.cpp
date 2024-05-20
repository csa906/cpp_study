#include "MyComplexNumber_class.h"

int main() { 
    Complex c1(3, 3);
    Complex c2(1, 1);

    c1 *= c2;
    c1.println();
    return 0;
}
