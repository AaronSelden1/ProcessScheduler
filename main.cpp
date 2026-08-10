#include "Process.h"
#include "Scheduler.h"
#include "Checker.h"
#include <iostream>



int main()
{
	Scheduler scheduler;
	Checker checker;

	int numProcesses;
    std::cout << "Welcome to Process Scheduler \n" << std::endl;
	std::cout << "How many processes do you want to create? ";
	std::cin >> numProcesses;
	for (int i = 0; i < numProcesses; i++)
	{
		int pid, priority;
		while (true)
		{
			std::cout << "Please enter PID , Then Priority 1 - 5: " << std::endl;
			std::cin >> pid >> priority;
			if (!checker.validPriority(priority))
			{
				std::cout << "Invalid priority. Please enter a value between 1 and 5." << std::endl;
				continue;
			}
			break;
		}

		if (!scheduler.addProcess(pid, priority))
		{
			std::cout << "PID already exists. Please enter a unique PID." << std::endl;
			i--; // Decrement i to repeat this iteration
			continue;
		}
	}
	scheduler.displayReadyQueue();
	scheduler.runAllProcesses();
	return 0;
}
