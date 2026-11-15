#include "TaskManager.h"
#include "MenuController.h"

int main() {
	TaskManager manager("tasks.txt");
	MenuController menu(manager);
	menu.run();
	return 0;
}