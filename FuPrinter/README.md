# 🖨️ FuPrinter · A “福”-Themed Console Pattern

Homework 01 — for most people this is their **first C++ program**. The task is open-ended: print a nice picture in the console out of characters, and the picture is up to you. Our chosen picture is the lucky Chinese character **福** (fú).

The code here is intentionally small. It shows the usual *shape* of a C++ program: a `main()` that calls into a tiny class called `FuPrinter`. Don’t worry if the word *class* still feels fuzzy — this homework only meets it by example, and we really study what a class *is* in homework 02.

---

## 📋 The assignment (what you were asked to do)

- Write a program that forms a **nice-looking picture** in the console window by printing strings.
- The **content and shape of the picture are up to you**.
- Implement it with **object-oriented programming**.
- *Optional (no grade impact):* build a **GUI version**, and let the final picture be a combination of **at least 3 different sub-patterns**.

> ✅ This folder implements the **required console part** with OOP. The optional GUI bonus is **not** implemented here.

---

## 🎨 What does "a picture made of strings" mean?

In a console you can only print characters one line at a time. To "draw", you place your **symbol** where you want "ink" and put **spaces** where you want the picture to be empty. If each line is chosen so that the ink/spaces line up, the whole output reads like a picture.

A tiny schematic (this is just to illustrate the idea, not the real “福” output):

```text
  &        <- some spaces, then symbols
 & &
&&&&&      <- wider rows can fill big areas
```

Now replace the rows above with rows that trace the strokes of **福**, keep the alignment right, and the console prints a giant “福” made of `&`. That is exactly what `drawFu()` does.

---

## 🧠 What to notice in the code

A C++ program starts in `main()`. Here `main()` uses a small *class* named `FuPrinter`:

- `FuPrinter` remembers **one piece of data** — the `symbol_` it should draw with.
- Its `drawFu()` method knows how to turn that symbol into the rows of the “福” picture.
- `main()` builds an object and asks it to draw:

```cpp
FuPrinter printer('&');   // make a printer that will draw with '&'
printer.drawFu();          // ask it to draw (the object knows the rest)
```

That is the whole idea for now: a class bundles some *data* (which symbol) with the *actions* that use it (drawing). If terms like class, object, attribute or method feel new, that’s completely fine — they are introduced here just by example, and homework 02 explains them properly.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`FuPrinter.sln`](FuPrinter.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/FuPrinter.vcxproj`](src/FuPrinter.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/FuPrinter.h`](src/FuPrinter.h) | 📜 `FuPrinter` **class declaration** — what the class looks like |
| [`src/FuPrinter.cpp`](src/FuPrinter.cpp) | ⚙️ Class **implementation** — where the drawing magic happens |
| [`src/Main.cpp`](src/Main.cpp) | 📍 **Entry point** — builds the object and triggers the draw |

> 💡 *Rule of thumb used here:* the **header** (`.h`) *declares* "this class exists and has these methods", while the **`.cpp`** *defines* "here is exactly how those methods work". `main()` is the door in — it creates an object and tells it to act.

---

## 🛠️ Build & run

1. Open [`FuPrinter.sln`](FuPrinter.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Press **F5** (or `Ctrl+F5` to keep the window open). 🚀
4. Enjoy the “福”! 🎉

---

## ✏️ Try it yourself

- Swap the drawing character in [`src/Main.cpp`](src/Main.cpp): `FuPrinter printer('&');` → try `'*'`, `'#'`, `'@'`… 🎨
- Tweak the spacing inside `drawFu()` in [`src/FuPrinter.cpp`](src/FuPrinter.cpp) and watch the pattern reshape itself. 🤓
- *Bonus itch?* Re-shape the output so it combines a few sub-patterns, or wrap it in a GUI window. ✨

---

## 🧭 Suggested reading order for beginners

1. Read [`src/Main.cpp`](src/Main.cpp) — the shortest file, it shows the "outside view" (make object → call method).
2. Skim [`src/FuPrinter.h`](src/FuPrinter.h) — see the class shape: an attribute and a method.
3. Read [`src/FuPrinter.cpp`](src/FuPrinter.cpp) — see how `drawFu()` actually prints each row of the pattern.
