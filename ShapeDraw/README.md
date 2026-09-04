# 🎨 ShapeDraw · A Single-Document MFC Drawing (CDC)

Homework 07 — a **single-document MFC** program that draws a picture with GDI. The picture is a little face built from three *custom shape classes*, and it uses **three or more colours**. The drawing is done in the view’s `OnDraw` using a `CDC`, exactly the week’s topic (MFC basics, SDI applications, and drawing with the `CDC` class).

---

## 📋 The assignment (what you were asked to do)

- Write an **MFC program** that draws a nice picture on a graphical interface.
- The picture must be built from **at least 3 custom shape classes** (the shapes and their meaning are up to you).
- The picture must use **at least 3 different colours**.

✅ This folder draws a smiley face: a pink round face, two white eyes with blue centres, and a black smile — that is 4 colours (pink, white, blue, black) and 3 custom shapes (circle, ellipse, arc).

---

## 🧠 This week’s ideas & how the code uses them

**Course knowledge**: MFC overview, a basic single-document MFC program, drawing line segments / shapes in an SDI view, and drawing with the `CDC` class.

A wizard-created MFC app splits the work into classes (the generated identifiers like `CMFCApplicationOOPWeek7Doc` are left untouched):

- The **Document** (`…Doc.h`) stores the *data* to draw — the shape objects.
- The **View** (`…View.h/.cpp`) is where the picture is actually painted in `OnDraw(CDC* pDC)`.
- The custom **shape classes** describe geometry; the **`DrawShapes`** functions turn that geometry into GDI calls (`dc.Ellipse`, `dc.Arc`).

The custom (student-written) layer was tidied up:

| Custom piece | Role |
| :--- | :--- |
| `Point2D` | a 2-D point (x, y) |
| `Circle2D` | a circle: centre, radius, bounding square |
| `Arc2D` | an arc: bounding rectangle + start/end of the arc |
| `Ellipse2D` | an ellipse: centre, two semi-axes, bounding box |
| `DrawShapes` | `DrawCircle` / `DrawArc` / `DrawEllipse` — draw each shape onto a `CDC` with a colour |

`Document` holds `face` (a `Circle2D`), four eye ellipses (`Ellipse2D`) and two mouth arcs (`Arc2D`); `OnDraw` fetches them and hands each to the matching `Draw*` function with a colour. For example:

```cpp
DrawCircle(*pDC, pDoc->face, PS_SOLID, 231, 108, 163);  // pink face
DrawEllipse(*pDC, pDoc->leftEyeBlue, PS_SOLID, 0, 159, 233); // blue eye
DrawArc(*pDC, pDoc->mouthArc1, PS_SOLID, 0, 0, 0);        // black smile
```

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`ShapeDraw.sln`](ShapeDraw.sln) | 🚪 Visual Studio **solution** — open this to build the MFC app |
| `src/MFCApplication_OOP_Week7.vcxproj` | 🧱 The MFC project (keeps its original wizard name) |
| `src/Point2D.h/.cpp` | 📜 A 2-D point |
| `src/Circle2D.h/.cpp` | 📜 The circle shape |
| `src/Arc2D.h/.cpp` | 📜 The arc shape |
| `src/Ellipse2D.h/.cpp` | 📜 The ellipse shape |
| `src/DrawShapes.h/.cpp` | 🎨 `DrawCircle` / `DrawArc` / `DrawEllipse` (CDC drawing) |
| `src/*Doc.*`, `src/*View.*`, `src/*Main*`, `src/pch.*`, `src/*.rc`, `src/res/` | 🧩 Wizard-generated MFC SDI application files |
| `src/*.rc`, `src/Resource.h`, `src/res/*` | 🖼️ Resources (icons, menus, toolbar) |

> 💡 The custom geometry/drawing layer is named cleanly (`Circle2D`, `Arc2D`, `Ellipse2D`, `DrawShapes`); the wizard scaffolding keeps its original `MFCApplication_OOP_Week7` names so the MFC project stays easy to open and rebuild.

---

## 🛠️ Build & run

**Prerequisites** 🧰
- 🪟 Windows + **Visual Studio 2022**
- The **Desktop development with C++** workload, including the **MFC** component

**Steps** 👇
1. Open [`ShapeDraw.sln`](ShapeDraw.sln).
2. Pick a configuration (e.g. `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Press **`Ctrl+F5`** — a window opens and draws the face.

> 🚧 Note: MFC only builds on Windows/Visual Studio. This repo is edited on macOS, so please build in VS once to confirm.

---

## ✏️ Try it yourself

- Change the colour numbers in `OnDraw` (e.g. make the face blue) and re-run.
- Resize or move a shape by editing the numbers passed to the shapes in the document constructor (centre, radius, semi-axes).
- Add a 4th custom shape (e.g. `Triangle2D` + a `DrawTriangle`) and draw extra details — the required minimum is already met.

---

## 🧭 Suggested reading order

1. Read `src/*Doc.h` and the document constructor in `src/*Doc.cpp` — this is where the shape objects are created and positioned.
2. Read `src/DrawShapes.h/.cpp` — see how each shape becomes a `CDC` call.
3. Read `src/*View.cpp` → `OnDraw` — see how the document data is painted.
