# 🔢 NumberSort · Sort Integers with `vector` + `set`

Homework 09 — this chapter covers **function templates**, **class templates**, **`std::vector`**, **`std::set`** and **`std::sort`**. This little console program reads some integers and then shows the two sorting results the assignment asks for: one that **keeps duplicates** (via `algorithm::sort` on a `vector`) and one that **removes duplicates** (via a `std::set`).

---

## 📋 The assignment

- Read a list of integers from the console (you may define the input format).
- Sort those integers with the `sort` function from the **algorithm** library, **without removing duplicates**, and print the result.
- Sort those integers with a **`std::set`**, which removes duplicates, and print that result too.

✅ This folder does exactly that. The defined input format is: first an integer `n`, then `n` integers.

---

## 🧠 Key ideas

The chapter’s tools are all used here:

| Tool | What it does | In the code |
| :--- | :--- | :--- |
| **`std::vector`** | A growable sequence that keeps everything, including duplicates | `original`, `withDuplicates` |
| **function templates** | One function that works for many types | `ReadNumbers<T>`, `PrintNumbers<T>` |
| **`algorithm::sort`** | Sorts a range in place; duplicates stay | `std::sort(withDuplicates.begin(), withDuplicates.end())` |
| **`std::set`** | An ordered container that automatically stores each value only once | `withoutDuplicates` |
| **`insert(first, last)`** | Pushes a whole range into the set | `withoutDuplicates.insert(original.begin(), original.end())` |

Two `PrintNumbers` overloads show how the same template can print a `vector` or a `set`:

```cpp
template <typename T>
void PrintNumbers(const std::vector<T>& numbers);   // prints [0]..[n-1]

template <typename T>
void PrintNumbers(const std::set<T>& numbers);      // prints in sorted, unique order
```

Why the two results differ: `std::sort` only reorders a `vector` (so equal values appear twice), while `std::set` is a sorted container that discards duplicates on insert.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`NumberSort.sln`](NumberSort.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/NumberSort.vcxproj`](src/NumberSort.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/NumberSort.h`](src/NumberSort.h) | 📜 Template helpers: `ReadNumbers` and `PrintNumbers` |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — reads input, sorts, prints both results |

> 💡 `NumberSort.h` is header-only (templates are defined where they’re declared); `Main.cpp` just drives the reading and the two sorts.

---

## 🛠️ Build & run

1. Open [`NumberSort.sln`](NumberSort.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

Input format: first `n`, then `n` integers. Example:

```text
10
5 3 8 3 9 1 5 7 2 8
```

Output (note the duplicates in the second line, none in the third):

```text
Sorted with sort() (duplicates kept):
[0] 1  [1] 2  [2] 3  [3] 3  [4] 5  [5] 5  [6] 7  [7] 8  [8] 8  [9] 9
Sorted with set (duplicates removed):
[0] 1  [1] 2  [2] 3  [3] 5  [4] 7  [5] 8  [6] 9
```

---

## ✏️ Try it yourself

- Change `ReadNumbers`’s input format, e.g. read until a `0` terminator, and update the prompt.
- Sort into **descending** order by adding `std::greater<int>()` to `std::sort`, and compare with the `set`.
- Template-ify further: read `double` or `std::string` values and confirm the same helpers still work.

---

## 🧭 Suggested reading order

1. Read [`src/NumberSort.h`](src/NumberSort.h) — see the two function templates (`ReadNumbers`/`PrintNumbers`).
2. Read [`src/Main.cpp`](src/Main.cpp) — watch `vector`+`sort` keep duplicates and `set` remove them.
