# Using single size-determined Array to provide memory for objs of same type.

Please read [CHANGE_LOG.md](./CHANGE_LOG.md) for code changes.

## Memory Manager (v1.0.0)

Also known as SSDAM (Single Size-Determined Array Memory)

If you are given to create say 1000 objs and you must create them and destroy them in a given context 500000 times then tradition new/delete takes a lot of time as shown in by this code:

```
  for (int i = 0; i < 500000; i++)
  { 
    /* context */

    for (int j = 0; j < 1000; j++)
    {
      arra[j] = new DClass2(i, j);
    }
    for (int j = 0; j < 1000; j++)
    {
      delete arra[j];
    }

    /*  */
  }
```

Using a custom memory manager class the program got faster by multipliacation factor of 6 which means that if the program took 30 seconds (using new/delete) then now it takes 5 seconds (memory manager):

```
  for (int i = 0; i < 500000; i++)
  {
      /* context */

      for (int j = 0; j < 1000; j++)
      {    
        arra[j] = memMan.nxtAddress();
        arra[j]->inialize(i, j);
      }
      for (int j = 0; j < 1000; j++)
      {
        memMan.freeAddress(arra[j]);
      }

      /*  */
  }
```
Here our 1000 obj are created/destroyed 500000 times in given context (outer most loop).
\
\
\
\
\
**Note**:

  This program can initialize a large sized array for memory allocation.

  For example if we take our example class and create 67,108,864 objs then it will require an array of size 67,108,864 x 8 bytes (our obj has 2 int, an int is of 4 bytes) = 512 MBs (half of 1GB).

  But we are creating 1000 objs in our example so it requires nearly 8KBs = 0.0078125 MBs