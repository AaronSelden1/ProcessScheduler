#pragma once

#include <vector>
#include "Process.h"

class Scheduler
{
private:
	std::vector<Process> processes;

public:
	bool addProcess(const Process& process);

	void displayProcesses() const;

	bool pidExists(int pid) const;

};

	