#pragma once

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

    void setState(ProcessState newState);
};