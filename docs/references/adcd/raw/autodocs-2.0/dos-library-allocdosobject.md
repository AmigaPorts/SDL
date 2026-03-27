# dos.library/AllocDosObject



NAME

```c
    AllocDosObject -- Creates a dos object (V36)
```
SYNOPSIS

```c
    ptr = AllocDosObject(type, tags)
    D0                    D1    D2

    void *AllocDosObject(ULONG, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    ptr = AllocDosObjectTagList(type, tags)
    D0                           D1    D2

    void *AllocDosObjectTagList(ULONG, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    ptr = AllocDosObjectTags(type, Tag1, ...)

    void *AllocDosObjectTags(ULONG, ULONG, ...)
```
FUNCTION

    Create one of several dos objects, initializes it, and returns it
    to you.  Note the DOS_STDPKT returns a pointer to the sp_Pkt of the
    structure.
INPUTS

    type - type of object requested
    tags - pointer to taglist with additional information
RESULT

    packet - pointer to the object or NULL
SEE ALSO

```c
    [FreeDosObject()](../Includes_and_Autodocs_2._guide/node02B2.html), [<dos/dostags.h>](../Includes_and_Autodocs_2._guide/node006D.html), [<dos/dos.h>](../Includes_and_Autodocs_2._guide/node0068.html)
```
