# 4 / / Opening A Window / Setting Window Attributes


Depending on which function is used to open a window, the window's
attributes may be specified using [TagItem](../Includes_and_Autodocs_2._guide/node012E.html#line31)s, or a [NewWindow](../Libraries_Manual_guide/node0102.html#line8) structure or an
[ExtNewWindow](../Libraries_Manual_guide/node0102.html#line8) structure.  In the [code above](../Libraries_Manual_guide/node05BC.html), the window attributes are set
up with an array of TagItems:


```c
    struct TagItem win_tags[] =
        {
        {WA_Left,       MY_WIN_LEFT},
        {WA_Top,        MY_WIN_TOP},
        {WA_Width,      MY_WIN_WIDTH},
        {WA_Height,     MY_WIN_HEIGHT},
        {WA_CloseGadget,TRUE},
        {WA_IDCMP,      IDCMP_CLOSEWINDOW},
        {TAG_DONE, NULL},
        };
```
These window attributes set the window's position ([WA_Left, WA_Top](../Libraries_Manual_guide/node0124.html)) and
size ([WA_Width, WA_Height](../Libraries_Manual_guide/node0124.html)), request a close gadget on the window
([WA_CloseGadget](../Libraries_Manual_guide/node0125.html#line36)) and ask Intuition to send a message whenever the user
activates the close gadget ([WA_IDCMP](../Libraries_Manual_guide/node0124.html#line35)).

Throughout this chapter window attributes are referred to by their TagItem
ID name (the name is always prefixed with "WA_").  See the section below
on "[Window Attributes](../Libraries_Manual_guide/node0122.html)" for a complete list.


```c
    Old and New Flag Names.
    -----------------------
    The names used for IDCMP flags and window flags have been changed
    under Release 2.  IDCMP flag names are now preceded by "IDCMP_".
    Likewise window flag names are now preceded by "WFLG_".  The old
    names (and their new equivalents) are listed in
    <intuition/[iobsolete.h](../Includes_and_Autodocs_2._guide/node00E4.html)>.  You may want to refer to this file if
    you are working with example code written for V34 and older versions
    of the OS.
```
