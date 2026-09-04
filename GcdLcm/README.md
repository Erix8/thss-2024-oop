# 🔢 GcdLcm · GCD & LCM Finder

You give the program two positive integers and it answers with their:

- 💪 **GCD** — Greatest Common Divisor
- ✨ **LCM** — Least Common Multiple

---

## 📋 The assignment (what you were asked to do)

- **Problem.** The program reads two positive integers `a` and `b`. It computes and prints:
  1. the **Greatest Common Divisor** of `a` and `b`;
  2. the **Least Common Multiple** of `a` and `b`.
- **Code.** Implement the above with **object-oriented programming**, and **test it**.

> ✅ This folder is an OOP implementation of the required part. About the “test it” requirement — see the *Testing* section below.

---

## 🎯 This implementation

- Class `GcdLcm` stores the two inputs and the computed results.
- The constructor takes two positive integers; GCD (`gcd()`) uses a **recursive** Euclidean algorithm 🔁, and LCM (`lcm()`) = `first ÷ gcd × second` 🧠.
- Non-positive input is politely rejected with *“Invalid input.”* 🚫

---

## 🧪 Testing

Right now `Main.cpp` lets you verify the program interactively: run it, type `12 18`, and you get `GCD: 6` / `LCM: 36`; feed a `0` or a negative number and you get `Invalid input.` This is a *manual smoke test* — good enough to eyeball, but not an automated check of the class itself.

> 📌 **Decision:** the assignment says “and test it”. After reviewing the options, this answer keeps the **interactive smoke test** above as its verification — no external framework, fitting a simple console homework. A record of the (rejected-for-now) automated self-check idea is kept at the bottom of this file for future reference.

---

## 🧮 Quick math reminder

For two numbers such as `12` and `18`:

- **GCD** = the largest number that divides both → `6`.
- **LCM** = the smallest number that is a multiple of both → `36`.

The classic trick: `LCM = (a × b) ÷ GCD`. The **Euclidean algorithm** finds the GCD with repeated remainders — `gcd(a, b) = gcd(b, a % b)` — until the remainder becomes `0`. In code this is done recursively by `computeGcd()`.

---

## 🧠 Key ideas (OOP in this example)

The maths could be written as a few free functions in `main()`. Instead the data (the two numbers) and the maths (gcd/lcm) are wrapped into one class, so `main()` just builds an object and reads its answers.

| OOP term | What it means here | In the code |
| :--- | :--- | :--- |
| **Class** | A blueprint for "something that can compute GCD & LCM" | `GcdLcm` |
| **Object (instance)** | A real calculator you create with two numbers | `calculator` in `main()` |
| **Constructor** | Special function that runs when an object is created — here it stores the inputs *and* pre-computes the results | `GcdLcm(int, int)` |
| **Member attribute** | Data the object keeps: the two inputs and the two results | `firstNumber_`, `secondNumber_`, `gcd_`, `lcm_` |
| **Member function (public API)** | What the outside world is allowed to ask | `gcd()`, `lcm()` |
| **Private helper** | Internal detail callers don't need to see | `computeGcd()` |

Why keep `computeGcd()` **private**? Because whoever uses the object only cares about the answers (`gcd()` / `lcm()`), not *how* they are computed. Hiding that detail (encapsulation) lets the internals change later without breaking the users of the class.

```cpp
GcdLcm calculator(12, 18);        // store 12 & 18, compute everything
std::cout << calculator.gcd();    // 6
std::cout << calculator.lcm();    // 36
```

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`GcdLcm.sln`](GcdLcm.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/GcdLcm.vcxproj`](src/GcdLcm.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/GcdLcm.h`](src/GcdLcm.h) | 📜 `GcdLcm` **class declaration** — what the class looks like |
| [`src/GcdLcm.cpp`](src/GcdLcm.cpp) | ⚙️ Class **implementation** — the maths (Euclid, LCM) |
| [`src/Main.cpp`](src/Main.cpp) | 📍 **Entry point** — reads input, builds the object, prints results |

> 💡 *Rule of thumb used here:* the **header** (`.h`) *declares* the class, the **`.cpp`** *defines* how its methods work, and **`main()`** is the outside user that drives everything.

---

## 🛠️ Build & run

1. Open [`GcdLcm.sln`](GcdLcm.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Press **F5** (or `Ctrl+F5` to keep the window open). 🚀
4. Type two positive integers, e.g. `12 18`, and press `Enter`.
5. Boom — `GCD: 6` and `LCM: 36` appear on screen! 🎉

---

## ✏️ Try it yourself

- Sneak in a `0` or a negative number → you’ll get *“Invalid input.”* 😉
- Read through `computeGcd()` in [`src/GcdLcm.cpp`](src/GcdLcm.cpp) slowly and watch the recursion unwind step by step. 🔍

---

## 🧭 Suggested reading order for beginners

1. Read [`src/Main.cpp`](src/Main.cpp) — the shortest file, it shows the "outside view" (build object → ask `gcd()`/`lcm()`).
2. Skim [`src/GcdLcm.h`](src/GcdLcm.h) — see the class shape: a constructor, two public getters, one private helper, and the stored data.
3. Read [`src/GcdLcm.cpp`](src/GcdLcm.cpp) — see the constructor pre-compute results and the recursive `computeGcd()`.

---

## 🧾 Testing decision & record

**Decision:** no extra automated self-test is added to the code. The interactive smoke test above (a few runs with known inputs, including an invalid one) is the verification method for this homework answer — simple, dependency-free, and enough for a console course project.

For anyone who later wants automation, here is the short idea we evaluated and set aside (kept for reference):

- Add an internal `runSelfTest()` that checks a few known pairs against `gcd()` / `lcm()` and prints `PASS` / `FAIL`, then exits non-zero on failure.
- Use cases like `12 18 → gcd 6 / lcm 36`, `7 3 → 1 / 21`, `5 5 → 5 / 5`, and coprime `13 17 → 1 / 221`.
- Run it automatically before the interactive prompt, or expose it behind a switch (e.g. `GcdLcm --selftest`) so normal usage stays unchanged.
