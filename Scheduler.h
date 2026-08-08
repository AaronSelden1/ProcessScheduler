#pragma once

#include <vector>
#include <queue>

#include "Process.h"
#include "ProcessComparator.h"


class Scheduler
{
private:
	std::priority_queue<Process, std::vector<Process>, ProcessComparator> readyQueue;
	std::vector<Process> processes;
	
	int nextArrival = 0; // To keep track of the arrival order of processes

public:
	bool addProcess(int pid, int priority);

	void displayProcesses() const;

	void displayReadyQueue();

	bool pidExists(int pid) const;

};

	