# 🔟 IntByString · A String-Based Super-Long Integer

Homework 10 — this chapter is about **string operations** (character-array strings, the `string` class, and the “super-long integer” case). So the number is kept in a `std::string` and all the work is ordinary string handling — no tricks.

---

## 📋 The assignment (what you were asked to do)

- Write a super-long integer class **based on the string class**.
- Implement **addition** and **subtraction** for super-long integers.
- Use object-oriented techniques.
- For **each overloaded operator**, design **at least 5 test cases**, each a different situation (for example, numbers that are all zero).

✅ This folder does that, following the textbook’s `IntByString` idea.

---

## 🧠 Design — a number as a string (textbook style)

Two plain members hold the number:

```cpp
int     m_flag;   // 1: non-negative or 0;  -1: negative
string  m_data;   // only digits '0'..'9', no leading zero; "" means 0
```

The class provides ordinary member functions to set, read and show it:

| Member | What it does |
| :--- | :--- |
| `IntByString(const string& data, int flag = 1)` | constructor |
| `getFlag()` / `getData()` | read the sign / digit string |
| `setValue(const string& data)` | parse `"+123"`, `"-123"`, `"0012"` … into sign + digits |
| `setValue(int flag, const string& data)` | force a sign after parsing |
| `show(const char* hint)` | print `hint` followed by the number |

`operator+` and `operator-` are overloaded. Inside, addition/subtraction are done on the two digit strings (add with carry, subtract with borrow), and the sign follows the usual schoolbook rule:

```cpp
IntByString a("12345678901234567890");
IntByString b("-9876543210");
IntByString c = a + b;   // string-based, no overflow however many digits
```

---

## 🧪 Testing — at least five cases per operator

`runAllIntByStringTests()` runs **5 cases for each operator**, several with **super-long 40-digit numbers** (built from repeated characters, no need to type them out):

- `operator+`: `0+0`; `111..1 + 222..2 = 333..3`; `999..9 + 1 = 1` + 40 zeros (carry past `long long`); `10^39 + (-1) = 39 nines`; two big negatives.
- `operator-`: `0-0`; equal 40-digit numbers → `0`; `111..1 - 222..2 = -(111..1)`; `10^39 - 1 = 39 nines` (super-long borrow); `999..9 - (-1)`.

A healthy run ends with `Failed checks: 0`.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`IntByString.sln`](IntByString.sln) | 🚪 Visual Studio **solution** — double-click to open the project |
| [`src/IntByString.vcxproj`](src/IntByString.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/IntByString.h`](src/IntByString.h) | 📜 class declaration (`m_flag`, `m_data`, `operator+/-`) |
| [`src/IntByString.cpp`](src/IntByString.cpp) | ⚙️ parsing, digit add/sub, `show`, `operator+/-` |
| [`src/IntByStringTest.h`](src/IntByStringTest.h) · [`IntByStringTest.cpp`](src/IntByStringTest.cpp) | 🧪 5 cases per operator |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — runs the test suite |

---

## 🛠️ Build & run

1. Open [`IntByString.sln`](IntByString.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

---

## ✏️ Try it yourself

- `setValue` a string like `"-00123"` and call `show` to see how the sign and leading zeros are handled.
- Put a 100-digit number in the constructor and add/subtract it.
- Make one expected value in `IntByStringTest.cpp` wrong and re-run — that case turns `FAIL`.

---

## 🧭 Suggested reading order

1. Read [`src/IntByString.h`](src/IntByString.h) — just two members plus the public methods.
2. Read [`src/IntByString.cpp`](src/IntByString.cpp) — parsing in `setValue`, the small digit helpers, and `operator+/-`.
3. Skim [`src/IntByStringTest.cpp`](src/IntByStringTest.cpp) — 5 cases per operator, including super-long ones.
