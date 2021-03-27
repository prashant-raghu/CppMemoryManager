#pragma once

template <class T>
class MemoryManager {
public:
    virtual T *nxtAddress() = 0;
    virtual void freeAddress(T *objPtr) = 0;
    virtual void cleanUp() {};
    
    ~MemoryManager()
    {
        cleanUp();
    }
};