#include "Scheduler.h"
#include <iostream>
#include "Process.h"


 bool Scheduler::addProcess(int pid, int priority)
{
	 if (pidExists(pid))
	 {
		 return false; // PID already exists, cannot add process
	 }
	 Process process(pid,priority, nextArrival++);
	 processes.push_back(process); readyQueue.push(process);
	return true; // Process added successfully
}
void Scheduler::displayProcesses() const
{
	for (const auto& process : processes)
	{
		std::cout << "PID: " << process.getPid() << ", Priority: " << process.getPriority() << ", State: " << process.getStateString() <<  ", Arrival Order: " << process.getArrivalOrder() << std::endl;
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

void Scheduler::displayReadyQueue()
{
	while (!readyQueue.empty())
	{
		Process process = readyQueue.top();

		std::cout << "PID: " << process.getPid() << ", Priority: " << process.getPriority() << ", State: " << process.getStateString() << ", Arrival Order: " << process.getArrivalOrder() << std::endl;

		readyQueue.pop();
	}
}