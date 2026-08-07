#include "Process.h"
#include <iostream>


int main()
{
	int pid, priority;
    std::cout << "Welcome to Process Scheduler \n" << std::endl;
	std::cout << "Please enter PID , Then Priority: " << std::endl;
	
	std::cin >> pid >> priority;
	Process p1(pid, priority);
	std::cout << "Process created with PID: " << p1.getPid() << " and Priority: " << p1.getPriority() << std::endl;
	if (p1.getState() == ProcessState::Ready)
	{
		std::cout << "Process is in Ready state." << std::endl;
	}
	else
	{
		std::cout << "Process is not in Ready state." << std::endl;
	}
	return 0;
}
