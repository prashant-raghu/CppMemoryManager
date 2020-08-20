#include <bits/stdc++.h>
using namespace std;

#define BASE_SIZE 1000
#define NO_OF_TIMES 500000

template <class T, size_t countT>
class MemoryManager
{
private:
    char *ref;

    const size_t typeSize;
    const size_t count;
    size_t noOfObj;

public:
    MemoryManager() : count(countT), noOfObj(0), typeSize(sizeof(T))
    {
        ref = new char[count * typeSize];
    }

    void free()
    {
        if (ref)
            delete[] ref;
    }

    T *nxtAddress()
    {
        if (ref)
        {
            if (noOfObj == count)
            {
                noOfObj = 0;
            }
            T *p = reinterpret_cast<T *>(ref + (typeSize * noOfObj));
            ++noOfObj;
            return p;
        }
        else
            return nullptr;
    }

    void freeAddress(T *objPtr)
    {
        objPtr->~T();
    }

    ~MemoryManager()
    {
        free();
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

    MemoryManager<MyPracticalClass, BASE_SIZE> memMan;

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
