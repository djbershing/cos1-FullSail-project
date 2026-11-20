# 🚀 Welcome to Project & Portfolio!

This repository will be used to keep track of research and development conducted in this class. Follow the instructions below to get started.
cos
### Getting Started

**1.** Review the [About](./docs/01_about/README.md) README and all of the links it provides.

**2.** Review the documentation and [Getting Started](./docs/02_getting_started/README.md) steps in this repository's docs folder.

**3.** Attend the first Live Lecture to see a live setup demo. If you are unable to attend, make sure to watch the archive.

### Next Steps...

After completing the above steps, feel free to begin updating this readme where indicated below. Remember to update this document each week to receive proper credit for the weekly Milestone assignment.

<br>

> ❗️ &nbsp; Now that you have read to this point, go ahead and delete this sentence and everything above it.

<br>

# Project & Portfolio 1

### Student First & Last Name

Hello my name is [enter name]. I am a student from [where are you from?]. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Replace this paragraph with your stand up for this week. Use the prompts above to summarize your most recent milestone activity and work.

### Week 2

My next stand up will go here...

### Week 3

markdown
---

## Milestone 3 Project Stand-Up

* **What Was Completed:**
* Implemented persistent file I/O (`tasks.txt`) using `Task::serialize()` / `Task::deserialize()` and `TaskManager::saveToFile()` / `loadFromFile()`.
* Added task deletion (`MenuController::handleDeleteTask()` and `TaskManager::deleteTask()`), priority labels, and a live `Completed/Total` summary counter.
* Refactored `MenuController` to centralize integer and index input validation, enforced `const`-correctness across all classes, standardized `Task.h` naming, and fixed the menu numbering typo.
* **Current Status:**
* All Milestone 3 issues (#12–#15) are implemented, compiled, and verified on the `dev` branch and ready for Pull Request review into `main`.
* **Blockers & Next Steps:**
* No current blockers. Next steps include adding task editing and priority/status filtering in Milestone 4.




### Week 4


# Milestone 4: Final Polish, Error Handling, and Release
## Features Completed & Verified
- **Full CRUD Task Management:** Users can add tasks with titles, descriptions, and priority levels (`Low`, `Medium`, `High`), view formatted task lists with completion status, mark tasks complete, and delete tasks.
- **Persistent File Storage:** Tasks automatically serialize to `tasks.txt` on every modification and deserialize back into memory on startup.
- **Final Application Screenshots:** Added verified build and runtime screenshots inside `/images` demonstrating clean compilation, input validation, and core task workflows.

## Refactoring & Code Quality Improvements
- **Modern String-Based Integer Parsing (`#17`):** Refactored `MenuController::getValidIntegerInput()` to read full lines via `std::getline()` and parse numbers with `std::stoi()` inside `try/catch` blocks (`std::invalid_argument` and `std::out_of_range`), replacing `cin >>`, `cin.clear()`, and `cin.ignore()`.
- **Safe File Deserialization (`#18`):** Added `try/catch` exception handling and field-count validation inside `Task::deserialize()` so malformed or corrupted lines in `tasks.txt` safely fall back to default values rather than crashing the program.

## Bugs Resolved
**Buffer & Partial-Numeric Input Bug (`#17`):** Fixed an issue where mixed inputs (such as `12abc`) or out-of-range integers could leave trailing characters in the input stream or behave unpredictably; checking `pos == input.length()` now rejects any non-pure numeric input cleanly.
**Pipe Delimiter File Corruption (`#19`):** Resolved a data corruption bug where entering a `|` character in a task title or description broke pipe-delimited parsing in `tasks.txt`.

## Usability Improvements
 **Clear Delimiter Validation Feedback:** In `MenuController::handleAddTask()`, the application now immediately notifies the user (`"Title cannot contain the '|' character."`) and re-prompts instead of silently corrupting saved task data.
-**Consistent Re-Prompting Across Menus:** Every numeric prompt across main menu selection, priority assignment, task completion, and task deletion now uses unified validation messaging (`"Invalid input. Please enter a valid number: "`), making navigation predictable and crash-proof.


My final stand up...
