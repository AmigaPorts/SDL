# 9 / / Event Message Classes and Flags / Window Flags


IDCMP_NEWSIZE

    Intuition sends this message after the user has resized the window.
    After receiving this, the program can examine the size variables in
    the window structure to discover the new size of the window.  The
    message is sent, even if the size of the window did not actually
    change.
IDCMP_REFRESHWINDOW

```c
    This message is sent whenever the window needs refreshing.  This flag
    makes sense only with windows that have a refresh type of
    [WA_SimpleRefresh](../Libraries_Manual_guide/node0125.html#line110) or [WA_SmartRefresh](../Libraries_Manual_guide/node0125.html#line115).

    As a minimum, the application must call [BeginRefresh()](../Libraries_Manual_guide/node011E.html) and
    [EndRefresh()](../Libraries_Manual_guide/node011E.html#line25) for the window after receiving an IDCMP_REFRESHWINDOW
    event.  Create the window with the [WA_NoCareRefresh](../Libraries_Manual_guide/node0125.html#line62) attribute if you
    do not want to manage these events.  See the "[Intuition Windows](../Libraries_Manual_guide/node0119.html)"
    chapter for details.

    Most of the graphics library calls used for display output are
    compatible with Intuition, with the exception of ScrollRaster().
    Intuition will not send an IDCMP_REFRESHWINDOW event when damage is
    caused to a window by [ScrollRaster()](../Libraries_Manual_guide/node0363.html).  This may happen in a simple
    refresh window which is partially obscured by another window--the
    region that scrolls out from behind the front window will be damaged,
    but the window will receive no notification.  Check the LAYERREFRESH
    bit in the [Layer](../Libraries_Manual_guide/node03E4.html) structure Flags field to see if damage did happen as
    a result of ScrollRaster().
```
IDCMP_SIZEVERIFY

```c
    Set this flag if the program must complete some operation before the
    user sizes the window.  When the user sizes the window, Intuition
    sends an IDCMP_SIZEVERIFY message to the application and then waits
    until the program replies before allowing the user to size the
    window.  See the "[Verification Functions](../Libraries_Manual_guide/node01E2.html)" section below for some
    things to consider when using this flag.
```
IDCMP_ACTIVEWINDOW and IDCMP_INACTIVEWINDOW

    Set these flags to discover when the window becomes activated or
    deactivated.
