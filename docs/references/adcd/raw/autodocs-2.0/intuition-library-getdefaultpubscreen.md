# intuition.library/GetDefaultPubScreen



NAME

```c
    GetDefaultPubScreen -- Get name of default public screen. (V36)
```
SYNOPSIS

```c
    GetDefaultPubScreen( Namebuff )
                         A0

    VOID GetDefaultPubScreen( UBYTE * );
```
FUNCTION

```c
    Provides the name of the current default public screen.
    Only anticipated use is for Public [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) Manager utilities,
    since it is easy to open a visitor window on the default
    public screen without specifying the name.
```
INPUTS

```c
    Namebuff = a buffer of MAXPUBSCREENNAME.  This can be NULL.
```
RESULT

    None.  Will provide the string "Workbench" in Namebuff if there
    is no current default public screen.
NOTE

```c
    This function actually "returns" in register D0 a pointer
    to the public screen.  Unfortunately, the lifespan of
    this pointer is not ensured; the screen could be closed
    at any time.  The *ONLY* legitimate use we can see for
    this return value is to compare for identity with the pointer
    to a public screen you either have a window open in, or
    a lock on using [LockPubScreen()](../Includes_and_Autodocs_2._guide/node0225.html), to determine if that
    screen is in fact the default screen.
```
BUGS

    The function prototype does not reflect the return value.
SEE ALSO

```c
    [SetDefaultPubScreen()](../Includes_and_Autodocs_2._guide/node024F.html), [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html)
```
