# exec.library/ReleaseSemaphoreList



NAME

    ReleaseSemaphoreList -- make a list of semaphores available
SYNOPSIS

```c
    ReleaseSemaphoreList(list)
                         A0

    void ReleaseSemaphoreList(struct [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) *);
```
FUNCTION

```c
    ReleaseSemaphoreList() is the inverse of [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html). It
    releases each element in the semaphore list.

    Needless to say, havoc breaks out if the task releases more times
    than it has obtained.
```
INPUT
   list -- a list of signal semaphores

SEE ALSO

```c
    [ObtainSemaphoreList()](../Includes_and_Autodocs_2._guide/node0363.html)
```
