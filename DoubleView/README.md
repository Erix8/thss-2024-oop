# 🧮 DoubleView · See a `double` as Its Binary Bits

Homework 14 — this chapter covers **programming conventions**, **inline functions** and **unions**. This program uses a **union** to inspect the 64 bits of a `double` in memory (IEEE 754: 1 sign + 11 exponent + 52 fraction), and it also prints the memory bits of **NaN** (“not a number”).

---

## 📋 The assignment

- Accept a **double** from the console and output its **binary representation in memory**.
- Output the binary representation of **NaN** (not-a-number).
- *Optional (bonus):* also output the binary representations of **positive infinity** and **negative infinity** — this folder implements it too.
- Implement it with **object-oriented techniques and a union**, and **test it**.

✅ This folder does all of the above.

---

## 🧠 Key ideas

A `double` is stored in 64 bits. A **union** lets two views share the same memory, so we can read the same 8 bytes either as a `double` or as an unsigned integer of bits:

```cpp
union DoubleBits
{
    double value;            // look at the bytes as a double ...
    unsigned long long bits; // ... or as raw bits
};
```

- `DoubleView` wraps the union (the object-oriented layer).
- Its small getters `getValue()` / `getBits()` are declared **inline** (this chapter’s topic).
- `show()` prints the value, its hex form, and the 64-bit breakdown `sign | exponent(11) | fraction(52)`.

For example, `1.5` is stored as `0x3ff8000000000000`:

```text
sign = 0
exp  = 01111111111   (0x3FF, bias 1023  =>  2^0)
frac = 1000...0      (.5 = 1/2)
```

NaN is recognised in the bits by its shape: **exponent all ones (0x7FF) and a non-zero fraction**. In the same way, **+inf** and **−inf** are exponent all ones with a zero fraction — they differ only in the sign bit (`0` for `+inf`, `1` for `−inf`). The program prints both infinities as the optional bonus.

> ⚠️ Reading the *inactive* member of a union like this is the classic trick for this task. It is technically non-portable but is exactly what the assignment asks to demonstrate.

---

## 🧪 Testing

`runAllDoubleViewTests()` checks known IEEE-754 bit patterns and the special values:

- `0.0` → `0x0000000000000000`
- `1.0` → `0x3FF0000000000000`
- `-2.0` → `0xC000000000000000`
- `0.5` → `0x3FE0000000000000`
- **NaN** → exponent all ones, fraction non-zero
- **+inf** → exponent all ones, fraction zero
- **−inf** → sign `1`, exponent all ones, fraction zero

A healthy run prints `Failed checks: 0`.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`DoubleView.sln`](DoubleView.sln) | 🚪 Visual Studio **solution** — double-click to open the project |
| [`src/DoubleView.vcxproj`](src/DoubleView.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/DoubleView.h`](src/DoubleView.h) | 📜 `union DoubleBits` + inline getters of `DoubleView` |
| [`src/DoubleView.cpp`](src/DoubleView.cpp) | ⚙️ constructor and `show()` (prints bits/hex) |
| [`src/DoubleViewTest.h`](src/DoubleViewTest.h) · [`DoubleViewTest.cpp`](src/DoubleViewTest.cpp) | 🧪 functional tests of known bit patterns & NaN/inf |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — reads a double, shows NaN, runs tests |

---

## 🛠️ Build & run

1. Open [`DoubleView.sln`](DoubleView.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

Type a double (e.g. `1.5`); the program prints its bits, then the bits of NaN, then runs the tests.

---

## ✏️ Try it yourself

- Enter `0.1` — see that it is **not** stored exactly (its fraction repeats).
- Enter a negative number and watch the sign bit become `1`.
- Replace `quiet_NaN()` in `main()` with `numeric_limits<double>::signaling_NaN()` and compare the fraction bits.

---

## 🧭 Suggested reading order

1. Read [`src/DoubleView.h`](src/DoubleView.h) — the union and the inline getters.
2. Read [`src/DoubleView.cpp`](src/DoubleView.cpp) — how the bits are printed.
3. Read [`src/DoubleViewTest.cpp`](src/DoubleViewTest.cpp) — the known-pattern and NaN/inf checks.
