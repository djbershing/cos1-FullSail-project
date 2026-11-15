#include "MenuController.h"
#include <iostream>
#include <limits>

MenuController::MenuController() : running(true) {}

void MenuController::displayMenu() const
{
	std::cout << "\n---TERMINAL TASK MANAGER ---\n"
		<< "1. View Tasks\n"
		<< "2. Add Task\n"
		<< "3. Complete a Task\n"
		<< "4. Exit\n"
		<< "5. Select an Option: ";
}

int MenuController::getValidIntegerInput() const
{
	int choice;
	while (!(std::cin >> choice))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid number: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return choice;
}

void MenuController::handleAddTask()
{
	std::string title, desc;
	int priority;

	std::cout << "Enter task title: ";
	std::getline(std::cin, title);

	std::cout << "Enter task description: ";
	std::getline(std::cin, desc);

	do
	{
		std::cout << "Enter priority (1 = Low, 2 = Medium, 3 = High): ";
		priority = getValidIntegerInput();
	} while (priority < 1 || priority > 3);

	manager.addTask(Task(title, desc, priority));
	std::cout << "\nTask added successfully!\n";
}

void MenuController::handleCompleteTask()
{
	manager.displayAllTasks();
	if (manager.getTaskCount() == 0) return;

	std::cout << "Enter the number of the task to complete: ";
	int choice = getValidIntegerInput();

	manager.completeTask(choice - 1);
}

void MenuController::run()
{
	while (running)
	{
		displayMenu();
		int choice = getValidIntegerInput();

		switch (choice)
		{
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
			std::cout << "\nGoodbye!\n";
			running = false;
			break;
		default:
			std::cout << "\nInvalid choice, please choose option 1-4.\n";
		}
	}
}