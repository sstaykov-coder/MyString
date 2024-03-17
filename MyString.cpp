#include <iostream>
#include <cstring>

class MyString {
private:
    char* buffer;
    unsigned length;
    unsigned bufferSize;

public:
    // Constructor
    MyString() : buffer(nullptr), length(0), bufferSize(0) {}

    // Destructor
    ~MyString() {
        if (buffer != nullptr)
            delete[] buffer;
    }

};

int main() {
    MyString str1;
    str1.push_back('H');

    str1.push_back('e');
    str1.push_back('l');
    str1.push_back('l');
    str1.push_back('o');
    std::cout << "str1: " << str1.c_str() << std::endl;
    MyString str2;
    str2.push_back(' ');
    str2.push_back('W');
    str2.push_back('o');
    str2.push_back('r');
    str2.push_back('l');
    str2.push_back('d');
    str2.push_back('!');
    std::cout << "str2: " << str2.c_str() << std::endl;

    str1.append(str2);
    std::cout << "str1 after append: " << str1.c_str() << std::endl;

    MyString substr = str1.substr(6, 5);
    std::cout << "Substring of str1: " << substr.c_str() << std::endl;

    std :: cout << str1.c_str() << std :: endl;
    str1.pop_back();
    str1.pop_back();
    std :: cout << str1.c_str() << std :: endl;
    std :: cout << str1.find('l',0);
    return 0;
}
