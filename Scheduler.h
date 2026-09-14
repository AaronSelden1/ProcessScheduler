#pragma once

#include <vector>
#include <queue>
#include <memory>
#include <deque>
#include "Process.h"
#include "ProcessComparator.h"


class Scheduler
{
private:
	std::vector<std::unique_ptr<Process>> processes; // Store processes as unique pointers to manage memory automatically
	std::priority_queue<Process*, std::vector<Process*>, ProcessComparator> readyQueue; // Priority queue for ready processes
	std::queue<Process* > fifoQueue; // FIFO queue for processes
	std::deque<Process*> roundRobinQueue; // Round Robin priority queue for processes
	int generateBurstTime(); // Function to generate a random burst time for a process
	int nextArrival = 0; // To keep track of the arrival order of processes

public:
	bool addProcess(int pid, int priority);

	void displayProcesses() const;

	void displayReadyQueue();

	bool pidExists(int pid) const;

	void runNextProcess();

	void runAllProcesses();
	
	void runFifoProcesses(); 

	void displayFifoQueue();

	void runFIFORoundRobin();

	void runPriorityRoundRobin();

	void displayRoundRobin();

	void populatePriorityRoundRobin();

	void populateFIFORoundRobin();
};	