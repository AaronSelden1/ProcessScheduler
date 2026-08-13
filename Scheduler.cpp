#include "Scheduler.h"
#include <iostream>
#include <chrono>
#include <thread>

 bool Scheduler::addProcess(int pid, int priority)
{
	 if (pidExists(pid))
	 {
		 return false; // PID already exists, cannot add process
	 }
	 int burstTime = generateBurstTime(); // Generate a random burst time for the process
	 auto process = std::make_unique<Process>(pid, priority, nextArrival++, burstTime);
	 Process* processPtr = process.get(); // Get the raw pointer to the process
	 fifoQueue.push(processPtr);
	 processes.push_back(std::move(process)); 
	 readyQueue.push(processPtr); // Add the process to the ready queue)
	 return true; // Process added successfully
}

void Scheduler::displayProcesses() const
{
	for (const auto& process : processes)
	{
		std::cout << "PID: " << process -> getPid() 
		<< ", Priority: " << process->getPriority() 
		<< ", State: " << process->getStateString() 
		<<  ", Arrival Order: " << process->getArrivalOrder() 
		<< ", Burst Time: " << process->getBurstTime() << std::endl;
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

		std::cout << "PID: " << process->getPid() << ", Priority: " << process->getPriority() << ", State: " << process->getStateString() << ", Arrival Order: " << process->getArrivalOrder() << ", Burst Time: " << process->getBurstTime() << std::endl;

		queueCopy.pop();
	}
}
void Scheduler::runNextProcess()

{
	if (!readyQueue.empty() && readyQueue.top()->getState() == ProcessState::Ready)

	{

		Process* process = readyQueue.top();

		std::cout << "Running process PID: " << process->getPid() << " for " << process->getBurstTime() * 100 << "ms" << std::endl;

		process->setState(ProcessState::Running);

		std::this_thread::sleep_for(std::chrono::milliseconds(process->getBurstTime() * 100)); // Simulate burst time in milliseconds

		process->setState(ProcessState::Finished);

		

		if (process->getState() == ProcessState::Finished)

		{

			std::cout << "Process PID: " << process->getPid() << " has finished execution." << std::endl;

			// displayReadyQueue();

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
int Scheduler::generateBurstTime()
{
	return rand() % 10 + 1; // Generate a random burst time between 1 and 10
}
void Scheduler::runFifoProcesses()
{
	while (!fifoQueue.empty() && fifoQueue.front()->getState() == ProcessState::Ready)
	{
		Process* process = fifoQueue.front();
		
		std::cout << "Running process PID: " << process->getPid() << " for " << process->getBurstTime() * 100 << "ms" << std::endl;
		
		process->setState(ProcessState::Running);

		std::this_thread::sleep_for(std::chrono::milliseconds(process->getBurstTime() * 100));

		process->setState(ProcessState::Finished);

		std::cout << "Process has finished execution." << std::endl;
		
		fifoQueue.pop();
	}
	std::cout << "All processes have been executed, Queue empty." << std::endl;
}

void Scheduler::displayFifoQueue()
{
	auto queueCopy = fifoQueue; // Create a copy of the FIFO queue to display its contents without modifying the original queue
	while (!queueCopy.empty())
	{
		Process* process = queueCopy.front();
		std::cout << "PID: " << process->getPid() << ", Priority: " << process->getPriority() << ", State: " << process->getStateString() << ", Arrival Order: " << process->getArrivalOrder() << ", Burst Time: " << process->getBurstTime() << std::endl;
		queueCopy.pop();
	}
}