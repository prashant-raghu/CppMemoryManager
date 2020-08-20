## Memory Manager (v1.0.0)
### Files
* MemoryManager.cpp
### Pros
* memory safe
* 6x times faster than traditional new/delete
* can be optimized to be near generic

### Cons
* const non-pointer/non-reference class members are not allowed
* initializes a large sized array for memmory allocation
