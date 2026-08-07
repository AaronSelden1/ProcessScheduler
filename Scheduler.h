#pragma once

#include <vector>
#include "Process.h"

class Scheduler
{
private:
	std::vector<Process> processes;

public:
	void addProcess(Process process);
};