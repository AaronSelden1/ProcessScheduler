#pragma once
#include <string>

enum class ProcessState { Ready, Running, Waiting, Terminated, Finished };

class Process
{
private:
    int pid;
    int priority;
	int arrivalOrder;

    ProcessState state;

public:

    Process(int pid, int priority, int arrivalOrder);

    int getPid() const;
    int getPriority() const;
    int getArrivalOrder() const;

    ProcessState getState() const;

    std::string getStateString() const;

    void setState(ProcessState newState);
};