#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

enum Size {
    BIGGER = 1,
    EQUAL = 0,
    SMALLER = -1
};

class MyString {
    private:
        char *string_content;
        int string_length;
        int memory_capacity;
    
    public:
        explicit MyString(int capacity); // capacity 만큼 할당
        MyString(char c); // 문자 하나로 생성
        MyString(const char *str); // 문자열로 생성
        MyString(const MyString& str); // 복사 생성자
        ~MyString();
        
        void print();
        int length() const;
        int capacity() const;
        void reserve(int size);
        char at(int i) const;

        MyString& assign(const MyString& str); // 문자열 할당
        MyString& assign(const char* str); // 문자열 할당

        MyString& insert(int loc, const MyString& str); // 문자열 삽입
        MyString& insert(int loc, const char* str); // 문자열 삽입
        MyString& insert(int loc, char c); // 문자 삽입

        MyString& erase(int loc, int num);

        int find(int find_from, MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        
        int compare(const MyString& str) const;

        vector<int> makeTable() const;
        void KMP(MyString& parent) const;
        bool operator==(MyString& str);
};

MyString::MyString(int capacity) {
    string_content = new char[capacity];
    string_length = 0;
    memory_capacity = capacity;
}

MyString::MyString(char c) {
    string_length = 1;
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
}

MyString::MyString(const char *str) {
    string_length = strlen(str);
    string_content = new char[string_length];
    for (int i = 0; i < string_length; i++) {
        string_content[i] = str[i];
    }
    memory_capacity = string_length;
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];
    for (int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::~MyString() {
    delete[] string_content;
}

void MyString::print() {
    for (int i = 0; i < string_length; i++) {
        cout << string_content[i];
    }
    cout << endl;
}

int MyString::length() const {
    return string_length;
}

int MyString::capacity() const {
    return memory_capacity;
}

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char *prev_string_content = string_content;
        string_content = new char[size];
        memory_capacity = size;
        for (int i = 0; i < string_length; i++) {
            string_content[i] = prev_string_content[i];
        }
        delete[] prev_string_content;
    }
}

char MyString::at(int i) const {
    if (i < 0 || i >= string_length) {
        return 0;
    } else {
        return string_content[i];
    }
}

MyString& MyString::assign(const MyString& str) {
    if(str.string_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    string_length = str.string_length;
    for (int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }

    return *this;
}

MyString& MyString::assign(const char* str) {
    if (strlen(str) > memory_capacity) {
        delete[] string_content;
        string_content = new char[strlen(str)];
        memory_capacity = strlen(str);
    }
    string_length = strlen(str);
    for (int i = 0; i < string_length; i++) {
        string_content[i] = str[i];
    }
    return *this;
}

MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > string_length) {
        return *this;
    }

    if (string_length + str.string_length > memory_capacity) {
        
        if (memory_capacity * 2 > string_length + str.string_length)
            memory_capacity *= 2;
        else 
            memory_capacity = string_length + str.string_length;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];
    
        int i;
        for (i = 0; i < loc; i++) {
            string_content[i] = prev_string_content[i];
        }
        for (int j = 0; j != str.string_length; j++) {
            string_content[i + j] = str.string_content[j];
        }
        for (; i < string_length; i++) {
            string_content[i + str.string_length] = prev_string_content[i];
        }
    
        delete[] prev_string_content;
    }
    else {
        for (int i = string_length - 1; i >= loc; i--) {
            string_content[i + str.string_length] = string_content[i]; 
        }
        for (int i = 0; i < str.string_length; i++) {
            string_content[i + loc] = str.string_content[i];
        }
        
    }
    string_length = string_length + str.string_length;
    return *this;
}

MyString& MyString::insert(int loc, const char* str) {
    MyString temp(str);
    return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
    MyString temp(c);
    return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num) {
    if (num < 0 || loc < 0 || loc > string_length || num > string_length) 
        return *this;
    else {
        for (int i = loc + num; i < string_length; i++) {
            string_content[i - num] = string_content[i];
        }
        string_length -= num;
        return *this;
    }
}

int MyString::find(int find_from, MyString& str) const {
    int i, j;
    if (str.string_length == 0) 
        return -1;
    
    for(i = find_from; i <= string_length - str.string_length; i++) {
        for (j = 0; j < str.string_length; j++) {
            if (string_content[i + j] != str.string_content[j]) 
                break;
        }
        if (j == str.string_length)
            return i;
    }
    return -1;
}

int MyString::find(int find_from, const char* str) const {
    MyString temp(str);
    return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
    MyString temp(c);
    return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
    for (int i = 0; i < std::min(string_length, str.string_length); i++) {
        if (string_content[i] > str.string_content[i])
            return BIGGER;
        else if(string_content[i] < str.string_content[i])
            return SMALLER;
    }
    if (string_length == str.string_length)
        return EQUAL;
    else if (string_length > str.string_length)
        return BIGGER;
    else
        return SMALLER;
}

vector<int> MyString::makeTable() const {
    int patternSize = length();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        while (j > 0 && string_content[i] != string_content[j]) {
            j = table[j - 1];
        }
        if(string_content[i] == string_content[j]) 
            table[i] = ++j;
    }
    return table;
}

void MyString::KMP(MyString& pattern) const {
    vector<int> table = pattern.makeTable();
    int parentSize = string_length;
    int patternSize = pattern.string_length;
    int j = 0;
    for(int i = 0; i < parentSize; i++) {
        while(j > 0 && string_content[i] != pattern.string_content[j]) {
            j = table[j - 1];
        }
        if(string_content[i] == pattern.string_content[j]) {
            if(j == patternSize - 1) {
                cout << i - patternSize + 1 << "번 째에서 찾았습니다." << endl;
                j = table[j];
            }
            else {
                j++;
            } 
        }
    }
}

bool MyString::operator==(MyString& str) {
    return !compare(str);
}