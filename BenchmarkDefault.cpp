#include <bits/stdc++.h>
#include "BenchmarkDefault.h"
using namespace std;
int main() 
  {
  time_t start, end;
  time(&start);
  // unsync the I/O of C and C++.
  ios_base::sync_with_stdio(false);
  DClass2 * arra[1000];
  //performing 1000 allocation and deletion * 5000 times
  // 1 Billion operation
  for (int i = 0;i  <  500000; i++) {
    for (int j = 0; j  <  1000; j++) {
      arra[j] = new DClass2 (i, j);}
    for (int j = 0; j  <  1000; j++) {
      delete arra[j];
      }
    }

  // Recording end time.
  time(&end);
  // Calculating total time taken by the program.
  double time_taken = double(end - start);
  cout << "Time taken by Default allocaters/deallocaters is : " << fixed
       << time_taken << setprecision(5);
  cout << " sec " << endl;
    //Took 22 Seconds to finish execution
  return 0;
  }