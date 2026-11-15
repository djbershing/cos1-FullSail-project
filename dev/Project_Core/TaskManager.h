#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include "task.h"

class TaskManager
{
private:
	std::vector<Task> tasks;


public:
	void addTask(const Task& t);
	void displayAllTasks() const;
	void completeTask(int index);
	int getTaskCount() const;

};

#endif