# exec.library/Vacate



NAME

```c
    Vacate -- release a message lock (semaphore)
```
SYNOPSIS

```c
    Vacate(semaphore)
           A0

    void Vacate(struct [Semaphore](../Includes_and_Autodocs_2._guide/node0082.html#line53) *);
```
FUNCTION

```c
    This function releases a previously locked semaphore (see
    the [Procure()](../Includes_and_Autodocs_2._guide/node036A.html) function).
    If another task is waiting for the semaphore, its bidMessage
    will be sent to its reply port.
```
INPUT

    semaphore - the semaport message port representing the
    semaphore to be freed.
BUGS

```c
    [Procure()](../Includes_and_Autodocs_2._guide/node036A.html) and Vacate() do not have proven reliability.
```
SEE ALSO

```c
    [Procure](../Includes_and_Autodocs_2._guide/node036A.html)
```
