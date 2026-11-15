#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "TaskManager.h"

class MenuController {
private:
	TaskManager& manager;

	void displayMenu() const;
	int getValidIntegerInput() const;
	int promptForTaskIndex(const std::string& actionLabel) const;

	void handleAddTask();
	void handleCompleteTask();
	void handleDeleteTask();

public:
	explicit MenuController(TaskManager& taskManager);
	void run();
};

#endif