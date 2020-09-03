#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define BASE_SIZE 1000
#define NO_OF_TIMES 500000


class MyPracticalClass
{
public:
    int a, b;
    MyPracticalClass(int a, int b)
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

    MyPracticalClass *arra[BASE_SIZE];

    //performing 1000 allocation and deletion * 500000 times
    // 1 Billion operations
    for (int i = 0; i < NO_OF_TIMES; i++)
    {
        for (int j = 0; j < BASE_SIZE; j++)
        {
            arra[j] = new MyPracticalClass(i,j);
        }
        for (int j = 0; j < BASE_SIZE; j++)
        {
            delete arra[j];
        }
    }
    // Recording end time.
    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program.
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << endl;
    return 0;
}
