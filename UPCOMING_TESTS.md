These are the programs that can be tested to improve more about reasoning and improvements in current design of SSDAM:

* SSDAM (Linked list based) optimized for auto dynamic pool initialization and destruction + random object deletion. Use of assignment operator.
* any random type initialization in SSDAM rather than single known type. 
* Seems like SSDAM+ is faster than SSDAM when only one pool is created. Try caching the single pool of memory in SSDAM. In SSDAM+ similar behaviour might be occuring showing good speeds.
* https://www.youtube.com/watch?v=YQs6IC-vgmo&t=25s. Shows a lot of difference, Vector is 50 times faster than List. WTF??.