#include <bits/stdc++.h>
#include "SingleThreadFixedSizeMM.h"

int main() 
  {
  DClass * arra[1000];
  //performing 1000 allocation and deletion * 5000 times
  for (int i = 0;i  <  5000; i++) {
    for (int j = 0; j  <  1000; j++) {
      arra[j] = new DClass (i, j);
      }
    for (int j = 0; j  <  1000; j++) {
      delete arra[j];
      }
    }
    //Took 1.906 Seconds to finish execution
    //40% Decrease in Execution Time
  return 0;
  }