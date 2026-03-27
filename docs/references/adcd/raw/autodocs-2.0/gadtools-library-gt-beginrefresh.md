# gadtools.library/GT_BeginRefresh



NAME

```c
    GT_BeginRefresh -- Begin refreshing friendly to GadTools. (V36)
```
SYNOPSIS

```c
    GT_BeginRefresh(win)
                    A0

    VOID GT_BeginRefresh(struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) *);
```
FUNCTION

```c
    Invokes the [intuition.library/BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html) function in a manner
    friendly to the [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) Toolkit.  This function call permits the
    GadTools gadgets to refresh themselves at the correct time.
    Call [GT_EndRefresh()](../Includes_and_Autodocs_2._guide/node03F0.html) function when done.
```
INPUTS

```c
    win - Pointer to [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) structure for which a IDCMP_REFRESHWINDOW
        IDCMP event was received.
```
RESULT

    None.
EXAMPLE

NOTES

```c
    The nature of GadTools precludes the use of the IDCMP flag
    WFLG_NOCAREREFRESH.  You must handle IDCMP_REFRESHWINDOW events
    in at least the minimal way, namely:

            case IDCMP_REFRESHWINDOW:
                GT_BeginRefresh(win);
                GT_EndRefresh(win, TRUE);
                break;
```
BUGS

SEE ALSO

```c
    [intuition.library/BeginRefresh()](../Includes_and_Autodocs_2._guide/node0200.html)
```
