#include "Process.h"

Process::Process(int pid, int priority)
    : pid(pid), priority(priority), state(ProcessState::Ready)
{
}

int Process::getPid() const
{
    return pid;
}

int Process::getPriority() const
{
    return priority;
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