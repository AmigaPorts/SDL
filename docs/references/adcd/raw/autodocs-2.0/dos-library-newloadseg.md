# dos.library/NewLoadSeg



NAME

```c
    NewLoadSeg -- Improved version of [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) for stacksizes (V36)
```
SYNOPSIS

```c
    seglist = NewLoadSeg(file, tags)
    D0                    D1    D2

    BPTR NewLoadSeg(STRPTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    seglist = NewLoadSegTagList(file, tags)
    D0                           D1    D2

    BPTR NewLoadSegTagList(STRPTR, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *)

    seglist = NewLoadSegTags(file, ...)

    BPTR NewLoadSegTags(STRPTR, ...)
```
FUNCTION

```c
    Does a [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) on a file, and takes additional actions based on the
    tags supplied.

    Clears unused portions of Code and Data hunks (as well as BSS hunks).
    (This also applies to [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html) and [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)).

    NOTE to overlay users: NewLoadSeg() does NOT return seglist in
    both D0 and D1, as [LoadSeg](../Includes_and_Autodocs_2._guide/node02C5.html) does.  The current ovs.asm uses [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html),
    and assumes returns are in D1.  We will support this for [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html)
    ONLY.
```
INPUTS

    file - Filename of file to load
    tags - pointer to tagitem array
RESULT

    seglist - Seglist loaded, or NULL
BUGS

    No tags are currently defined.
SEE ALSO

```c
    [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html), [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html), [InternalLoadSeg()](../Includes_and_Autodocs_2._guide/node02C0.html), [InternalUnLoadSeg()](../Includes_and_Autodocs_2._guide/node02C1.html)
```
