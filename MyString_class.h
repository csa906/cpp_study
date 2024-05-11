#include <iostream>
#include <string.h>
using namespace std;

class MyString {
    private:
        char *string_content;
        int string_length;
        int memory_capacity;
    
    public:
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
};

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