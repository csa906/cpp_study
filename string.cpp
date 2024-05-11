#include <iostream>

class string {
    private:
        char* str;
        int len;
    public:
        string(char c, int n);
        string(const char* s);
        string(const string& s);
        ~string();
        
        void add_string(const string& s);
        void copy_string(const string& s);
        void print_string();
        int strlen();
};

string::string(char c, int n) {
    str = new char[n + 1];
    for (int i = 0; i < n; i++) {
        str[i] = c;
    }
    str[n] = '\0';
    len = n;
}

string::string(const char* s) {
    len = 0;
    while (s[len] != '\0') {
        len++;
    }
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s[i];
    }
    str[len] = '\0';
}

string::string(const string& s) {
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s.str[i];
    }
    str[len] = '\0';
}

string::~string() {
    delete[] str;
}

void string::add_string(const string& s) {
    char* temp = new char[len + s.len + 1];
    for (int i = 0; i < len; i++) {
        temp[i] = str[i];
    }
    for (int i = 0; i < s.len; i++) {
        temp[len + i] = s.str[i];
    }
    temp[len + s.len] = '\0';
    delete[] str;
    str = temp;
    len += s.len;
}

void string::copy_string(const string& s) {
    delete[] str;
    len = s.len;
    str = new char[len + 1];
    for (int i = 0; i < len; i++) {
        str[i] = s.str[i];
    }
    str[len] = '\0';
}

void string::print_string() {
    std::cout << str << std::endl;
}

int string::strlen() {
    return len;
}

int main() {
    string a('a', 5);
    string b("hello"); 
    string c = b;

    a.print_string();

    a.add_string(b);
    a.print_string();

    a.copy_string(c);
    a.print_string();
    
    return 0;
}