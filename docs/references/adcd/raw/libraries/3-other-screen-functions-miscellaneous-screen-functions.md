# 3 / Other Screen Functions / Miscellaneous Screen Functions


Three other functions used with screens are DisplayBeep(), [ShowTitle()](../Includes_and_Autodocs_2._guide/node0259.html) and
[GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html).  DisplayBeep() flashes the screen colors to inform the
user of an error or problem.


```c
    VOID DisplayBeep( struct Screen *myscreen )
```
Since not all users will have speakers attached to the system,
DisplayBeep() can be used to provide a visible bell.  DisplayBeep() can
beep any single screen or, if myscreen is set to NULL, all screens.

[ShowTitle()](../Includes_and_Autodocs_2._guide/node0259.html) determines whether the screen's title bar will be displayed in
front of or behind any backdrop windows on the screen.


```c
    VOID ShowTitle( struct Screen *myscreen, BOOL infront )
```
By default, the screen's title bar is set to display in front of backdrop
windows.  Call this function with infront set to FALSE to put the screen
title bar behind backdrop windows.  This can also be set when the screen
is opened with the [SA_ShowTitle](../Libraries_Manual_guide/node00E5.html#line211) tag.

Under 1.3 (V34) and earlier versions of the Amiga OS, applications used
the [GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html) to get a copy of the Workbench [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure in
order to examine its attributes.


```c
    success = BOOL GetScreenData( APTR buffer, UWORD bufsize,
                                  UWORD type, struct Screen *scr)
```
If successful, [GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html) copies a given [Screen](../Libraries_Manual_guide/node00DE.html#line6) structure to a buffer
supplied by the application.  A copy of the Workbench Screen data can be
obtained without knowing its location in memory using GetScreenData(buf,
sizeof(struct Screen), WBENCHSCREEN, NULL).  However, for Release 2 and
later versions of the operating system, this function may return some
false information about the Workbench screen.  This false screen
information helps prevent older applications that used the call from
malfunctioning when run in a Release 2 system that has Workbench set up
with one of the newer modes.

Applications that want to get information on the Workbench screen should
use [GetScreenData()](../Includes_and_Autodocs_2._guide/node021F.html) when run under 1.3 and [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34) when run under
under Release 2.  For more about LockPubScreen() and [Workbench](../Libraries_Manual_guide/node00E8.html), see the
section on "[Public Screen Functions](../Libraries_Manual_guide/node00E6.html)" earlier in this chapter.

