# 📊 ScoreSheet · A Student Score-Sheet Editor & Storage

Homework 11 — this chapter is about **streams**: stream concepts, stream classes/objects, standard input/output streams, formatting, and **file input/output streams**. So this homework is a small editor for a student **score sheet** that can be stored in and reloaded from a **text file**.

---

## 📋 The assignment

A score sheet holds several students (each an id and a score); it starts empty. The command number controls the operation:

| Command | Action |
| :--- | :--- |
| `1` | read a score sheet from a file and **merge** it into the current sheet |
| `2` | add one student (id + score) |
| `3` | delete the student with a given id |
| `4` | delete **all** students |
| `5` | change the score of a given id |
| `6` | show the score of a given id |
| `7` | show all students (id + score) |
| `8` | save the current sheet to a file |
| `-1` | exit |

Design your own file format — but a sheet saved by command `8` must be readable again by command `1` (all ids and scores restored).

✅ This folder does all of the above, with a **plain round-trip file format**.

---

## 🧠 Key ideas

- `Student` — one record (id + score).
- `ScoreSheet` — a list of students (`std::vector<Student>`) plus the commands’ logic and the file I/O.
- The stream classes used: `std::cin`/`std::cout` for the console, `std::ifstream`/`std::ofstream` for files, and `std::fixed`/`std::setprecision` for formatting.

**Self-designed file format** (the important requirement): each line is exactly

```text
<id> <score>
```

for example:

```text
2023010001 90.50
2023010002 80.25
```

Only plain data lines are written — **no header/footer text or labels**. That is what makes the round trip work: what command `8` writes is exactly what command `1` reads back. (A common bug is decorating the file with text and then failing to read it back; here the format is kept data-only.)

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`ScoreSheet.sln`](ScoreSheet.sln) | 🚪 Visual Studio **solution** — double-click to open the project |
| [`src/ScoreSheet.vcxproj`](src/ScoreSheet.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/Student.h`](src/Student.h) · [`Student.cpp`](src/Student.cpp) | 📜 One student record (id + score) |
| [`src/ScoreSheet.h`](src/ScoreSheet.h) | 📜 `ScoreSheet` declaration + documented file format |
| [`src/ScoreSheet.cpp`](src/ScoreSheet.cpp) | ⚙️ commands’ logic and file read/write |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — the interactive command menu |
| [`sample_records.txt`](sample_records.txt) | 🧪 A small sample sheet you can load with command `1` |

---

## 🛠️ Build & run

1. Open [`ScoreSheet.sln`](ScoreSheet.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

A quick round-trip test you can do by hand:

1. command `2` → add `2023010001 90.5`, then `2023010002 80.25`;
2. command `8` → save to e.g. `sheet.txt`;
3. command `4` → delete everything (now empty);
4. command `1` → read `sheet.txt` back;
5. command `7` → the two students are back, with the same scores.

---

## ✏️ Try it yourself

- Load [`sample_records.txt`](sample_records.txt) with command `1` and show it with command `7`.
- Delete one id (command `3`), then save and reload — only the remaining students come back.
- Read the saved file in a text editor and check it is just the plain `id score` lines.

---

## 🧭 Suggested reading order

1. Read [`src/Student.h`](src/Student.h) — the tiny record.
2. Read [`src/ScoreSheet.h`](src/ScoreSheet.h) — the method list and the documented file format.
3. Read [`src/ScoreSheet.cpp`](src/ScoreSheet.cpp) — focus on `readFromFile` / `writeToFile` (file streams) and `printAll` (formatting).
4. Read [`src/Main.cpp`](src/Main.cpp) — how each command maps to a method.
