markdown
# Project Title
TaskFlow: Terminal-Based Task Manager

# Project Idea
TaskFlow is a command-line productivity application that allows users to organize their daily schedule by adding, viewing, categorizing, and completing tasks. Running the application presents a persistent interactive main menu allowing the user to seamlessly interact with a structured task list, track completion statuses, and filter assignments by priority levels.

# Core Features
* Task Creation & Sorting: Users can add items with distinct text titles, detailed descriptions, and urgency priority levels.
* Interactive Status Tracking: Toggle tasks cleanly between incomplete and completed states with updated visual indicators.
* Priority Filtering: An interactive menu filter that lets the user display only high, medium, or low priority tasks.

# Class Plan
* Task: Stores unique individual task data points including title, details, priority scale, and completion booleans.
* TaskManager: Manages a collection of Task objects, containing functions to add, delete, edit, or clear tasks.
* MenuController: Drives the primary terminal user interface, captures menu selections, and handles string/integer input validation.

# Current Focus
My primary focus is establishing the core Task data class structure and building the foundational MenuController loop to ensure menu selections process accurately without crashes.
