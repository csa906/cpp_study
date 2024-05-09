#include <iostream>
using namespace std;

void add(int a, int b)
{
    a += b;
}

int main()
{
    int a = 10;
    int b = 20;

    add(a, b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}