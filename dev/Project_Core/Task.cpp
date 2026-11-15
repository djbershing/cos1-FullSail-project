#include "Task.h"
#include <sstream>

Task::Task(const std::string& title, const std::string& description, int priority, bool completed)
	: title(title), description(description), priority(priority), completed(completed) {
}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }

std::string Task::getPriorityLabel() const {
	switch (priority) {
	case 1: return "Low";
	case 2: return "Medium";
	case 3: return "High";
	default: return "Unknown";
	}
}

bool Task::isCompleted() const { return completed; }

void Task::markComplete() { completed = true; }
void Task::setTitle(const std::string& newTitle) { title = newTitle; }
void Task::setDescription(const std::string& newDescription) { description = newDescription; }
void Task::setPriority(int newPriority) { priority = newPriority; }

std::string Task::serialize() const {
	return std::to_string(completed ? 1 : 0) + "|" + std::to_string(priority) + "|" + title + "|" + description;
}

Task Task::deserialize(const std::string& line) {
	std::stringstream ss(line);
	std::string completedStr, priorityStr, title, description;

	std::getline(ss, completedStr, '|');
	std::getline(ss, priorityStr, '|');
	std::getline(ss, title, '|');
	std::getline(ss, description);

	bool isDone = (completedStr == "1");
	int prio = priorityStr.empty() ? 1 : std::stoi(priorityStr);
	return Task(title, description, prio, isDone);
}