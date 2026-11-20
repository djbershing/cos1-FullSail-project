# Docs.

This folder is for miscellaneous documentation. 

It's common for repositories to contain documentation provided by the developers or team working on projects together.   

In this class you may be asked to work on documentation that can be stored in this folder. 

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













