#include <bits/stdc++.h>
#include <new>       // Must #include this to use "placement new"
#include <chrono>
using namespace std;

#define BASE_SIZE 1000
#define NO_OF_TIMES 500000

template <class T, size_t countT>
class MemoryManager
{
private:
    void *ref;
    T *startRef, *nxtRef, *endRef;

    const size_t typeSize;
    const size_t count;

public:
    MemoryManager() : count(countT), typeSize(sizeof(T))
    {
        if (!countT)
        {
            throw "no of objs that can be allocated cannot be zero.";
        }
        try
        {
            ref = malloc(count * typeSize);
            startRef = reinterpret_cast<T*>(ref);
            nxtRef = startRef - 1;
            endRef = startRef + count;
        }
        catch (...)
        {
            cout << "Array Memory cannot be initialized.";
            throw; //Re-throwing
        }
    }

    void cleanUp()
    {
        if (ref)
            free(ref);
    }

    T *nxtAddress()
    {
        ++nxtRef;
        if(nxtRef == endRef) {
            nxtRef = startRef;
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
    MyPracticalClass(int a, int b):a(a),b(b) {}
};

int main()
{
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    auto start = chrono::high_resolution_clock::now();

    MemoryManager<MyPracticalClass, BASE_SIZE> memMan;

    MyPracticalClass *arra[BASE_SIZE];

    //performing 1000 allocation and deletion * 500000 times
    // 1 Billion operations
    for (int i = 0; i < NO_OF_TIMES; i++)
    {
        for (int j = 0; j < BASE_SIZE; j++)
        {
            arra[j] = new(memMan.nxtAddress()) MyPracticalClass(i,j);
        }
        for (int j = 0; j < BASE_SIZE; j++)
        {
            memMan.freeAddress(arra[j]);
        }
    }
    // Recording end time.
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl;
    return 0;
}
