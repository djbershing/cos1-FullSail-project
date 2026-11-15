#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
	std::string title;
	std::string description;
	int priority; // 1 = Low, 2 = Medium, 3 = High
	bool completed;

public:
	Task(const std::string& title, const std::string& description, int priority, bool completed = false);

	// Getters (const-correct)
	std::string getTitle() const;
	std::string getDescription() const;
	int getPriority() const;
	std::string getPriorityLabel() const;
	bool isCompleted() const;

	// Setters / Modifiers
	void markComplete();
	void setTitle(const std::string& newTitle);
	void setDescription(const std::string& newDescription);
	void setPriority(int newPriority);

	// Serialization helpers for file storage
	std::string serialize() const;
	static Task deserialize(const std::string& line);
};

#endif