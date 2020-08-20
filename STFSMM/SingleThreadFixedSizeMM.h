#include <bits/stdc++.h>
#include "./DiscreteClass.h"
#define POOLSIZE 32

class IMemoryManager {
  public:
    virtual void * allocate(size_t) = 0;
    virtual void   free(void *) = 0;
};

class MemoryManager: public IMemoryManager {
  struct FreeStore
    {
     FreeStore * next;
    };
  void expandPoolSize ();
  void cleanUp ();
  FreeStore * freeStoreHead;
  public:
    MemoryManager () {
      freeStoreHead = 0;
      expandPoolSize ();
      }
    virtual ~MemoryManager () {
      cleanUp ();
      }
    virtual void * allocate(size_t);
    virtual void   free(void *);
  };
inline void * MemoryManager::allocate(size_t size)
  {
  if (0 == freeStoreHead)
    expandPoolSize ();
  FreeStore * head = freeStoreHead;
  freeStoreHead = head -> next;
  return head;
  }
void MemoryManager::expandPoolSize ()
  {
  size_t size = (sizeof(DClass) > sizeof(FreeStore *)) ? sizeof(DClass) : sizeof(FreeStore *);
  FreeStore * head = reinterpret_cast <FreeStore *> (new char[size]);
  freeStoreHead = head;
//expanding the new pool to pool size
  for (int i = 0; i < POOLSIZE; i++) {
    head -> next = reinterpret_cast <FreeStore *> (new char [size]);
    head = head -> next;
    }
  head -> next = 0;
  }

void MemoryManager::cleanUp()
  {
  FreeStore * nextPtr = freeStoreHead;
  for (; nextPtr; nextPtr = freeStoreHead) {
    freeStoreHead = freeStoreHead -> next;
    delete [] nextPtr; // remember this was a char array
    }
  }

inline void MemoryManager::free(void * deleted)
  {
  FreeStore * head = static_cast <FreeStore *> (deleted);
  head -> next = freeStoreHead;
  freeStoreHead = head;
  }
MemoryManager gMemoryManager;

void * DClass::operator new (size_t size) 
  {
  return gMemoryManager.allocate(size);
  }

void DClass::operator delete (void * pointerToDelete)
  {
  gMemoryManager.free(pointerToDelete);
  }
