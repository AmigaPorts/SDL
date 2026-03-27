# intuition.library/UnlockPubScreen



NAME

```c
    UnlockPubScreen -- Release lock on a public screen. (V36)
```
SYNOPSIS

```c
    UnlockPubScreen( Name, [Screen] )
                     A0    A1

    VOID UnlockPubScreen( UBYTE *, struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) * );
```
FUNCTION

```c
    Releases lock gotten by [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).
    It is best to identify the locked public screen by
    the pointer returned from [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).  To do this,
    supply a NULL 'Name' pointer and the screen pointer.

    In rare circumstances where it would be more convenient to pass
    a non-NULL pointer to the public screen name string, the
    'Screen' parameter is ignored.
```
INPUTS

```c
    Name = pointer to name of public screen.  If Name is NULL,
        then argument 'Screen' is used as a direct pointer to
        a public screen.
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = pointer to a public screen.  Used only if Name
        is NULL.  This pointer MUST have been returned
        by [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html).
        It is safe to call UnlockPubScreen() with NULL Name
        and [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) (the function will have no effect).
```
RESULT

BUGS

SEE ALSO

```c
    [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html)
```
