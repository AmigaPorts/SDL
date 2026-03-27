# gadtools.library/GetVisualInfoA



NAME

```c
    GetVisualInfoA -- Get information GadTools needs for visuals. (V36)
    GetVisualInfo -- Varargs stub for GetVisualInfoA(). (V36)
```
SYNOPSIS

```c
    vi = GetVisualInfoA(screen, taglist)
    D0                  A0      A1

    APTR vi = GetVisualInfoA(struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, struct [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31) *);

    vi = GetVisualInfo(screen, firsttag, ...)

    APTR vi = GetVisualInfo(struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, Tag, ...);
```
FUNCTION

```c
    Get a pointer to a (private) block of data containing various bits
    of information that GadTools needs to ensure the best quality
    visuals.  Use the result in the [NewGadget](../Includes_and_Autodocs_2._guide/node0106.html#line93) structure of any gadget
    you create, or as a parameter to the various menu calls.  Once the
    gadgets/menus are no longer needed (after the last CloseWindow),
    call [FreeVisualInfo()](../Includes_and_Autodocs_2._guide/node03ED.html).
```
INPUTS

    screen - Pointer to the screen you will be opening on.
    taglist - Pointer to list of TagItems.
RESULT

    vi - Pointer to private data.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [FreeVisualInfo()](../Includes_and_Autodocs_2._guide/node03ED.html), [intuition/LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html),
    [intuition/UnlockPubScreen()](../Includes_and_Autodocs_2._guide/node025D.html)
```
