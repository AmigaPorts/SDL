# intuition.library/PubScreenStatus



NAME

```c
    PubScreenStatus -- Change status flags for a public screen. (V36)
```
SYNOPSIS

```c
    ResultFlags = PubScreenStatus( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97), StatusFlags )
    D0                             A0      D0

    UWORD PubScreenStatus( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, UWORD );
```
FUNCTION

    Changes status flags for a given public screen.

    Do not apply this function to a screen if your program
    isn't the screen's "owner", in particular, don't call
    this function for the Workbench screen.
INPUTS

```c
    [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = pointer to public screen
    StatusFlags = values currently:
      PSNF_PRIVATE: make this screen unavailable to visitor windows
```
RESULT

    Returns 0 in the lowest order bit of the return value
    if the screen wasn't public, or because it can not be taken
    private because visitors are open in it.

    All other bits in the return code are reserved for future
    enhancement.
BUGS

SEE ALSO

```c
    [OpenScreen()](../Includes_and_Autodocs_2._guide/node0237.html), Intuition V36 update documentation
```
