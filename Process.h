#pragma once
#include <string>

enum class ProcessState { Ready, Running, Waiting, Terminated, Finished };

class Process
{
private:
    int pid;
    int priority;

    ProcessState state;

public:

    Process(int pid, int priority);

    int getPid() const;
    int getPriority() const;

    ProcessState getState() const;

    std::string getStateString() const;

    void setState(ProcessState newState);
};