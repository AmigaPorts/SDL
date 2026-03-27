# dos.library/FreeDosEntry



NAME

```c
    FreeDosEntry -- Frees an entry created by [MakeDosEntry](../Includes_and_Autodocs_2._guide/node02CA.html) (V36)
```
SYNOPSIS

```c
    FreeDosEntry(dlist)
                   D1

    void FreeDosEntry(struct [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) *)
```
FUNCTION

```c
    Frees an entry created by [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html).  This routine should be
    eliminated and replaced by a value passed to FreeDosObject()!
```
INPUTS

```c
    dlist - [DosList](../Includes_and_Autodocs_2._guide/node0078.html#line369) to free.
```
SEE ALSO

```c
    [AddDosEntry()](../Includes_and_Autodocs_2._guide/node027C.html), [RemDosEntry()](../Includes_and_Autodocs_2._guide/node02E6.html), [FindDosEntry()](../Includes_and_Autodocs_2._guide/node02A7.html), [LockDosList()](../Includes_and_Autodocs_2._guide/node02C7.html),
    [NextDosEntry()](../Includes_and_Autodocs_2._guide/node02D5.html), [MakeDosEntry()](../Includes_and_Autodocs_2._guide/node02CA.html)
```
