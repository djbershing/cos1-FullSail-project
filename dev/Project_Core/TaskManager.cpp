#include "TaskManager.h"
#include <iostream>
#include <fstream>

TaskManager::TaskManager(const std::string& filename) : storageFile(filename) {
	loadFromFile();
}

bool TaskManager::isValidIndex(int index) const {
	return index >= 0 && index < static_cast<int>(tasks.size());
}

void TaskManager::addTask(const Task& task) {
	tasks.push_back(task);
	saveToFile();
}

bool TaskManager::completeTask(int index) {
	if (!isValidIndex(index)) {
		return false;
	}
	tasks[index].markComplete();
	saveToFile();
	return true;
}

bool TaskManager::deleteTask(int index) {
	if (!isValidIndex(index)) {
		return false;
	}
	tasks.erase(tasks.begin() + index);
	saveToFile();
	return true;
}

void TaskManager::displayAllTasks() const {
	if (tasks.empty()) {
		std::cout << "\nNo tasks currently stored.\n";
		return;
	}

	std::cout << "\n--- Current Tasks (" << getCompletedCount() << "/" << getTaskCount() << " Completed) ---\n";
	for (size_t i = 0; i < tasks.size(); ++i) {
		std::cout << (i + 1) << ". [" << (tasks[i].isCompleted() ? "X" : " ") << "] "
			<< tasks[i].getTitle() << " (" << tasks[i].getPriorityLabel() << ")\n"
			<< " Description: " << tasks[i].getDescription() << "\n";
	}
}

int TaskManager::getTaskCount() const {
	return static_cast<int>(tasks.size());
}

int TaskManager::getCompletedCount() const {
	int count = 0;
	for (const auto& task : tasks) {
		if (task.isCompleted()) {
			++count;
		}
	}
	return count;
}

bool TaskManager::saveToFile() const {
	std::ofstream outFile(storageFile);
	if (!outFile.is_open()) {
		return false;
	}
	for (const auto& task : tasks) {
		outFile << task.serialize() << "\n";
	}
	return true;
}

bool TaskManager::loadFromFile() {
	std::ifstream inFile(storageFile);
	if (!inFile.is_open()) {
		return false;
	}
	tasks.clear();
	std::string line;
	while (std::getline(inFile, line)) {
		if (!line.empty()) {
			tasks.push_back(Task::deserialize(line));
		}
	}
	return true;
}