#include <iostream>

using namespace std;
class Date {
    private: 
    int year;
    int month; 
    int day; 

    public:
    void SetDate(int _year, int _month, int _date) {
        year = _year;
        month = _month;
        day = _date;
    }
    
    void AddDay(int inc) { // 1 부터 31 까지
        if((day + inc) > 31) {
            AddMonth(1);
            day += (inc - 31);
        }
        else {
            day += inc;
        }
    }

    void AddMonth(int inc) { // 1 부터 12 까지
        if((month + inc) > 12) {
            month += (inc - 12);
            year += 1;
        }
        else {
            month += inc;
        }
    }

    void AddYear(int inc) {
        year += inc;
    }

    void ShowDate() {
        cout << year << "-" << month << "-" << day << endl; //year-month-day
    }    
};

int main() {
    Date date;
    
    date.SetDate(2002, 11, 27);
    date.ShowDate();
    date.AddMonth(2);
    date.ShowDate();
    date.AddDay(10);
    date.ShowDate();

    return 0;
}
