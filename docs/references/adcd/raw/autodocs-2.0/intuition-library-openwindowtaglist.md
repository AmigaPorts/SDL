# intuition.library/OpenWindowTagList



NAME

```c
    OpenWindowTagList -- [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) with [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) extension. (V36)
    OpenWindowTags -- Varargs stub for OpenWindowTagList (V36)
```
SYNOPSIS

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = OpenWindowTagList( [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976), TagItems )
    D0                          A0         A1

    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *OpenWindowTagList( struct [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) *,
            struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) * );

    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) = OpenWindowTags( [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976), Tag1, ... )

    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *OpenWindowTags( struct [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) *, ULONG, ... );
```
FUNCTION

```c
    A variation of [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) that allow direct specification of
    a [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) array of extension data.  Recommended over using the
    ExtNewWindow.Extension field.

    If you omit the [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) (pass NULL), a set of defaults
    are used, and overridden by the tag items.  Even without
    any tag items at all, a reasonable window opens on the Workbench
    or default public screen.

    See [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) for all the details.
```
INPUTS

```c
    [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) - (optional) pointer to a [NewWindow](../Includes_and_Autodocs_2._guide/node00D4.html#line976) structure.
    TagItems - (optional) pointer to [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) array, with tag
            values as described under the description for
            [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html).
```
RESULT

```c
    [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) - newly created window, per your specifications.
```
EXAMPLE

```c
    See [OpenScreenTagList()](../Includes_and_Autodocs_2._guide/node0238.html) for an example of how to create
    a "varargs" version of this function for convenient C
    language programming.
```
NOTES


BUGS


SEE ALSO

```c
    [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
```
