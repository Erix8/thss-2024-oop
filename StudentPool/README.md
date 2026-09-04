# 📚 StudentPool · Student Manager with a Factory-Method Node Pool

Homework 13 — this chapter introduces **design patterns**: the adapter and the **factory method**. Building on homework 6 (a sorted doubly linked list of students), this version uses the *factory* idea to **reuse list nodes** instead of allocating and freeing them all the time.

---

## 📋 The assignment (what you were asked to do)

Manage a student id/score form. Define:

- a **product class** — a doubly linked list of the students **in use** (the form);
- a **factory class** — a doubly linked list of the students **not in use** (spare nodes).

The factory’s nodes are *reserve* nodes: they are given to the product when it needs one, and returned when the product no longer needs them, so memory is not constantly allocated/freed.

Commands:

| Command | Action & the node rule |
| :--- | :--- |
| `1` | add several students (id + score; end with id `0`). Each add **takes one node from the factory**; if the factory is empty it allocates a new one. |
| `2` | delete the FIRST student with a given id → its node is **returned to the factory**. |
| `3` | delete ALL students with a given score → all those nodes are **returned to the factory**. |
| `4` | show the score of the first student with a given id |
| `5` | show the ids of all students with a given score |
| `6` | show all students |
| `-1` | exit → **delete** the nodes of both the product list and the factory list (no leaks) |

✅ This folder does all of the above. Whether the list is sorted by id is up to the designer — here it is kept sorted ascending by id.

---

## 🧠 Design & key ideas — the factory / node pool

Two classes share the same node type (`StudentNode`, with `prev`/`next`):

- **`NodeFactory`** keeps a doubly linked list of **spare** nodes. It can `acquire()` (pop a spare node, or `new` one if the pool is empty) and `release()` (push a node back).
- **`StudentForm`** (the product) keeps the **in-use** nodes sorted by id. It does not create or delete nodes itself — it borrows them from the factory and hands them back.

```cpp
// add a student  -> take a spare node (or allocate), then insert it
StudentNode* node = factory.acquire();
node->id = id; node->score = score;
insertSorted(node);

// delete a student -> remove from the form, give the node back
unlink(node);
factory.release(node);   // reuse it later instead of freeing it now
```

The factory prints how many spare nodes it is holding, so you can *see* the reuse: deleting students makes the spare count grow, and the next `add` reuses those nodes instead of calling `new` again. On `-1`, the form returns every node to the factory and the factory then deletes them all — no leaks.

This is why it is a “factory method / object pool” answer rather than the naive version that does `new` on every add and `delete` on every remove.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`StudentPool.sln`](StudentPool.sln) | 🚪 Visual Studio **solution** — double-click to open the project |
| [`src/StudentPool.vcxproj`](src/StudentPool.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/StudentPool.h`](src/StudentPool.h) | 📜 `StudentNode`, `NodeFactory`, `StudentForm` declarations |
| [`src/StudentPool.cpp`](src/StudentPool.cpp) | ⚙️ doubly linked lists, acquire/release, commands’ logic |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — the interactive command menu |

---

## 🛠️ Build & run

1. Open [`StudentPool.sln`](StudentPool.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

After every `add`/`delete` the program prints the in-use count and the factory spare count, so you can watch nodes being recycled.

---

## ✏️ Try it yourself

- `add` several, then `delete` one and add another — the “spare” count shows the node is reused, not reallocated.
- `delete` all with a score (command `3`) and watch many nodes go back at once.
- Change the sort choice in `StudentForm` (e.g. keep insertion order instead of sorting by id).

---

## 🧭 Suggested reading order

1. Read [`src/StudentPool.h`](src/StudentPool.h) — see the factory’s `acquire`/`release` and the form’s methods.
2. Read [`src/StudentPool.cpp`](src/StudentPool.cpp) — watch nodes move between the factory pool and the sorted form.
3. Read [`src/Main.cpp`](src/Main.cpp) — how each command maps to borrowing/returning nodes.
