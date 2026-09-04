# Solutions to OOP Homeworks 🚀

Hey, welcome to my little **Object-Oriented Programming** playground for the *THSS 2024 OOP* course! 🎓💻

Every homework here is a small **Visual Studio 2022 console app** written in **C++**, tucked into its own cozy folder together with a solution (`.sln`), a project (`.vcxproj`) and a per-homework README. No external libraries, no CMake — just the classic C++ standard library and plenty of console fun! 😄

---

## 🧭 About this repo & how to read it

This collection is a set of **worked answers to OOP-basics homeworks**, shared so newer students can see how small assignments are solved with classes and objects.

- **What’s inside.** Each homework lives in its own folder with a Visual Studio solution (`.sln`), a project (`.vcxproj`), the source under `src/`, and a per-homework `README.md`.
- **How a homework README is organised.** It lists the *original assignment*, then the concrete *implementation*, the OOP *key ideas*, the *files*, how to *build & run*, a few *try-it-yourself* tweaks, and a *suggested reading order* for beginners.
- **Language.** The whole repo is written in English. The only Chinese character kept is **福** — the theme of homework 01 (see why in that folder).
- **No magic.** Everything uses only the C++ standard library — no external libraries, no CMake — so you can focus on the OOP ideas themselves.

---

## 📋 Homework overview

| 🏷️ HW # | 📝 Task | 🧠 Concepts practiced |
| :---: | :--- | :--- |
| 01 | 🖨️ [Console Pattern Printer (OOP) — “福”-themed](./FuPrinter/README.md) | Classes & objects, member functions, console output |
| 02 | 🔢 [Find GCD & LCM of Two Numbers](./GcdLcm/README.md) | Recursion, Euclid’s algorithm, input validation |


---

## 🛠️ Build & run (Visual Studio)

**Prerequisites** 🧰
- 🪟 Windows 10 or 11
- 🛠️ **Visual Studio 2022** with the *Desktop development with C++* workload

**Steps** 👇
1. 📂 Go into a homework folder, e.g. `FuPrinter/`
2. 🚪 Double-click `FuPrinter.sln` — Visual Studio opens the project
3. 🏗️ Pick a configuration from the toolbar: **Debug**/**Release** × **x86**/**x64**
4. 🧱 Hit **Build → Build Solution** (or `Ctrl+Shift+B`)
5. ▶️ Press **F5** to run — or `Ctrl+F5` to run *without* debugging so the console window stays open
6. 🎉 Watch the output appear in the terminal window!

> 💡 All homeworks are **Win32 console applications** (subsystem `Console`, toolset **v143**, `WindowsTargetPlatformVersion 10.0`). Every project supports the same four configurations:

| Configuration | Platform | Vibe ✨ |
| :--- | :--- | :--- |
| Debug | Win32 (x86) & x64 | Full checks on, slow & friendly 👀 |
| Release | Win32 (x86) & x64 | Optimized & ready to fly 🚀 |

---

Happy coding! ☕💻✨
