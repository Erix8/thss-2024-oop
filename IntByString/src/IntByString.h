#pragma once

#include <string>

// A super-long integer kept as a string (this chapter is about string
// operations). Representation, following the textbook:
//   m_flag : 1 for a non-negative number, -1 for a negative number
//   m_data : digits '0'..'9', no leading zero; m_data == "" means 0
class IntByString
{
public:
    IntByString();                                     // the number 0
    IntByString(const std::string& data, int flag = 1);

    int getFlag() const;                               // sign: 1 or -1
    std::string getData() const;                       // the digit string

    void setValue(const std::string& data);            // parse like "+123" / "-123"
    void setValue(int flag, const std::string& data);  // set sign and digits

    void show(const char* hint) const;                 // print hint + the number

    // String add/sub are done by operator overloading.
    friend IntByString operator+(const IntByString& a, const IntByString& b);
    friend IntByString operator-(const IntByString& a, const IntByString& b);

private:
    int m_flag;
    std::string m_data;
};
