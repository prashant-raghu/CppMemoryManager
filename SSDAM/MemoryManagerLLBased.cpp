#include <bits/stdc++.h>
using namespace std;

#define BASE_SIZE 1000
#define NO_OF_TIMES 500000

template <class T, size_t poolObjCountT, size_t countT>
class MemoryManager
{

    struct PoolLink
    {
        void *ref;
        PoolLink *next;
    };

private:
    PoolLink *sRef, *eRef, *cRef;

    T *startRef, *nxtRef, *endRef;

    const size_t poolLinkSize;
    const size_t typeSize;
    const size_t poolObjCount;
    size_t noOfObj;

public:
    MemoryManager() : poolObjCount(poolObjCountT), noOfObj(0), typeSize(sizeof(T)), poolLinkSize(sizeof(PoolLink))
    {
        if (!(poolObjCountT && countT))
        {
            throw "pool-size and count cannot be zero.";
        }
        try
        {
            sRef = eRef = cRef = reinterpret_cast<PoolLink *>(malloc(poolObjCount * typeSize + poolLinkSize));
            sRef->ref = reinterpret_cast<void *>(sRef + 1);
            sRef->next = nullptr;

            startRef = reinterpret_cast<T *>(sRef->ref);
            nxtRef = startRef - 1;
            endRef = startRef + poolObjCount;

            PoolLink *p;
            int count = countT / poolObjCount;
            while (--count)
            {
                p = reinterpret_cast<PoolLink *>(malloc(poolObjCount * typeSize + poolLinkSize));
                p->ref = reinterpret_cast<void *>(p + 1);
                p->next = nullptr;

                eRef->next = p;
                eRef = p;
            }
        }
        catch (...)
        {
            cout << "Array Memory cannot be initialized.";
            throw; //Re-throwing
        }
    }

    void cleanUp()
    {
        PoolLink *tmpLink = sRef;
        while (tmpLink)
        {
            sRef = sRef->next;
            free(tmpLink);
            tmpLink = sRef;
        }
    }

    T *nxtAddress()
    {
        ++nxtRef;
        if (nxtRef == endRef)
        {
            cRef = cRef->next;
            if (!cRef)
            {
                cRef = sRef;
            }
            startRef = reinterpret_cast<T *>(cRef->ref);
            nxtRef = startRef;
            endRef = startRef + poolObjCount;
        }
        return nxtRef;
    }

    void freeAddress(T *objPtr)
    {
        if (objPtr)
        {
            objPtr->~T();
            // objPtr = nullptr;
        }
    }

    ~MemoryManager()
    {
        cleanUp();
    }
};

class MyPracticalClass
{
public:
    int a, b;
    void inialize(int a, int b)
    {
        MyPracticalClass::a = a;
        MyPracticalClass::b = b;
    }
};

int main()
{
    time_t start, end;
    time(&start);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    MemoryManager<MyPracticalClass, BASE_SIZE, BASE_SIZE> memMan;

    MyPracticalClass *arra[BASE_SIZE];

    //performing 1000 allocation and deletion * 500000 times
    // 1 Billion operations
    for (int i = 0; i < NO_OF_TIMES; i++)
    {
        for (int j = 0; j < BASE_SIZE; j++)
        {

            arra[j] = memMan.nxtAddress();
            arra[j]->inialize(i, j);
        }
        for (int j = 0; j < BASE_SIZE; j++)
        {
            memMan.freeAddress(arra[j]);
        }
    }
    // Recording end time.
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
