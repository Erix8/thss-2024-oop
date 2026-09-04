# 🔷 ShapeCalc · A Shape Perimeter & Area Calculator (Inheritance)

Homework 03. In homework 02 we learned *what a class is*; here we take the next step: **inheritance**. `ShapeCalc` is a small menu-driven program that keeps building shapes and, at the end, reports how many were drawn plus the total perimeter and area. The point is inheritance — we give the five shapes one shared base class and let each derived class add its own maths.

---

## 📋 The assignment (what you were asked to do)

The program reads a command (a positive integer) in a loop:

| Command | Action |
| :--- | :--- |
| `1` | read the side of an **equilateral triangle**, build it, print its perimeter & area |
| `2` | read the side of a **square**, build it, print its perimeter & area |
| `3` | read the side of a **regular pentagon**, build it, print its perimeter & area |
| `4` | read the side of a **regular hexagon**, build it, print its perimeter & area |
| `5` | read the **radius of a circle**, build it, print its perimeter (circumference) & area |
| `0` | print the **number of shapes**, the **total perimeter** and the **total area**, then exit |

✅ This folder implements it using inheritance: a base class `Shape` plus one derived class per shape.

---

## 🧠 Design & key ideas — inheritance

Look at the five shapes: each is described by **one length** (the side of a regular polygon, or the radius of a circle). That shared trait belongs in one **base class**; each specific shape is a **derived class** that inherits it and adds its own behaviour.

```cpp
class Shape { ... };            // the common part: stores the size and pi
class Triangle : public Shape { ... };   // inherits Shape's size, adds its own maths
```

| Term | What it means here | In the code |
| :--- | :--- | :--- |
| **Base class** | The common idea shared by every shape — it stores the one length, keeps `pi`, and has a constructor | `Shape` |
| **`protected` member** | Members the base keeps for derived classes to use (inheritance needs this) | `size_`, `pi` |
| **Derived class** | A “kind of shape” that inherits the base and adds its own members | `Triangle`, `Square`, `Pentagon`, `Hexagon`, `Circle` |
| **Inheritance / IS-A** | “A `Triangle` **is a** `Shape`”, so it automatically has `Shape`’s size and constructor | `class Triangle : public Shape` |
| **Constructor chaining** | A derived constructor hands its argument up to the base constructor | `Triangle(double side) : Shape(side) {}` |

Because each shape inherits `size_`, none of the derived classes needs to store its own length again — they just use the one they got from `Shape`. The same goes for `pi`: it lives once in `Shape`, and `Pentagon` / `Hexagon` / `Circle` simply use it instead of re-declaring it. Each derived class then defines its own **ordinary member functions** `perimeter()` and `area()` with that shape’s formula. (At this point in the course we haven’t covered polymorphism, virtual functions or encapsulation yet, so these are plain functions called by name on the concrete object.)

In `main()` each command builds the matching concrete object — e.g. `Triangle shape(size);` — reads its `perimeter()`/`area()`, and adds the numbers to three ordinary variables (`count`, `totalPerimeter`, `totalArea`). The shape is a local object, so it is cleaned up automatically when its `case` ends.

The maths lives in each derived `.cpp`. For example `Pentagon::area()` uses the general regular-polygon formula `area = (n/4) · side² · cot(π/n)` with `n = 5`; `Circle::area()` uses `π · r²`.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`ShapeCalc.sln`](ShapeCalc.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/ShapeCalc.vcxproj`](src/ShapeCalc.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/Shape.h`](src/Shape.h) · [`Shape.cpp`](src/Shape.cpp) | 📜 Base class: stores the shared `size_` and `pi`, plus a constructor |
| [`src/Triangle.h`](src/Triangle.h) · [`Triangle.cpp`](src/Triangle.cpp) | 🔺 Equilateral triangle (3 sides) |
| [`src/Square.h`](src/Square.h) · [`Square.cpp`](src/Square.cpp) | ⬛ Square (4 sides) |
| [`src/Pentagon.h`](src/Pentagon.h) · [`Pentagon.cpp`](src/Pentagon.cpp) | ⬠ Regular pentagon (5 sides) |
| [`src/Hexagon.h`](src/Hexagon.h) · [`Hexagon.cpp`](src/Hexagon.cpp) | ⬡ Regular hexagon (6 sides) |
| [`src/Circle.h`](src/Circle.h) · [`Circle.cpp`](src/Circle.cpp) | ⚪ Circle (radius) |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Menu loop — builds one concrete shape per command and adds up the totals |

> 💡 Rule of thumb: **headers** (`.h`) *declare* the classes, each **`.cpp`** *defines* a class’s members, and **`Main.cpp`** is the outside user that drives everything.

---

## 🛠️ Build & run

1. Open [`ShapeCalc.sln`](ShapeCalc.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

A sample session (read `side` for shapes, `radius` for the circle):

```text
> 1          -> build Triangle
Enter side length: 3
Triangle: perimeter = 9, area = 3.89711
> 5          -> build Circle
Enter radius: 2
Circle: perimeter = 12.5664, area = 12.5664
> 0
Shapes drawn: 2
Total perimeter: 21.5664
Total area: 16.4635
```

---

## ✏️ Try it yourself

- Mix several shapes and sizes, then press `0` to check the totals against a quick hand-calc.
- Type an out-of-range command (like `9`) — you should get an “Unknown command” and be asked again.
- Feed a non-positive size — the program rejects it instead of building a nonsense shape.

---

## 🧭 Suggested reading order for beginners

1. Read [`src/Shape.h`](src/Shape.h) and [`src/Shape.cpp`](src/Shape.cpp) — the base class that stores the shared `size_` and `pi`.
2. Open [`src/Triangle.h`](src/Triangle.h) and [`src/Triangle.cpp`](src/Triangle.cpp) — see a derived class inherit `Shape` and add its own `perimeter()`/`area()`.
3. Read [`src/Main.cpp`](src/Main.cpp) — each `case` builds a concrete shape and adds its numbers to three plain totals.
4. Compare `Square` / `Pentagon` / `Hexagon` / `Circle` to see how each only changes the formula.
