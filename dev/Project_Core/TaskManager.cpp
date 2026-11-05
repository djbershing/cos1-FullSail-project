#include "TaskManager.h"
#include <iostream>

void TaskManager::addTask(const Task& t)
{
	task.push_back(t);
}

void TaskManager::displayAllTasks() const
{
	if (tasks.empty())
	{
		std::cout << "\n--- No tasks available! ---\n";
		return;
	}

	std::cout << "\n================== TASK LIST ====================\n";
	for (size_t i = 0; i < tasks.size(); ++i)
	{
		std::cout << i + 1 << ". [" << (tasks[i].getIsCompleted() ? "X" : " ") << "] "
			<< tasks[i].getTitle() << " (" << tasks[i].getPriorityString() << " Priority)\n"
			<< "  Desc: " << tasks[i].getDescription() << "\n---------------------------------------------------\n";
	}
}

void TaskManager::conpleteTask(int index)
{
	if (index >= 0 && index < static_cast<int>(tasks.size()))
	{
		tasks[index].markComplete();
		std::cout << "\nTask marked as complete!\n";
	}
}

int TaskManager::getTaskCount() const
{
	return static_cast<int>(tasks.size());
}

