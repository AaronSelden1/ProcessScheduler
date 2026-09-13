#include "Process.h"

Process::Process(int pid, int priority, int arrivalOrder, int burstTime)
    : pid(pid), priority(priority), arrivalOrder(arrivalOrder), burstTime(burstTime), state(ProcessState::Ready)
{
}

int Process::getPid() const
{
    return pid;
}

int Process::getBurstTime() const
{
    return burstTime;
}

void Process::subtractBurstTime()
{
    this->burstTime = burstTime - 3;
}

int Process::getPriority() const
{
    return priority;
}

int Process::getArrivalOrder() const
{
    return arrivalOrder;
}

ProcessState Process::getState() const
{
    return state;
}

void Process::setState(ProcessState newState)
{
    state = newState;
}

std::string Process::getStateString() const
{
    switch (state)
    {
    case ProcessState::Ready:
        return "Ready";

    case ProcessState::Running:
        return "Running";

    case ProcessState::Waiting:
        return "Waiting";

    case ProcessState::Terminated:
        return "Terminated";

    case ProcessState::Finished:
        return "Finished";
    }

    return "Unknown";
}