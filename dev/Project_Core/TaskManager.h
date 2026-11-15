#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>
#include "Task.h"

class TaskManager {
private:
	std::vector<Task> tasks;
	std::string storageFile;

	bool isValidIndex(int index) const;

public:
	explicit TaskManager(const std::string& filename = "tasks.txt");

	void addTask(const Task& task);
	bool completeTask(int index);
	bool deleteTask(int index);
	void displayAllTasks() const;

	int getTaskCount() const;
	int getCompletedCount() const;

	bool saveToFile() const;
	bool loadFromFile();
};

#endif