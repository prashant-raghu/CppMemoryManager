#include <bits/stdc++.h>
#include <chrono>

using namespace std;

#define BENCHMARK(PracticalClass, memMan, BASE_SIZE, NO_OF_TIMES) \
    \
    ios_base::sync_with_stdio(false); \
    \
    auto start = chrono::high_resolution_clock::now(); \
    \
    PracticalClass *arra[BASE_SIZE]; \
    \
    for (int i = 0; i < NO_OF_TIMES; i++) \
    { \
        for (int j = 0; j < BASE_SIZE; j++) \
        { \
            arra[j] = memMan.nxtAddress(); \
            arra[j]->inialize(i, j); \
        } \
        for (int j = 0; j < BASE_SIZE; j++) \
        { \
            memMan.freeAddress(arra[j]); \
        } \
    } \
    \
    auto end = chrono::high_resolution_clock::now(); \
    \
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl; 
