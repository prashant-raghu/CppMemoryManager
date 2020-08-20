#include <bits/stdc++.h>
class DClass 
  {
  public:
  double member1;
  double member2;
  DClass (double a, double b): member1 (a), member2 (b) {}

  void * operator new(size_t size);
  void operator delete(void * pointerToDelete);

};