# 📅 Calendar · A Safe Date Class

Homework 04 — this is the week we learn **encapsulation**: we hide a class’s data behind a private wall and let it out (or change it) only through *methods* that check the rules. `Calendar` stores a year-month-day, but because the data is `private`, an invalid date can never sneak in — month is always 1–12, and day is always a real day of the Gregorian calendar.

---

## 📋 The assignment

- Design a **calendar class** whose data is a year, a month and a day.
- Use OOP so that:
  - the **year** may be any integer;
  - the **month** is always between 1 and 12;
  - the **day** is always between 1 and the real number of days in that month/year of the **Gregorian (solar) calendar** — no 31 Feb, no 29 Feb unless it is a leap year, and so on.
- Through an instance you can **set / get / print** the stored year-month-day, and you can ask for the date that comes **`n` days later** — where `n` is any integer: positive, negative, or zero.
- Then build one instance, set it to **today’s date**, read an integer `n` from the user, and print the date `n` days later.

✅ This folder implements all of it, with the focus on *encapsulation*.

---

## 🧠 Key ideas

Without encapsulation you could write `date.day = 32;` and break everything. Here the fields are **private**, so the outside world simply cannot touch them. The only doorways are the setters, which check every value first, and the getters, which only read:

| Term | What it means here | In the code |
| :--- | :--- | :--- |
| **Encapsulation** | Bundle the data *and* its rules together; hide the data | data members are `private` in `Calendar` |
| **`private` data** | Outside code can’t read/write it directly | `year_`, `month_`, `day_` |
| **Public interface** | The methods that let the world safely use the object | setters / getters / `addDays()` / `print()` |
| **Setter with validation** | A way to change data *only if the new value is legal* | `setMonth()`, `setDay()`, `setDate()` |
| **Invariant** | A property that is always true while the object exists | month ∈ [1,12]; day is real for that month/year |
| **Private helper** | Detail callers never need to see | `isLeapYear()`, `daysInMonth()` |

For example, `setDay()` refuses to store a day that doesn’t exist in the current month/year:

```cpp
void Calendar::setDay(int day)
{
    int maxDay = daysInMonth(year_, month_);   // 28, 29, 30 or 31
    if (day >= 1 && day <= maxDay)
    {
        day_ = day;
    }
    else
    {
        std::cout << "Day " << day << " is not valid. Change ignored.\n";
    }
}
```

Because the rules live *inside* the class next to the data, no code outside can put the object into a bad state. That is the whole point of encapsulation.

To move the date, `addDays(n)` simply adds `n` to the day and then normalizes — carrying overflow into the next month/year for a positive `n`, or borrowing from the previous month/year for a negative `n`. Leap years are handled because `daysInMonth()` asks `isLeapYear()` every time it needs February’s length.

---

## 📁 Files

| File | Role |
| :--- | :--- |
| [`Calendar.sln`](Calendar.sln) | 🚪 Visual Studio **solution** — double-click this to open the project |
| [`src/Calendar.vcxproj`](src/Calendar.vcxproj) | 🧱 Project file (tells VS which source files to build) |
| [`src/Calendar.h`](src/Calendar.h) | 📜 `Calendar` class declaration — private data + public interface |
| [`src/Calendar.cpp`](src/Calendar.cpp) | ⚙️ Implementation — validation, leap years, `addDays()`, printing |
| [`src/Main.cpp`](src/Main.cpp) | 📍 Entry point — builds today’s date, reads `n`, prints `n` days later |

> 💡 Rule of thumb: the **header** (`.h`) *declares* the class and shows *what* it can do; the **`.cpp`** *defines* how each method works; **`main()`** is the outside user who can only use the public methods.

---

## 🛠️ Build & run

1. Open [`Calendar.sln`](Calendar.sln) in **Visual Studio 2022**.
2. Pick a configuration (say `Debug/x64`) and hit **Build → Build Solution** (`Ctrl+Shift+B`).
3. Run with **`Ctrl+F5`** (keeps the console window open). 🚀

A sample session (today being, say, `2026-9-5`):

```text
Today is 2026-9-5
Enter n (days to move; any integer, e.g. negative goes back): 45
After 45 days it is 2026-10-20
```

---

## ✏️ Try it yourself

- Try `n = 0` (date should not change), a big positive value (it should roll into a later year), and a negative value (it should go back, even across a year boundary).
- Play with dates near the end of February in a leap year, e.g. call `setDate(2024, 2, 28)` then `addDays(1)` — it should land on the 29th.
- Try an invalid `setMonth(13)` or `setDay(31)` for February — the class rejects it instead of storing a nonsense date.

---

## 🧭 Suggested reading order

1. Read [`src/Calendar.h`](src/Calendar.h) — see the `private` data and the public methods that are the only way in.
2. Read [`src/Calendar.cpp`](src/Calendar.cpp) — see how each setter validates, how `isLeapYear()`/`daysInMonth()` work, and how `addDays()` normalizes.
3. Read [`src/Main.cpp`](src/Main.cpp) — build today’s date, read `n`, and print the result; notice `main()` never touches `year_`/`month_`/`day_` directly.
