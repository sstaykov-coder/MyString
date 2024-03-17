#include <iostream>
#include <cstring>

class MyString
{
private:
    char *buffer;
    unsigned length;
    unsigned bufferSize;

public:
    // Constructor
    MyString() : buffer(nullptr), length(0), bufferSize(0) {}

    // Destructor
    ~MyString()
    {
        if (buffer != nullptr)
            delete[] buffer;
    }
    MyString(const MyString &other)
    {
        length = other.length;
        bufferSize = other.length + 1;
        buffer = new char[bufferSize];
        std::strcpy(buffer, other.buffer);
    }

    // Assignment operator
    MyString &operator=(const MyString &other)
    {
        if (this != &other)
        {
            length = other.length;
            bufferSize = other.length + 1;
            delete[] buffer;
            buffer = new char[bufferSize];
            std::strcpy(buffer, other.buffer);
        }
        return *this;
    }

    // Member functions (unchanged)

    unsigned size() const
    {
        return length;
    }

    unsigned capacity() const
    {
        return bufferSize - 1;
    }

    const char *c_str() const
    {
        return buffer;
    }

    char at(unsigned indx) const
    {
        if (indx >= length)
            throw std::out_of_range("Index out of range");
        return buffer[indx];
    }
    void push_back(char c)
    {
        if (length + 1 >= bufferSize)
        {
            unsigned newBufferSize = (bufferSize == 0) ? 1 : bufferSize * 2;
            char *newBuffer = new char[newBufferSize];
            if (buffer != nullptr)
            {
                std::strcpy(newBuffer, buffer);
                delete[] buffer;
            }
            buffer = newBuffer;
            bufferSize = newBufferSize;
        }
        buffer[length] = c;
        length++;
        buffer[length] = '\0';
    }

    void pop_back()
    {
        if (length > 0)
        {
            --length;
            buffer[length] = '\0';
        }
    }

    unsigned find(char c, unsigned startPos = 0) const
    {
        for (unsigned i = startPos; i < length; ++i)
        {
            if (buffer[i] == c)
                return i;
        }
        return length; // Not found
    }

    bool empty() const
    {
        return length == 0;
    }

    MyString substr(unsigned pos = 0, unsigned n = 0) const
    {
        if (pos >= length)
            return MyString(); // Empty string

        n = (n == 0 || pos + n > length) ? length - pos : n;
        MyString sub;
        sub.buffer = new char[n + 1];
        std::strncpy(sub.buffer, buffer + pos, n);
        sub.buffer[n] = '\0';
        sub.length = n;
        sub.bufferSize = n + 1;
        return sub;
    }

    void append(const MyString &str)
    {
        unsigned newLength = length + str.length;
        if (newLength + 1 > bufferSize)
        {
            unsigned newBufferSize = newLength * 2 + 1;
            char *newBuffer = new char[newBufferSize];
            std::strcpy(newBuffer, buffer);
            std::strcpy(newBuffer + length, str.buffer);
            delete[] buffer;
            buffer = newBuffer;
            bufferSize = newBufferSize;
        }
        else
        {
            std::strcpy(buffer + length, str.buffer);
        }
        length = newLength;
    }

    void append(const char *str)
    {
        unsigned strLength = std::strlen(str);
        unsigned newLength = length + strLength;
        if (newLength + 1 > bufferSize)
        {
            unsigned newBufferSize = newLength * 2 + 1;
            char *newBuffer = new char[newBufferSize];
            std::strcpy(newBuffer, buffer);
            std::strcpy(newBuffer + length, str);
            delete[] buffer;
            buffer = newBuffer;
            bufferSize = newBufferSize;
        }
        else
        {
            std::strcpy(buffer + length, str);
        }
        length = newLength;
    }
};

int main()
{
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

    std ::cout << str1.c_str() << std ::endl;
    str1.pop_back();
    str1.pop_back();
    std ::cout << str1.c_str() << std ::endl;
    std ::cout << str1.find('l', 0);
    return 0;
}
