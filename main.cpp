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
	std::cout << "Select an option for process running, 1. priority Queue, 2. FIFO, 3. Round Robin  4. Exit: " << std::endl;
	int option;
	std::cin >> option;
	switch (option)
	{
	case 1:
		std::cout << "Running Prioity Queue Scheduling..." << std::endl;
		scheduler.runAllProcesses();
		break;
	case 2:
		std::cout << "Running FIFO Scheduling..." << std::endl;
		scheduler.runFifoProcesses();
		break;
	case 3:
		std::cout << "Round Robin Scheduling is not implemented yet." << std::endl;
		break;
	case 4:
		std::cout << "Exiting..." << std::endl;
		break;
	}
	return 0;
}
