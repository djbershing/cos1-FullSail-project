markdown
# Milestone 2 Planning Worksheet

## 📌 Project Overview

**Project Name:** Terminal Task Manager

**What does your program currently do? (1–3 sentences)**
My program is an interactive command-line application that allows users to manage a dynamic collection of personal tasks. It features a fully responsive text menu that allows users to add tasks with customized titles, descriptive notes, and priority metrics, view all current tasks in an organized list format, and dynamically toggle individual task completion statuses.

---

## 🔍 Current Progress Check

**What is working right now?**
* The `MenuController` class successfully runs an application execution loop and performs numeric input cleaning to reject malformed choices.
* The `TaskManager` class successfully stores individual instances inside a dynamic `std::vector<Task>` collection.
* Dynamic state modification works perfectly; users can select an index to invoke the `markComplete()` method, altering the display flag seamlessly.
* Custom visual formatting outputs clear labels ("Low", "Medium", "High") based on integer tracking attributes.

**What is NOT working or incomplete?**
* The list data is completely volatile; since file input/output streams are not implemented yet, all added records are entirely cleared from system memory whenever the application exits.
* There is currently no option to delete or remove an unwanted task from the tracking vector once it has been appended.

**What feels confusing or messy in your code?**
* Managing the index offsets between the user interface layout (which is 1-based indexing for ease of human interaction) and the backend vector storage container (which requires traditional 0-based array index keys) felt error-prone and required precise mathematical subtractions (`choice - 1`) inside the controller.

---

## 🚀 Feature Planning

### Feature 1
* **Name:** Task Entry Creation Pipeline
* **What does this feature do?** Captures continuous string inputs for a task title and detailed description, forces a bounded selection loop for priority values (1 through 3), instantiates a structured `Task` object, and inserts it straight into the array.
* **Why is this feature important?** It forms the data collection foundational pillar of the task manager, giving users the precise customization necessary to track actual, variable objectives.

### Feature 2
* **Name:** Reactive Status Checklist Display
* **What does this feature do?** Loops over every structural record inside the data collection vector and draws a cleanly formatted text report. Completed entities are visually highlighted using an `[X]` box layout mark, while pending entries hold an open `[ ]` blank container block.
* **Why is this feature important?** It delivers essential immediate visual feedback, allowing users to rapidly scan their current productive workloads and evaluate project density at a glance.

### Feature 3 (Optional)
* **Name:** Contextual Dynamic Task Completion Setter
* **What does this feature do?** Evaluates the total length of the active tracking vector, prompts the user to submit a single item index choice key, applies a strict array-bounds validation guard, and invokes internal logic switches to flip the boolean completion status.
* **Why is this feature important?** It moves the system state from a static, read-only layout into an interactive program where users can record real milestone achievements.

---

## 🛠️ System Design Updates

**Will you need to create any new classes? If so, which ones?**
No new classes are required for this milestone phase. The current object architecture cleanly partitions responsibilities across three files: data definitions (`Task`), collection operations (`TaskManager`), and display routines (`MenuController`).

**Will you modify any existing classes? How?**
Yes, all existing interface class declarations will be expanded in upcoming cycles to support file system read/write pathways. Specifically, `TaskManager` will incorporate `std::ifstream` and `std::ofstream` handlers to automatically load and persist tracking logs directly to the computer disk.

**What data structures will you use (vectors, 2D vectors, etc.)?**
A sequential standard template library vector container (`std::vector<Task>`) is used. This fits the prototype perfectly because it natively handles dynamic scaling, continuous element blocks, and simple array-style bracket lookups.

---

## 🔀 Program Flow

**Describe how a user interacts with your program:**
1. **Program starts** $\rightarrow$ The `main()` entry routine instantiates structural dependencies, passes control to the application driver, and outputs the primary terminal menu display options.
2. **User chooses** $\rightarrow$ The client interacts with the terminal line prompt and inputs a command integer (such as selecting `2` to initiate the task insertion workflow).
3. **Program responds** $\rightarrow$ The console clears context lines, captures the text data strings, appends a new node item, and provides a success notification confirmation message.
4. **Loop/next step** $\rightarrow$ The terminal execution cycle loops smoothly back to the top of the interface routine block, exposing the core menu choices to wait for the next user event.

---

## 🎨 Usability Improvements

* **Clearer prompts:** The priority input pipeline explicitly informs the end user of the exact domain space values expected by writing out `(1 = Low, 2 = Medium, 3 = High):` instead of expecting blind inputs.
* **Better error handling:** Input streams are guarded by continuous evaluation loops containing `std::cin.clear()` and `std::cin.ignore()` blocks, trapping alphabetic letters or garbage inputs without freezing or crashing.
* **Improved menu/navigation:** All menu item rows are perfectly structured on distinct screen lines utilizing intentional, precise newline controllers (`\n`) for clean visualization.

---

## ⚠️ Potential Challenges

**What do you think will be the hardest part this week?**
Ensuring that multiple distinct implementation classes communicated across header definitions correctly without triggering circular compilation dependencies or variable scoping blocks was the toughest part. Overcoming the structural divergence between our `.h` declarations and `.cpp` scope mappings took careful adjustments.

**What is your plan if you get stuck?**
I plan to run explicit manual code traces using localized diagnostic logging steps, leverage official compiler error output codes to map hidden syntax typos, and test isolated routines systematically within minimal sandbox test blocks.

---

## 📈 Level Up Goal

**What skill are you focusing on improving this week?**
I am focusing on mastering strict Object-Oriented compilation linkages, header guard structures, and class method scoping syntax within multi-file C++ project layouts.

**What will you do to improve it?**
I am systematically studying terminal compiler invocations (using Microsoft's Native compiler `cl` flags), tracking variable declaration patterns closely, and practicing mapping complex multi-object configurations directly from planning blueprints.

---

## 📋 Task Breakdown (GitHub Issues Planning)

* [X] Set up core multi-file structure layout rules for definitions and implementations.
* [X] Code the data encapsulation classes for singular task element models.
* [X] Build the central vector registry system to manipulate tracking blocks.
* [X] Code the robust menu navigation driver