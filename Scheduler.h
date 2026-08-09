#pragma once

#include <vector>
#include <queue>
#include <memory>

#include "Process.h"
#include "ProcessComparator.h"


class Scheduler
{
private:
	std::vector<std::unique_ptr<Process>> processes; // Store processes as unique pointers to manage memory automatically
	std::priority_queue<Process*, std::vector<Process*>, ProcessComparator> readyQueue; // Priority queue for ready processes
	
	int nextArrival = 0; // To keep track of the arrival order of processes

public:
	bool addProcess(int pid, int priority);

	void displayProcesses() const;

	void displayReadyQueue();

	bool pidExists(int pid) const;

	void runNextProcess();

	void runAllProcesses();

};

	