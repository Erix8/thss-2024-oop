# Solutions to OOP Homeworks 🚀

Hey, welcome to my little **Object-Oriented Programming** playground for the *THSS 2024 OOP* course! 🎓💻

Every homework here is a small **Visual Studio 2022 console app** written in **C++**, tucked into its own cozy folder together with a solution (`.sln`), a project (`.vcxproj`) and a per-homework README. No external libraries, no CMake — just the classic C++ standard library and plenty of console fun! 😄

---

## 🗺️ Homework overview

| HW# | 📝 Task | 🧠 Concepts practiced |
| :---: | :--- | :--- |
| 01 | 🖨️ [Console Pattern Printer](./FuPrinter/README.md) | First C++ program — console output; meeting a first small class |
| 02 | 🔢 [Find GCD & LCM of Two Numbers](./GcdLcm/README.md) | What a class is — data members, member functions, constructors; recursion |
| 03 | 🔷 [Shape Perimeter & Area Calculator](./ShapeCalc/README.md) | Inheritance — base & derived classes, `protected` members, constructors |
| 04 | 📅 [Calendar / Date Class](./Calendar/README.md) | Encapsulation — `private` data, validated setters, getters |
| 05 | 🧮 [Complex Numbers — Operator Overloading](./Complex/README.md) | Operator overloading (`+ - * / ++ --`), prefix vs postfix |

---

## 🚀 Follow along — FuPrinter, end to end

The best way to get comfortable is to run one example from top to bottom, and **FuPrinter** is the gentlest one (one class, one attribute, one method). Try this:

1. **Read [`FuPrinter/README.md`](FuPrinter/README.md) first.** It restates the original *assignment*, then unpacks the OOP *key ideas* (what a class / object / attribute / method means *in this code*), and gives a *file map* — every filename in the table links straight to the source.
2. **Open [`FuPrinter.sln`](FuPrinter/FuPrinter.sln)** — double-click it and Visual Studio loads the project.
3. **Build it** with **Build → Build Solution** (`Ctrl+Shift+B`). A console app needs no extra setup, so it should just work.
4. **Run it with `Ctrl+F5`** (run *without* debugging, so the console window stays open). You’ll see the big **福** drawn with `&`.
5. **Go back to the README’s *Try it yourself*** and change the drawing character or the spacing, then re-run. Watching the picture change is the fastest way to *feel* how `drawFu()` works — and breaking it on purpose teaches more than reading it.

When you move to a later homework (like **GcdLcm**), the flow is identical: its README has the same sections, its own build steps, and clickable file links. And whenever a word like *class* or *method* shows up, it’s explained in plain words right there in that README — no separate glossary to hunt through.

---

## 🛠️ Environment & project setup

**Prerequisites** 🧰
- 🪟 **Windows 10 or 11**
- 🛠️ **Visual Studio 2022** with the *Desktop development with C++* workload

Every project in this repo is configured the same way, so once your machine is set up you can build any of them:

> 💡 All homeworks are **Win32 console applications** (subsystem `Console`, toolset **v143**, `WindowsTargetPlatformVersion 10.0`, Unicode). Each supports the same four configurations:

| Configuration | Platform | Vibe ✨ |
| :--- | :--- | :--- |
| Debug | Win32 (x86) & x64 | Full checks on, slow & friendly 👀 |
| Release | Win32 (x86) & x64 | Optimized & ready to fly 🚀 |

Run with **`Ctrl+F5`** to keep the console window open after the program ends, or **`F5`** to run under the debugger.

---

Happy coding! ☕💻✨
