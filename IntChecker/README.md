# 🔍 IntChecker · Check a String Is an Integer (Exception Handling)

Homework 12 — this chapter covers **namespaces**, **exception handling**, **class objects** and the **singleton** pattern. This little program uses a class object and **exceptions** (`throw` / `try` / `catch`) to decide whether a line typed in the console is a valid integer, and to report *why* it is not.

---

## 📋 The assignment (what you were asked to do)

- Read **one line of text** from the console.
- Analyse it: does it look like an **integer**?
  - If yes → convert it to an integer and print that integer.
  - If no → **throw an exception**, analyse the reason, and **throw a different value for each reason** (at least 5 reasons/values).

✅ This folder does that. It can tell apart **7 different reasons** (see below).

---

## 🧠 Design & how exceptions are used

`IntChecker::parse(text)` returns the `long long` value when the text is a valid integer. When it is not, it `throw`s an `int` code — each code means one specific reason:

| Code | Reason | Example |
| :--- | :--- | :--- |
| `1` | the input is empty | `""` |
| `2` | contains spaces / whitespace | `"1 2"` |
| `3` | contains another non-digit character | `"12a3"` |
| `4` | too many / misplaced `+` or `-` signs | `"--5"`, `"1-2"` |
| `5` | a sign but no digits | `"+"`, `"-"` |
| `6` | a leading zero in a multi-digit number | `"007"` |
| `7` | the number is too big for a `long` | a 40-digit number |

`main()` does the parse inside a `try` block and uses `catch (int code)` to print the matching reason, so the thrown value is what tells the program (and the user) what went wrong:

```cpp
try
{
    long long value = checker.parse(line);
    std::cout << "OK: it is the integer " << value << ".\n";
}
catch (int code)
{
    std::cout << "Invalid integer.\n";
    printReason(code);   // which of the 7 reasons it was
}
```

Valid forms include `"123"`, `"-45"`, `"+0"`, `"0"` … Each valid line is really **converted** to an integer and printed.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`IntChecker.sln`](IntChecker.sln) | 🚪 Visual Studio **solution** — double-click to open the project |
| [`src/IntChecker.vcxproj`](src/IntChecker.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/IntChecker.h`](src/IntChecker.h) | 📜 class declaration + the meaning of each thrown value |
| [`src/IntChecker.cpp`](src/IntChecker.cpp) | ⚙️ the validation (throws) and conversion |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — reads lines, catches and prints reasons |

---

## 🛠️ Build & run

1. Open [`IntChecker.sln`](IntChecker.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀
4. Type lines such as `123`, `-45`, `007`, `12a3`, `1 2`, `--5`, `+` …; an **empty line** ends the program.

---

## ✏️ Try it yourself

- Add an eighth rule of your own (e.g. reject `+` when you want a “no sign allowed” style) and give it a new code.
- Instead of `throw 6`, try `throw "leading zero"` — see that `catch` must change to match the new thrown type.

---

## 🧭 Suggested reading order

1. Read [`src/IntChecker.h`](src/IntChecker.h) — the reason-code table.
2. Read [`src/IntChecker.cpp`](src/IntChecker.cpp) — the scan that decides each reason and throws.
3. Read [`src/Main.cpp`](src/Main.cpp) — the `try`/`catch` and the reason messages.
