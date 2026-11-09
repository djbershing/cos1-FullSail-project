#include "task.h"

Task::Task(std::string t, std::string d, int p) : title(t), description(d), priority(p), isCompleted(false) {}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
int Task::getPriority() const { return priority; }
bool Task::getIsCompleted() const { return isCompleted; }

void Task::markComplete() { isCompleted = true; }

std::string Task::getPriorityString() const
{
	if (priority == 1) return "Low";
	if (priority == 2) return "Medium";
	return "High";
}