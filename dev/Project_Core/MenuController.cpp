#include "MenuController.h"
#include <iostream>
#include <limits>

MenuController::MenuController(TaskManager& taskManager) : manager(taskManager) {}

void MenuController::displayMenu() const {
	std::cout << "\n==============================\n";
	std::cout << " TERMINAL TASK MANAGER \n";
	std::cout << "==============================\n";
	std::cout << "1. View Tasks\n";
	std::cout << "2. Add Task\n";
	std::cout << "3. Complete a Task\n";
	std::cout << "4. Delete a Task\n";
	std::cout << "5. Exit\n";
	std::cout << "Select an Option: ";
}

int MenuController::getValidIntegerInput() const {
	int choice;
	while (!(std::cin >> choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return choice;
}

int MenuController::promptForTaskIndex(const std::string& actionLabel) const {
	manager.displayAllTasks();
	if (manager.getTaskCount() == 0) {
		return -1;
	}
	std::cout << "\nEnter the number of the task to " << actionLabel << " (or 0 to cancel): ";
	int choice = getValidIntegerInput();
	if (choice == 0) {
		std::cout << "Action canceled.\n";
		return -1;
	}
	return choice - 1;
}

void MenuController::handleAddTask() {
	std::string title, desc;
	int priority = 1;

	do {
		std::cout << "Enter task title: ";
		std::getline(std::cin, title);
		if (title.empty()) {
			std::cout << "Title cannot be empty.\n";
		}
	} while (title.empty());

	std::cout << "Enter task description: ";
	std::getline(std::cin, desc);

	do {
		std::cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
		priority = getValidIntegerInput();
		if (priority < 1 || priority > 3) {
			std::cout << "Priority must be 1, 2, or 3.\n";
		}
	} while (priority < 1 || priority > 3);

	manager.addTask(Task(title, desc, priority));
	std::cout << "\nTask added and saved successfully!\n";
}

void MenuController::handleCompleteTask() {
	int index = promptForTaskIndex("complete");
	if (index == -1) return;

	if (manager.completeTask(index)) {
		std::cout << "Task marked as completed!\n";
	}
	else {
		std::cout << "Invalid task number.\n";
	}
}

void MenuController::handleDeleteTask() {
	int index = promptForTaskIndex("delete");
	if (index == -1) return;

	if (manager.deleteTask(index)) {
		std::cout << "Task deleted successfully!\n";
	}
	else {
		std::cout << "Invalid task number.\n";
	}
}

void MenuController::run() {
	bool running = true;
	while (running) {
		displayMenu();
		int choice = getValidIntegerInput();

		switch (choice) {
		case 1:
			manager.displayAllTasks();
			break;
		case 2:
			handleAddTask();
			break;
		case 3:
			handleCompleteTask();
			break;
		case 4:
			handleDeleteTask();
			break;
		case 5:
			manager.saveToFile();
			std::cout << "Tasks saved. Exiting Terminal Task Manager. Goodbye!\n";
			running = false;
			break;
		default:
			std::cout << "Invalid option. Please choose between 1 and 5.\n";
			break;
		}
	}
}
