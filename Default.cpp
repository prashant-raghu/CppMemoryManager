#include <bits/stdc++.h>
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
    time_t start, end;
    time(&start);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

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
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by Overloaded allocaters/deallocaters is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
