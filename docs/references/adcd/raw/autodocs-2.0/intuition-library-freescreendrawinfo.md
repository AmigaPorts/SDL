# intuition.library/FreeScreenDrawInfo



NAME

```c
    FreeScreenDrawInfo -- Finish using a [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure. (V36)
```
SYNOPSIS

```c
    FreeScreenDrawInfo( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97), DrInfo )
                        A0      A1

    VOID FreeScreenDrawInfo( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, struct [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) * );
```
FUNCTION

```c
    Declares that you are finished with the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure
    returned by [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html).
```
INPUTS

```c
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97)           - pointer to screen passed to [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html)
    DrInfo      - pointer to [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) returned by [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html)
```
RESULT

    None
NOTES

```c
    This function, and [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html), don't really do much, but
    they provide an upward compatibility path.  That means that
    if you misuse them today, they probably won't cause a problem,
    although they may someday later.  So, please be very careful
    only to use the [DrawInfo](../Includes_and_Autodocs_2._guide/node00DD.html#line60) structure between calls to
    [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html) and FreeScreenDrawInfo(), and be sure
    that you don't forget FreeScreenDrawInfo().
```
BUGS

SEE ALSO

```c
    [GetScreenDrawInfo()](../Includes_and_Autodocs_2._guide/node0220.html)
```
