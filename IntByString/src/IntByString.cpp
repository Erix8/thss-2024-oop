#include <algorithm>
#include <iostream>

#include "IntByString.h"

// ---------- small helpers (plain string arithmetic, no fancy tricks) -------

// Remove leading zeros; an empty string means zero.
static std::string trimZeros(const std::string& digits)
{
    std::size_t i = 0;
    while (i < digits.size() && digits[i] == '0')
    {
        ++i;
    }
    return digits.substr(i);
}

// Add two magnitudes, e.g. "111" + "222" -> "333". Empty string means 0.
static std::string addDigits(const std::string& a, const std::string& b)
{
    std::string result;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        int sum = carry;
        if (i >= 0) sum += a[i] - '0';
        if (j >= 0) sum += b[j] - '0';
        result += static_cast<char>('0' + sum % 10);
        carry = sum / 10;
        --i;
        --j;
    }
    std::reverse(result.begin(), result.end());
    return trimZeros(result);
}

// Compare two magnitudes ("" is smaller than any non-empty). Returns -1/0/1.
static int compareDigits(const std::string& a, const std::string& b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size() ? -1 : 1;
    }
    if (a == b)
    {
        return 0;
    }
    return a < b ? -1 : 1;
}

// Subtract magnitudes; needs |a| >= |b|.
static std::string minusDigits(const std::string& a, const std::string& b)
{
    std::string result;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int digit = (a[i] - '0') - borrow;
        if (j >= 0)
        {
            digit -= b[j] - '0';
            --j;
        }
        if (digit < 0)
        {
            digit += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        result += static_cast<char>('0' + digit);
        --i;
    }
    std::reverse(result.begin(), result.end());
    return trimZeros(result);
}

// --------------------------------------------------------------------------

IntByString::IntByString() : m_flag(1), m_data("") {}

IntByString::IntByString(const std::string& data, int flag)
{
    setValue(flag, data);
}

int IntByString::getFlag() const
{
    return m_flag;
}

std::string IntByString::getData() const
{
    return m_data;
}

void IntByString::setValue(const std::string& data)
{
    m_flag = 1;
    m_data.clear();

    std::size_t pos = 0;
    if (pos < data.size() && (data[pos] == '+' || data[pos] == '-'))
    {
        if (data[pos] == '-')
        {
            m_flag = -1;
        }
        ++pos;
    }

    while (pos < data.size() && data[pos] >= '0' && data[pos] <= '9')
    {
        m_data += data[pos];
        ++pos;
    }
    m_data = trimZeros(m_data);   // "0" becomes "" (means zero)
}

void IntByString::setValue(int flag, const std::string& data)
{
    setValue(data);            // parse the digits first
    if (flag == -1 && !m_data.empty())
    {
        m_flag = -1;           // force negative if it is not zero
    }
}

void IntByString::show(const char* hint) const
{
    std::cout << hint;
    if (m_data.empty())
    {
        std::cout << '0';
        return;
    }
    if (m_flag == -1)
    {
        std::cout << '-';
    }
    std::cout << m_data;
}

IntByString operator+(const IntByString& a, const IntByString& b)
{
    IntByString result;
    if (a.m_flag == b.m_flag)   // same sign: add the magnitudes
    {
        result.m_data = addDigits(a.m_data, b.m_data);
        result.m_flag = a.m_flag;
    }
    else                        // different signs: subtract the smaller
    {
        if (compareDigits(a.m_data, b.m_data) >= 0)
        {
            result.m_data = minusDigits(a.m_data, b.m_data);
            result.m_flag = a.m_flag;
        }
        else
        {
            result.m_data = minusDigits(b.m_data, a.m_data);
            result.m_flag = b.m_flag;
        }
    }
    if (result.m_data.empty())  // zero is never negative
    {
        result.m_flag = 1;
    }
    return result;
}

IntByString operator-(const IntByString& a, const IntByString& b)
{
    IntByString negB = b;
    negB.m_flag = -b.m_flag;    // a - b = a + (-b)
    return a + negB;
}
