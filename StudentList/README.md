# 📚 StudentList · A Sorted Student Database (Doubly Linked List)

Homework 06 — this week’s lesson covers **pointers**, **pointers with const**, **lvalue references**, and **how function parameters are passed**. So this homework deliberately manages a **doubly linked list by hand** with `new`/`delete` and `prev`/`next` pointers, and one method even returns a result through a **reference parameter**. The list always stays sorted by student id (ascending).

---

## 📋 The assignment (what you were asked to do)

Build a small console management system. A student has a **positive integer id** and a **non-negative integer score**. The command number decides what happens:

| Command | Action |
| :--- | :--- |
| `1` | add several students (id + score), stop when id is `0` |
| `2` | delete the FIRST student with a given id |
| `3` | delete ALL students with a given score |
| `4` | show the score of the FIRST student with a given id |
| `5` | show the ids of ALL students with a given score |
| `6` | show all students |
| `-1` | exit |

Additional requirements:

- Use a **doubly linked list** to store the students.
- The list must always be kept sorted by id **ascending**.
- When adding, add **one student at a time**, and after each insertion the list must still be sorted.
- Test it — design **at least 5 different situations**.

✅ This folder does all of the above; `sample_input.txt` below is ready to paste to run a multi-step test.

---

## 🧠 Design & key ideas — a sorted doubly linked list

Two small classes keep things clear:

- `Student` — one record (id + score).
- `StudentList` — the list. It owns a chain of `Node`s; every node is created with `new` and linked by `prev` and `next` pointers.

| Idea | What it means here | In the code |
| :--- | :--- | :--- |
| **Doubly linked list** | Each node points to the one before and the one after | `Node::prev` / `Node::next` |
| **Pointer to heap node** | A node lives on the heap, reached through a pointer | `new Node(…)` in `add()` |
| **Insert-in-order** | Walk until we find the right spot, then link the new node in | `add()` |
| **Removing a node** | Unlink it from its neighbours, then `delete` it | `removeFirstById()`, `removeAllByScore()` |
| **Empty list** | `head_ == 0` means the list is empty | `printAll()` |
| **Destructor** | Walks the whole list and `delete`s every node | `~StudentList()` |
| **Out-parameter by reference** | A method hands a value back through `int& score` | `findScoreById(int id, int& score)` |
| **Pointer to const** | A read-only scan pointer: you may follow it, but can’t change the node through it | `const Node* cur` in `printAll()` / `findScoreById()` / `size()` |
| **Sorted invariant** | After every insert the ids are still in ascending order | kept by `add()` |

The heart is `add()`. Instead of adding anywhere and sorting later, it **searches for the right place first**:

```cpp
// Walk to the first node whose id is >= the new id, then link the new node
// between prev and cur — the list stays sorted with no extra pass.
Node* prev = 0;
Node* cur = head_;
while (cur != 0 && cur->student.id < id)
{
    prev = cur;
    cur = cur->next;
}
```

`findScoreById` is where a function *sends a value out through a reference parameter* — exactly the lesson’s “how parameters are passed”:

```cpp
bool StudentList::findScoreById(int id, int& score)   // score is an out-param
{
    // ... find the student ...
    score = cur->student.score;   // hand the answer back by reference
    return true;
}
```

Wherever a method only *reads* the list (looking up, counting, printing), it walks with a **pointer to const** (`const Node*`): you may follow the `next`/`prev` pointers, but the compiler will not let you accidentally change a node through it. That is exactly this week’s “pointers and const”. (The methods that *do* modify — insert and delete — use a plain `Node*` instead.)


---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`StudentList.sln`](StudentList.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/StudentList.vcxproj`](src/StudentList.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/Student.h`](src/Student.h) · [`Student.cpp`](src/Student.cpp) | 📜 One student record (id + score) |
| [`src/StudentList.h`](src/StudentList.h) | 📜 `StudentList` declaration (doubly linked list) |
| [`src/StudentList.cpp`](src/StudentList.cpp) | ⚙️ Pointer operations: sorted insert, delete, search, print |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — the interactive command menu |
| [`sample_input.txt`](sample_input.txt) | 🧪 Ready-to-paste sample run (see *Testing*) |

> 💡 Data lives in `Student`; the list logic lives in `StudentList`; the user interface lives in `main()`. Nothing else reaches into the nodes directly.

---

## 🛠️ Build & run

1. Open [`StudentList.sln`](StudentList.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

You can type commands by hand, or paste the whole [`sample_input.txt`](sample_input.txt) into the console to run a full test in one go.

---

## 🧪 Testing — at least five situations

The program is tested by running these five situations (the sample file combines several of them):

| # | Situation | How it is tested |
| :--- | :--- | :--- |
| 1 | **Add students given out of order** | add ids `201604, 201609, 201603, 201601, …` → command `6` shows them sorted ascending by id |
| 2 | **Add an extra student to a non-empty sorted list** | insert one more id and check the order is still ascending |
| 3 | **Delete the first student with a given id** | command `2`, id `201609` → that id disappears, others stay |
| 4 | **Delete all students with a given score** | command `3`, score `99` → every student with 99 is gone |
| 5 | **Look up by id / by score** | command `4` (id `201610` → its score) and command `5` (score `86` → its ids) |

A convenient end-to-end run is the contents of [`sample_input.txt`](sample_input.txt): it adds several students, deletes by id, deletes by score, looks up by id, lists ids by score, then exits with `-1`.

---

## ✏️ Try it yourself

- Add students in **reverse** order and confirm command `6` always prints them sorted.
- Try deleting an id that doesn’t exist, or a score that nobody has — the program reports “not found”.
- Feed invalid data (negative id, negative score) and see it rejected.
- Insert a student whose id sits between two existing ones, and confirm it lands in the middle.

---

## 🧭 Suggested reading order for beginners

1. Read [`src/Student.h`](src/Student.h) — the tiny data record.
2. Read [`src/StudentList.h`](src/StudentList.h) — see the `Node` chain and the method list.
3. Read [`src/StudentList.cpp`](src/StudentList.cpp) — focus on `add()` (insert in order), the delete methods (unlink + delete), and `findScoreById()` (reference out-parameter).
4. Read [`src/Main.cpp`](src/Main.cpp) — how each command maps to a list method.
