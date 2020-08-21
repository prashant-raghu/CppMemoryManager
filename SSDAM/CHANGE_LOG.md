## Memory Manager (v1.0.0)
### Files
* MemoryManager.cpp
### Pros
* memory safe
* single threaded
* 6x times faster than traditional new/delete.

### Cons
* specific application
* const non-pointer/non-reference class members are not allowed in our custom class.
* can initialize a large sized array for memory allocation.

  For example if we take our example class and create 67,108,864 objs then it will require an array of size 67,108,864 x 8 bytes (our obj has 2 int, an int is of 4 bytes) = 512 MBs (half of 1GB).

  But we are creating 1000 objs in our example so it requires nearly 8KBs = 0.0078125 MBs
