#include "AllocationCounter.hpp"

int AllocationCounter::counter_ = 0;
QMutex AllocationCounter::mutex_;

AllocationCounter::AllocationCounter()
{
    mutex_.lock();
    ++counter_;
    mutex_.unlock();
}

AllocationCounter::~AllocationCounter()
{
    mutex_.lock();
    --counter_;
    mutex_.unlock();
}

int AllocationCounter::getCount()
{
    return counter_;
}
