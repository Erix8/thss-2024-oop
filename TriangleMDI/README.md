# 🔺 TriangleMDI · A Multi-Document MFC Triangle Editor

Homework 08 — a **multi-document MFC** program that lets you create and edit a single triangle. This week’s material: creating a new MDI MFC project, the basic point / line-segment code, editing resources, adding a dialog class, and event/message handling.

The program stores one triangle (three vertices) in its document, and you can:
- create it by clicking the mouse,
- move a vertex by clicking in “edit vertex” mode,
- edit the three vertex coordinates directly through a dialog,
- save / load the triangle to / from a **self-describing text file**.

---

## 📋 The assignment

Write an MDI MFC program that lets you create and edit **a single triangle**:

- The triangle has three vertices (each a point with x and y).
- The triangle’s three vertex coordinates can be **saved to / loaded from a text file**, using a **self-describing file** mechanism (the file says what it contains).
- The triangle can be **created with the mouse**, and each **vertex can be moved** with the mouse.
- The vertex coordinates can be **edited directly in a dialog**.

✅ This folder implements all of it.

---

## 🧠 Key ideas

**Course knowledge**: creating a new multi-document MFC project, point & line-segment base code, editing resources, adding a dialog class, and handling events/messages.

The custom (student-written) layer was tidied into clear names:

| Custom piece | Role |
| :--- | :--- |
| `Point2D` | a 2-D point (x, y) |
| `Triangle2D` | a triangle with three vertices `vertex1`, `vertex2`, `vertex3` |
| `TriangleDrawing` | `DrawTriangle(CDC&, const Triangle2D&, …)` — draws the outline |
| `CTriangleEditDialog` | modal dialog that edits the six coordinates (`x1..y3`) |

How it is wired into the MFC app (the wizard identifiers like `CMFCApplicationOOPWeek8Doc/View` are left unchanged):

- The **Document** holds the data — `Triangle2D m_triangle` — and its `Serialize` reads/writes the file.
- The **View** paints the triangle in `OnDraw` (via `DrawTriangle`) and reacts to the mouse (`OnLButtonDown`) and to menu commands:
  - `OnResetTriangle` — reset and draw a fresh triangle by clicking 3 points;
  - `OnEditVertex1 / 2 / 3` — choose a vertex to move by clicking;
  - `OnEditCoordinates` — open `CTriangleEditDialog`.
- The **dialog** edits the coordinates; `DoDataExchange` binds the six edit boxes (resource ids `IDC_POINT_1_X` … `IDC_POINT_3_Y`) to `x1,y1,…,y3`.

**Self-describing file**: `Serialize` writes markers so the file explains its own content:

```text
#Triangle2D begin
100,150,300,120,200,260
#Triangle2D end
```

Each line is the three vertices’ `x,y` pairs. On loading, the program scans for the `begin` marker, reads the line, and fills the triangle.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`TriangleMDI.sln`](TriangleMDI.sln) | 🚪 Visual Studio **solution** — open this to build the MDI app |
| `src/MFCApplication_OOP_Week_8.vcxproj` | 🧱 The MFC project (keeps its original wizard name) |
| `src/Point2D.h/.cpp` | 📜 A 2-D point |
| `src/Triangle2D.h/.cpp` | 📜 The triangle (three vertices) |
| `src/TriangleDrawing.h/.cpp` | 🎨 `DrawTriangle` (CDC outline drawing) |
| `src/TriangleEditDialog.h/.cpp` | 🪟 The vertex-coordinate edit dialog |
| `src/*Doc.*`, `src/*View.*`, `src/*Main*`, `src/ChildFrm.*`, `src/pch.*`, `src/*.rc`, `src/res/` | 🧩 Wizard-generated MFC MDI files + resources |

> 💡 The geometry / drawing / dialog classes are custom and cleaned up; the wizard-generated MFC shell keeps its original `MFCApplication_OOP_Week_8` names.

---

## 🛠️ Build & run

**Prerequisites** 🧰
- 🪟 Windows + **Visual Studio 2022**
- **Desktop development with C++** workload, including **MFC**

**Steps** 👇
1. Open [`TriangleMDI.sln`](TriangleMDI.sln).
2. Pick a configuration (e.g. `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** and try the workflow below.

> 🚧 Note: MFC only builds on Windows/Visual Studio. This repo is edited on macOS, so please build in VS once to confirm.

**Suggested workflow**
1. Choose the “draw triangle” command, then click three times in the window — a triangle appears.
2. Pick a vertex to move, click elsewhere, and watch that vertex follow the mouse.
3. Open the coordinate dialog, type new values, press OK — the triangle updates.
4. Save to a text file, then open it again (the self-describing format should restore it).

---

## ✏️ Try it yourself

- Draw a triangle, save the file, and look at it in a text editor — you’ll see the `#Triangle2D begin/end` markers (self-describing).
- Edit one vertex to a negative coordinate and confirm the triangle still draws.
- Move all three vertices so the triangle is upside down, then reload from the saved file to undo it.

---

## 🧭 Suggested reading order

1. `src/*Doc.*` → `Serialize` — see the self-describing save/load format.
2. `src/*View.cpp` → `OnDraw`, `OnLButtonDown`, and the `OnEdit*`/`OnReset*` handlers — see mouse drawing and vertex editing.
3. `src/TriangleEditDialog.*` and `src/TriangleDrawing.*` — see the dialog DDX binding and the drawing call.
