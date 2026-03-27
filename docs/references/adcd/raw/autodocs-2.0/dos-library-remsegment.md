# dos.library/RemSegment



NAME

```c
    RemSegment - Removes a resident segment from the resident list (V36)
```
SYNOPSIS

```c
    success = RemSegment(segment)
    D0                      D1

    BOOL RemSegment(struct [Segment](../Includes_and_Autodocs_2._guide/node0078.html#line296) *)
```
FUNCTION

```c
    Removes a resident segment from the Dos resident segment list,
    unloads it, and does any other cleanup required.  Will only succeed
    if the seg_UC (usecount) is 0.
```
INPUTS

    segment - the segment to be removed
RESULT

    success - success or failure.
SEE ALSO

```c
    [FindSegment()](../Includes_and_Autodocs_2._guide/node02A8.html), [AddSegment()](../Includes_and_Autodocs_2._guide/node027E.html)
```
