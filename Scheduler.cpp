#include "Scheduler.h"
#include <iostream>
#include "Process.h"


 bool Scheduler::addProcess(int pid, int priority)
{
	 if (pidExists(pid))
	 {
		 return false; // PID already exists, cannot add process
	 }
	 auto process = std::make_unique<Process>(pid, priority, nextArrival++);
	 
	 Process* processPter = process.get(); // Get the raw pointer to the process

	 processes.push_back(std::move(process)); 
	 readyQueue.push(processPter); // Add the process to the ready queue)
	 return true; // Process added successfully
}

void Scheduler::displayProcesses() const
{
	for (const auto& process : processes)
	{
		std::cout << "PID: " << process -> getPid() << ", Priority: " << process->getPriority() << ", State: " << process->getStateString() <<  ", Arrival Order: " << process->getArrivalOrder() << std::endl;
	}
}
bool Scheduler::pidExists(int pid) const
{
	for(const auto& p : processes)
	{
		if (p -> getPid() == pid)
		{
			return true;
		}
	}
	return false;
}

void Scheduler::displayReadyQueue()
{
	auto queueCopy = readyQueue; // Create a copy of the ready queue to display its contents without modifying the original queue
	while (!queueCopy.empty())
	{
		Process* process = queueCopy.top();

		std::cout << "PID: " << process->getPid() << ", Priority: " << process->getPriority() << ", State: " << process->getStateString() << ", Arrival Order: " << process->getArrivalOrder() << std::endl;

		queueCopy.pop();
	}
}
void Scheduler::runNextProcess()

{
	if (!readyQueue.empty() && readyQueue.top()->getState() == ProcessState::Ready)

	{

		Process* process = readyQueue.top();



		process->setState(ProcessState::Waiting);

		std::cout << "Running process PID: " << process->getPid() << std::endl;

		process->setState(ProcessState::Running);



		process->setState(ProcessState::Finished);

		

		if (process->getState() == ProcessState::Finished)

		{

			std::cout << "Process PID: " << process->getPid() << " has finished execution." << std::endl;

			displayReadyQueue();

			readyQueue.pop(); // Remove the process from the ready queue

		}

		else

		{

			std::cout << "Process PID: " << process->getPid() << " Has encountered an error. Terminating..." << std::endl;

			process->setState(ProcessState::Terminated);

			return;

		}

	}
	else

	{

		std::cout << "No ready processes to run." << std::endl;

	}
}

void Scheduler::runAllProcesses()
{
	while (!readyQueue.empty()) 
	{
		runNextProcess();
	}
	std::cout << "All processes have been executed." << std::endl;
}