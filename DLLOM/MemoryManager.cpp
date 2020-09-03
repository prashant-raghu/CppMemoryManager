#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define BASE_SIZE 1000
#define NO_OF_TIMES 500000

template <class T>
class MemoryManager
{
    struct Link
    {
        Link *prev;
        Link *next;
    };

private:
    Link *sRef, *eRef;
    Link *freeLink;

    Link *tmpLink, *tmpLink2, *tmpLink3;

    const size_t typeSize;
    const size_t linkSize;
    const size_t typePlusLinkSize;


    void freeCells()
    {
        tmpLink = sRef;
        while (tmpLink)
        {
            sRef = sRef->next;
            free(tmpLink);
            tmpLink = sRef;
        }
    }

public:
    MemoryManager() : typeSize(sizeof(T)), linkSize(sizeof(Link)), typePlusLinkSize(typeSize + linkSize)
    {
        try
        {
            sRef = reinterpret_cast<Link *>(malloc(typePlusLinkSize));
            sRef->prev = sRef->next = nullptr;
            freeLink = eRef = sRef;
        }
        catch (...)
        {
            cout << "Memory cannot be initialized.";
            throw; //Re-throwing
        }

        // for(int i=0;i<999;++i) {
        //     tmpLink = reinterpret_cast<Link *>(malloc(typePlusLinkSize));
            
        //     tmpLink->prev = eRef;
        //     tmpLink->next = nullptr;

        //     eRef->next = tmpLink;
        //     eRef = tmpLink;
        // }
    }

    T *nxtAddress()
    {
        if (freeLink)
        {
            tmpLink = freeLink;
            freeLink = freeLink->next;
            return reinterpret_cast<T *>(tmpLink + 1);
        }
        else
        {
            tmpLink = reinterpret_cast<Link *>(malloc(typePlusLinkSize));
            tmpLink->prev = eRef;
            tmpLink->next = nullptr;
            eRef->next = tmpLink;
            eRef = tmpLink;

            return reinterpret_cast<T *>(tmpLink + 1);
        }
    }

    void freeAddress(T *objPtr)
    {
        if (objPtr)
        {
            objPtr->~T();
            tmpLink2 = reinterpret_cast<Link *>(objPtr) - 1;

            tmpLink = tmpLink2->prev;
            tmpLink3 = tmpLink2->next;

            if (tmpLink && tmpLink3)
            {
                tmpLink->next = tmpLink3;
                tmpLink3->prev = tmpLink;

                eRef->next = tmpLink2;
                tmpLink2->prev = eRef;
                eRef = tmpLink2;
            }
            else if (tmpLink3)
            {
                sRef = tmpLink3;
                tmpLink3->prev = nullptr;

                eRef->next = tmpLink2;
                tmpLink2->prev = eRef;
                eRef = tmpLink2;
            }

            tmpLink2->next = nullptr;
            if (!freeLink)
            {
                freeLink = tmpLink2;
            }
        }
    }

    ~MemoryManager()
    {
        freeCells();
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
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    auto start = chrono::high_resolution_clock::now();
    
    MemoryManager<MyPracticalClass> memMan;

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
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl;
    return 0;
}
