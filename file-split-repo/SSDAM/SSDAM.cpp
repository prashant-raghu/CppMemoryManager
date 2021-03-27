#include <bits/stdc++.h>
#include "../MemoryManager.h"

using namespace std;

template <class T>
class SSDAM
{
private:
    T *startRef;
    int index;

    const size_t typeSize;
    const size_t count;

public:
    SSDAM(size_t countT) : count(countT), typeSize(sizeof(T)), index(0)
    {
        if (!countT)
        {
            throw "no of objs that can be allocated cannot be zero.";
        }
        try
        {
            startRef = reinterpret_cast<T *>(malloc(count * typeSize));
        }
        catch (...)
        {
            cout << "Array Memory cannot be initialized.";
            throw; //Re-throwing
        }
    }

    void cleanUp()
    {
        if (startRef)
            free(startRef);
    }

    T *nxtAddress()
    {
        if (index == count)
            index = 0;

        return startRef + index++;
    }

    void freeAddress(T *objPtr)
    {
        if (objPtr)
        {
            objPtr->~T();
            // objPtr = nullptr;
        }
    }
};