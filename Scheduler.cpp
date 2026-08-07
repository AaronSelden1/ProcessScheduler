#include "Scheduler.h"
#include <iostream>

 bool Scheduler::addProcess(const Process& process)
{
	 if (pidExists(process.getPid()))
	 {
		 return false; // PID already exists, cannot add process
	 }
	processes.push_back(process);
	return true; // Process added successfully
}
void Scheduler::displayProcesses() const
{
	for (const auto& process : processes)
	{
		std::cout << "PID: " << process.getPid() << ", Priority: " << process.getPriority() << ", State: " << process.getStateString() << std::endl;
	}
}
bool Scheduler::pidExists(int pid) const
{
	for(const auto& p : processes)
	{
		if (p.getPid() == pid)
		{
			return true;
		}
	}
	return false;
}