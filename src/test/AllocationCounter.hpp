#ifndef ALLOCATIONCOUNTER_HPP
#define ALLOCATIONCOUNTER_HPP

#include <QMutex>

#if defined ENABLE_MEMORY_TEST

class AllocationCounter
{
    static int counter_;
    static QMutex mutex_;
public:
    AllocationCounter();
    ~AllocationCounter();
    static int getCount();
};

#else

class AllocationCounter
{
};

#endif

#endif // ALLOCATIONCOUNTER_HPP
