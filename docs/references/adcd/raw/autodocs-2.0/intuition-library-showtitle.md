# intuition.library/ShowTitle



NAME

    ShowTitle -- Set the screen title bar display mode.
SYNOPSIS

```c
    ShowTitle( [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97), ShowIt )
               A0      D0

    VOID ShowTitle( struct [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) *, BOOL );
```
FUNCTION
    This routine sets the SHOWTITLE flag of the specified screen, and
    then coordinates the redisplay of the screen and its windows.

    The screen title bar can appear either in front of or behind
    WFLG_BACKDROP windows.  This is contrasted with the fact that
    non-WFLG_BACKDROP windows always appear in front of the screen title
    bar.  You specify whether you want the screen title bar to be in front
    of or behind the screen's WFLG_BACKDROP windows by calling this
    routine.

    The ShowIt argument should be set to either TRUE or FALSE.  If TRUE,
   the screen's title bar will be shown in front of WFLG_BACKDROP windows
.
   If FALSE, the title bar will be rendered behind all windows.

   When a screen is first opened, the default setting of the SHOWTITLE
   flag is TRUE.

INPUTS
   [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) = pointer to a [Screen](../Includes_and_Autodocs_2._guide/node00DD.html#line97) structure
   ShowIt = Boolean TRUE or FALSE describing whether to show or hide the

       screen title bar
RESULT
   None

BUGS

SEE ALSO

