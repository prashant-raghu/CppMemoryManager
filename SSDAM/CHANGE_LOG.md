## SSDAM (v1.2.0)
* array size can be small as small as single obj size (MemoryManagerLLBased). Performance varies from 8x/8.1x (1 array) to 5.38x (n arrays). 

## SSDAM (v1.1.0)
* 8.2x times faster than traditional new/delete.
* const non-pointer/non-reference class members are allowed (MemoryManagerConsBased.cpp). Speed will be 7.43x not 8.2x.
* const non-pointer/non-reference class members are allowed (MemoryManagerNewDelete.cpp). Speed will be 6.78x not 8.2x.

## SSDAM (v1.0.1)
* 8x times faster than traditional new/delete.

## SSDAM (v1.0.0)
* memory safe
* single threaded
* 6x times faster than traditional new/delete.
* specific application
* const non-pointer/non-reference class members are not allowed in our custom class.
* array size can be large
