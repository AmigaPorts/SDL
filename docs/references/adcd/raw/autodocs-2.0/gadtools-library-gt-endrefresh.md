# gadtools.library/GT_EndRefresh



NAME

```c
    GT_EndRefresh -- End refreshing friendly to GadTools. (V36)
```
SYNOPSIS

```c
    GT_EndRefresh(win, complete)
                  A0   D0

    VOID GT_EndRefresh(struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *, BOOL complete);
```
FUNCTION

```c
    Invokes the [intuition.library/EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html) function in a manner
    friendly to the [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) Toolkit.  This function call permits
    GadTools gadgets to refresh themselves at the correct time.
    Call this function to [EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html) when you have used
    [GT_BeginRefresh()](../Includes_and_Autodocs_2._guide/node03EF.html).
```
INPUTS

```c
    win - Pointer to [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure for which a IDCMP_REFRESHWINDOW
        IDCMP event was received.
    complete - TRUE when done with refreshing.
```
RESULT

    None.
EXAMPLE

NOTES

BUGS

SEE ALSO

```c
    [intuition.library/EndRefresh()](../Includes_and_Autodocs_2._guide/node0213.html)
```
