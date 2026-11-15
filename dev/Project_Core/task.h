#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
private:
	std::string title;
	std::string description;
	int priority;
	bool isCompleted;

public:
	Task(std::string t, std::string d, int p);

	//getters
	std::string getTitle() const;
	std::string getDescription() const;
	int getPriority() const;
	bool getIsCompleted() const;

	//setters
	void markComplete();
	std::string getPriorityString() const;
};

#endif