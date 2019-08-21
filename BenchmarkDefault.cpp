#include <bits/stdc++.h>
#include "BenchmarkDefault.h"

int main() 
  {
  DClass2 * arra[1000];
  //performing 1000 allocation and deletion * 5000 times
  for (int i = 0;i  <  5000; i++) {
    for (int j = 0; j  <  1000; j++) {
      arra[j] = new DClass2 (i, j);}
    for (int j = 0; j  <  1000; j++) {
      delete arra[j];
      }
    }
    //Took 3.024 Seconds to finish execution
  return 0;
  }