#include <iostream>
#include "date2_class.h"
using namespace std;

int main() {
    Date date(2002, 11, 27); // Date date = date(2002, 11, 27); 와 같은 의미

    date.ShowDate(); // 2002-11-27

    date.AddDay(5);
    date.ShowDate(); // 2002-12-02

    date.AddDay(32);
    date.ShowDate(); // 2003-1-3

    date.SetDate(2012, 1, 31);
    date.AddDay(29);
    date.ShowDate(); // 2012-2-29
    
    return 0;
}