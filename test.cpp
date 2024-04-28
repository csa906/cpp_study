#include <iostream>
#include <typeinfo>

using namespace std;

// int main() {
//     int arr[3] = {1, 2, 3};
//     cout << arr[0] << arr[1] << arr[2] << endl;
    
//     int (&ref)[3] = arr;
//     ref[0] = 3;
//     ref[1] = 2;
//     ref[2] = 1;
//     cout << arr[0] << arr[1] << arr[2] << endl;

//     return 0;
// }

int main() {
    int a = 4;
    {
        cout << a << endl;
        int a = 3;
        cout << a <<endl;
    }
    cout << a << endl;

    

    return 0;
}