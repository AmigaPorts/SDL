# intuition.library/GetScreenDrawInfo



NAME

```c
    GetScreenDrawInfo -- Get pointer to rendering information. (V36)
```
SYNOPSIS

```c
    DrInfo = GetScreenDrawInfo( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) )
    D0                          A0

    struct [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) *GetScreenDrawInfo( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) * );
```
FUNCTION

```c
    Returns a pointer to a [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure derived from the
    screen passed.  This data structure is READ ONLY.  The field
    dri_Version identifies which version of struct [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) you
    are given a pointer to.
```
INPUTS

```c
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97)        - pointer to a valid, open screen.
```
RESULT

```c
    DrInfo - pointer to a system-allocated [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure,
    as defined in [intuition/screens.h](../Includes_and_Autodocs_2._guide/node00DD.html).
```
NOTES

```c
    Some information in the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure may in the future
    be calculated the first time this function is called for a
    particular screen.

    You must call [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html) when you are done using the
    returned pointer.

    This function does not prevent a screen from closing.  Apply it
    only to the screens you opened yourself, or apply a protocol
    such as [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).

    WARNING: Until further notice, the pointer returned does not
    remain valid after the screen is closed.

    This function and [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html) don't really do much now,
    but they provide an upward compatibility path.  That means that
    if you misuse them today, they probably won't cause a problem,
    although they may someday later.  So, please be very careful
    only to use the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure between calls to
    GetScreenDrawInfo() and [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html), and be sure
    that you don't forget [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html).
```
BUGS

    Does not reflect to changes in screen modes, depth, or pens.
SEE ALSO

```c
    [FreeScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0218.html), [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html), [intuition/screens.h](../Includes_and_Autodocs_2._guide/node00DD.html)
```
