# 🧮 Complex · Complex-Number Operator Overloading

Homework 05 — this week’s topic is **polymorphism**, and in this lesson we learn the concrete C++ method of **operator overloading**: we make `+`, `-`, `*`, `/`, `++` and `--` work on our own `Complex` numbers, just as they do on `int` or `double`. We also follow the assignment’s rule that **every overloaded operator is tested with at least five cases** covering five different situations (zero, pure real, pure imaginary, mixed, and values with negative parts).

---

## 📋 The assignment

- Write a **complex-number class** and overload these operators on it:
  - binary arithmetic: **`+`**, **`-`**, **`*`**, **`/`**
  - increment / decrement: **prefix `++`**, **postfix `++`**, **prefix `--`**, **postfix `--`**
- Implement them with object-oriented techniques.
- For **each** overloaded operator, design **at least 5 test cases** that represent **5 different situations** (for example, a pure-imaginary number, a pure-real number, zero, and so on).

✅ This folder implements all of the above; running the program runs the full test suite and reports any failures.

---

## 🧠 Key ideas

A complex number is `a + bi`. The data is `private` (we already learned encapsulation), so the binary operators are free functions that read the parts through the public getters:

| Operator | Rule used | Notes |
| :--- | :--- | :--- |
| `+` | `(a+bi)+(c+di) = (a+c) + (b+d)i` | add the parts separately |
| `-` | `(a+bi)-(c+di) = (a-c) + (b-d)i` | subtract the parts separately |
| `*` | `(a+bi)(c+di) = (ac-bd) + (ad+bc)i` | use `i² = -1` |
| `/` | `(a+bi)/(c+di) = ((ac+bd)+(bc-ad)i) / (c²+d²)` | divide by zero is rejected |
| `++` | increases the **real** part by 1 | a chosen meaning for “increment a complex number” |
| `--` | decreases the **real** part by 1 | same idea as `++` |

**Prefix vs postfix** are told apart by a dummy `int` parameter that is never used:

```cpp
Complex& Complex::operator++()      // prefix  ++c : change first, then give c
Complex  Complex::operator++(int)   // postfix c++ : give the OLD value, then change
```

That is why:
- **prefix** `++c` returns a **reference** to the (already changed) object;
- **postfix** `c++` returns a **copy of the old value**, and changes the object afterwards.

To test it, each operator gets **5 checks** on the five situations — for instance, adding two pure-imaginary numbers `(0+4i)+(0+6i) = (0+10i)`, or dividing `(6+0i)/(0+3i) = (0-2i)`. The tests compare results with a tiny tolerance (floating point) and print `PASS` / `FAIL`.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`Complex.sln`](Complex.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/Complex.vcxproj`](src/Complex.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/Complex.h`](src/Complex.h) | 📜 `Complex` class declaration + the operator declarations |
| [`src/Complex.cpp`](src/Complex.cpp) | ⚙️ Implementation of the operators and the class |
| [`src/ComplexTest.h`](src/ComplexTest.h) | 📜 Declares the test runner `runAllComplexTests()` |
| [`src/ComplexTest.cpp`](src/ComplexTest.cpp) | 🧪 The 5-cases-per-operator test suite (prints `PASS`/`FAIL`) |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — runs the whole test suite |

> 💡 `main()` only calls the tests; the maths is split between `Complex.cpp` (implementation) and `ComplexTest.cpp` (verification).

---

## 🛠️ Build & run

1. Open [`Complex.sln`](Complex.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

The program prints one `PASS`/`FAIL` line per case. A healthy run ends with:

```text
Failed checks: 0
```

---

## ✏️ Try it yourself

- Change one *expected* value in `ComplexTest.cpp` to a wrong number and re-run — you’ll see that case turn `FAIL`. That is the point of the tests.
- Add a 6th category (for example dividing by zero) and watch the guard in `operator/` report it.
- Replace the “real part ± 1” choice of `++`/`--` (in `Complex.cpp`) with your own rule (e.g. add `1 + 0i`) and update the tests to match.

---

## 🧭 Suggested reading order

1. Read [`src/Complex.h`](src/Complex.h) — see which operators are declared and the `private` data.
2. Read [`src/Complex.cpp`](src/Complex.cpp) — see the formulas, and how prefix vs postfix differ.
3. Skim [`src/ComplexTest.cpp`](src/ComplexTest.cpp) — notice each operator gets its own 5-case group, including pure-imaginary and zero situations.
