#include "Process.h"
#include <iostream>


int main()
{
	
	int numProcesses;

    std::cout << "Welcome to Process Scheduler \n" << std::endl;
	std::cout << "How many processes do you want to create? ";
	std::cin >> numProcesses;
	for (int i = 0; i < numProcesses; i++)
	{
		int pid, priority;
		std::cout << "Please enter PID , Then Priority 1 - 5: " << std::endl;

		std::cin >> pid >> priority;
		Process process(pid, priority);
		std::cout << "Process created with PID: " << process.getPid() << " and Priority: " << process.getPriority() << std::endl;
		if (process.getState() == ProcessState::Ready)
		{
			std::cout << "Process is in Ready state." << std::endl;
		}
		else
		{
			std::cout << "Process is not in Ready state. current state: " << process.getStateString() << std::endl;
		}
	}
	return 0;
}
