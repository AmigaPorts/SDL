# 18 Exec Libraries / What is a Library?


A library consists of a group of functions somewhere in memory (ROM or
RAM), a vector table, and a [Library](../Includes_and_Autodocs_2._guide/node009C.html#line32) structure which can be followed by an
optional private data area for the library.  The library's base pointer
(as returned by [OpenLibrary()](../Libraries_Manual_guide/node028E.html#line15)) points to the library's Library data
structure:


struct Library
{
```c
    struct  Node lib_Node;
    UBYTE   lib_Flags;
    UBYTE   lib_pad;
    UWORD   lib_NegSize;            /* number of bytes before library */
    UWORD   lib_PosSize;            /* number of bytes after library */
    UWORD   lib_Version;
    UWORD   lib_Revision;
    APTR    lib_IdString;
    ULONG   lib_Sum;                /* the checksum itself */
    UWORD   lib_OpenCnt;            /* number of current opens */
```
};
/* Meaning of the flag bits: */
                               /* A task is currently running a checksum */
#define LIBF_SUMMING (1 << 0)  /* on this library (system maintains this */
```c
                               /* flag)                                  */
```
#define LIBF_CHANGED (1 << 1)  /* One or more entries have been changed  */

```c
                               /* in the library code vectors used by    */
                               /* SumLibrary (system maintains this flag)*/
```
#define LIBF_SUMUSED (1 << 2)  /* A checksum fault should cause a system */
```c
                               /* panic (library flag)                   */
```
#define LIBF_DELEXP (1 << 3)   /* A user has requested expunge but       */


```c
                               /* another user still has the library     */
                               /* open (this is maintained by library)   */
```
 [Using a Library to Reference Data](../Libraries_Manual_guide/node0293.html)    [Relationship of Libraries to Devices](../Libraries_Manual_guide/node0294.html) 
 [Minimum Subset of Library Vectors](../Libraries_Manual_guide/node0295.html)    [Changing the Contents of a Library](../Libraries_Manual_guide/node0296.html) 

