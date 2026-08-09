#include "ProcessComparator.h"

bool ProcessComparator::operator()(const Process* a, const Process* b) const
{
	if (a->getPriority() != b->getPriority())
	{
		return a->getPriority() < b->getPriority(); // Higher priority value means higher priority
	}
	else
	{
		return a->getArrivalOrder() > b->getArrivalOrder(); // If priorities are equal, compare arrival order
	}
}