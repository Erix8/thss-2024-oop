# 🖨️ FuPrinter · A “福”-Themed Console Pattern

`FuPrinter` is one concrete answer to an **open-ended** assignment: it uses object-oriented code to print a pretty picture in the console, built line by line out of a symbol you can swap. The picture chosen here is the lucky Chinese character **福** (fú).

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

## 🧠 Key ideas (OOP in this tiny example)

The naive way is to dump all the `cout` lines straight into `main()`. But this course is about **object-oriented programming**, so the solution instead bundles the *data* and the *behaviour* into one class:

| OOP term | What it means here | In the code |
| :--- | :--- | :--- |
| **Class** | A blueprint describing "a printer of 福 pictures" | `FuPrinter` |
| **Object (instance)** | A real printer you can actually ask to draw | `printer` in `main()` |
| **Member attribute** | The data the object remembers — which symbol to draw | `symbol_` |
| **Member function (method)** | The behaviour the object knows — how to draw the pattern | `drawFu()` |

Why bother wrapping it in a class? Because the two ideas that belong together — *"which character do I draw with"* (data) and *"how to draw 福"* (behaviour) — now live in **one place**, and `main()` only has to talk to the object through its public method. `main()` never needs to know *how* the pattern is drawn; it just calls `drawFu()`. That separation of concerns is the heart of OOP.

```cpp
FuPrinter printer('&');   // make an object, remember to use '&'
printer.drawFu();          // ask it to draw (the object knows the rest)
```

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
