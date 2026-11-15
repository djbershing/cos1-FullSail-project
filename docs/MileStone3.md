markdown
# Milestone 3: Code Expansion, Refactoring & Project Stand-Up

## 1. Overview of New Features Implemented
Building upon the core task-tracking foundation established in Milestone 2, Milestone 3 resolved the primary architectural limitations identified in the project proposal:

* **Persistent File Storage (`tasks.txt`):** Implemented `Task::serialize()` and `Task::deserialize()` alongside `TaskManager::saveToFile()` and `TaskManager::loadFromFile()`. Tasks are now written to disk automatically upon creation, completion, deletion, or exit, and reloaded seamlessly when the application starts.
* **Task Deletion (`deleteTask`):** Added menu option `4. Delete a Task` in `MenuController` and `TaskManager::deleteTask(int index)`, enabling users to remove unwanted or obsolete tasks from the active vector.
* **Live Completion Summary & Priority Labels:** Enhanced `TaskManager::displayAllTasks()` to display a real-time progress header (`Completed/Total`) and human-readable priority labels (`Low`, `Medium`, `High`) instead of raw integers.

## 2. Code Refactoring & Quality Improvements
To improve maintainability, readability, and object-oriented design, several structural refactors were applied across the codebase:

* **Eliminated Duplicated Input Logic:** Extracted `MenuController::getValidIntegerInput()` and `MenuController::promptForTaskIndex()` to centralize stream error handling (`std::cin.clear()` / `std::cin.ignore()`) and index validation across both the Complete and Delete workflows.
* **Enforced `const`-Correctness:** Marked all read-only getters, display routines, validation helpers, and serialization methods as `const` across `Task`, `TaskManager`, and `MenuController`.
* **Header Standardization & Bug Fixes:** Standardized `Task.h` naming and resolved the menu prompt numbering bug (`"5. Select an Option:"` corrected to `"Select an Option:"`).
* **Dependency Injection:** Updated `MenuController` to accept a `TaskManager&` reference via constructor injection in `main.cpp`, decoupling storage initialization from the console UI layer.

## 3. Challenges & Solutions
* **File Serialization Delimiters:** Designing a clean plain-text format in `Task::serialize()` required separating boolean status, priority integer, title, and description reliably. Using a pipe (`|`) delimiter with `std::stringstream` and `std::getline` allowed multi-word titles and descriptions with spaces to be parsed accurately.
* **Git Branch Synchronization & Binary Tracking:** Ensured compiled `.exe`, `.obj`, and runtime `tasks.txt` files were excluded via `.gitignore` so only clean source code and documentation are tracked in version control.

## 4. Next Steps (Milestone 4)
* Add filtering and sorting options (view by priority level or incomplete tasks only).
* Implement task editing (`editTask`) to update an existing task's title, description, or priority without deleting and recreating it.
* Expand automated edge-case testing for malformed storage files.