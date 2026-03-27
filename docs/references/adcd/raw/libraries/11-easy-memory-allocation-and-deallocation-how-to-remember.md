# 11 / Easy Memory Allocation and Deallocation / How to Remember


To use Intuition's memory functions, first create an anchor for the memory
to be allocated by declaring a variable that is a pointer to a [Remember](../Libraries_Manual_guide/node01FA.html)
structure and initializing that pointer to NULL.  This variable is called
the remember key.


```c
    struct Remember *rememberKey = NULL;
```
Call [AllocRemember()](../Libraries_Manual_guide/node01F8.html) with the address of the remember key, along with the
memory requirements for the specific allocation.  Multiple allocations may
be made before a call to [FreeRemember()](../Libraries_Manual_guide/node01F8.html#line29).


```c
    memBlockA = AllocRemember(&rememberKey, SIZE_A,
                              MEMF_CLEAR | MEMF_PUBLIC);
    if (memBlockA == NULL)
        {
        /* error: allocation failed */
        printf("Memory allocation failed.\n");
        }
    else
        {
        /* use the memory here */
        printf("Memory allocation succeeded.\n");
        }
```
[AllocRemember()](../Libraries_Manual_guide/node01F8.html) actually performs two memory allocations per call, one for
the memory requested and the other for a [Remember](../Libraries_Manual_guide/node01FA.html) structure.  The Remember
structure is filled in with data describing the allocation, and is linked
into the list to which the remember key points.

To free memory that has been allocated, simply call [FreeRemember()](../Libraries_Manual_guide/node01F8.html#line29) with
the correct remember key.


```c
    void FreeRemember(&rememberKey, TRUE);
```
This will free all the memory blocks previously allocated with
[AllocRemember()](../Libraries_Manual_guide/node01F8.html) in a single call.

