#pragma once
#include "Process.h"

struct ProcessComparator
{
	bool operator()(const Process& a, const Process& b) const;
};