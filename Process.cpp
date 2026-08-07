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