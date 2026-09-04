#include <iostream>
#include <string>

#include "IntByString.h"
#include "IntByStringTest.h"

static int gFailures = 0;

// Turn a value into plain text: zero -> "0", negative -> "-123".
static std::string toText(const IntByString& v)
{
    if (v.getData().empty())
    {
        return "0";
    }
    return (v.getFlag() == -1 ? "-" : "") + v.getData();
}

static void check(bool ok, const std::string& what)
{
    if (ok)
    {
        std::cout << "  PASS  " << what << '\n';
    }
    else
    {
        std::cout << "  FAIL  " << what << '\n';
        ++gFailures;
    }
}

static bool sumIs(const std::string& a, const std::string& b, const std::string& expect)
{
    return toText(IntByString(a) + IntByString(b)) == expect;
}

static bool diffIs(const std::string& a, const std::string& b, const std::string& expect)
{
    return toText(IntByString(a) - IntByString(b)) == expect;
}

static void testAddition()
{
    std::cout << "\noperator+  (5 cases, several super-long)\n";

    std::string ones40(40, '1');
    std::string twos40(40, '2');
    std::string threes40(40, '3');
    std::string nines40(40, '9');
    std::string zeros39(39, '0');
    std::string zeros40(40, '0');

    check(sumIs("0", "0", "0"),
          "1) all zero: 0 + 0 = 0");
    check(sumIs(ones40, twos40, threes40),
          "2) 40-digit + 40-digit (no carry): 111..1 + 222..2 = 333..3");
    check(sumIs(nines40, "1", "1" + zeros40),
          "3) super-long carry: 999..9 (40 digits) + 1 = 1 followed by 40 zeros");
    check(sumIs("1" + zeros39, "-1", std::string(39, '9')),
          "4) big positive + (-1): 10^39 - 1 = 39 nines");
    check(sumIs("-" + ones40, "-" + twos40, "-" + threes40),
          "5) two big negatives: -(111..1) + -(222..2) = -(333..3)");
}

static void testSubtraction()
{
    std::cout << "\noperator-  (5 cases, several super-long)\n";

    std::string ones40(40, '1');
    std::string twos40(40, '2');
    std::string nines40(40, '9');
    std::string zeros39(39, '0');
    std::string zeros40(40, '0');

    check(diffIs("0", "0", "0"),
          "1) all zero: 0 - 0 = 0");
    check(diffIs(nines40, nines40, "0"),
          "2) equal big numbers: 999..9 - 999..9 = 0");
    check(diffIs(ones40, twos40, "-" + ones40),
          "3) bigger - smaller result negative: 111..1 - 222..2 = -(111..1)");
    check(diffIs("1" + zeros39, "1", std::string(39, '9')),
          "4) super-long borrow: 10^39 - 1 = 39 nines");
    check(diffIs(nines40, "-1", "1" + zeros40),
          "5) big positive - negative: 999..9 - (-1) = 1 followed by 40 zeros");
}

int runAllIntByStringTests()
{
    std::cout << "IntByString operator tests\n";
    testAddition();
    testSubtraction();

    std::cout << "\nFailed checks: " << gFailures << '\n';
    return gFailures;
}
