#include "Checker.h"

bool Checker::validPriority(int priority)
{
	if (priority < 1 || priority > 5)
	{
		std::cout << "Invalid priority. Please enter a value between 1 and 5." << std::endl;
		return false;
	}
	return (priority >= 1 && priority <= 5);
}