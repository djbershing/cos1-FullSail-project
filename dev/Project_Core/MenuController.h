#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include "TaskManager.h"

class MenuController
{
private:
	TaskManager manager;
	bool running;

	//helper functions
	void displayMenu() const;
	int getValidIntergerInput() const;
	void handleAddTask();
	void handleCompleteTask();

public:
	MenuController();
	void run();

};

#endif