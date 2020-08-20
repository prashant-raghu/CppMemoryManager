#include <bits/stdc++.h>
#include "./SingleThreadFixedSizeMM.h"
using namespace std;
int main()
{
  time_t start, end;
  time(&start);
  // unsync the I/O of C and C++.
  ios_base::sync_with_stdio(false);

  DClass *arra[1000];
  //performing 1000 allocation and deletion * 500000 times
  // 1 Billion operation
  for (int i = 0; i < 500000; i++)
  {
    for (int j = 0; j < 1000; j++)
    {
      arra[j] = new DClass(i, j);
    }
    for (int j = 0; j < 1000; j++)
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
  //Fn + F6
  //Took 12 Seconds to finish execution
  //40% Decrease in Execution Time
  return 0;
}