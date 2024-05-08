#include <iostream>
using namespace std;

class Date {
    private:
    int year;
    int month;
    int day;
    
    public:
    void SetDate(int _year, int _month, int _day);
    void AddDay(int inc);
    void AddMonth(int inc);
    void AddYear(int inc);
    void ShowDate();
    int GetCurrentMonthTotalDays();

    Date(int _year, int _month, int _day) {
        year = _year;
        month = _month;
        day = _day;
    }
};

void Date::SetDate(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}

void Date::AddDay(int inc) {
    day += inc;
    while(day > GetCurrentMonthTotalDays()) {
        day -= GetCurrentMonthTotalDays();
        AddMonth(1);
    }
}

void Date::AddMonth(int inc) {
    month += inc;
    while(month > 12) {
        month -= 12;
        AddYear(1);
    }
}

void Date::AddYear(int inc) {
    year += inc;
}

void Date::ShowDate() {
    cout << year << "-" << month << "-" << day << endl;
}

int Date::GetCurrentMonthTotalDays() {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                return 29;
            }
            else {
                return 28;
            }
    }
}