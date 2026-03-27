# 9 / / Event Message Classes and Flags / Gadget Flags


IDCMP_GADGETDOWN

```c
    IDCMP_GADGETDOWN messages are sent when the user selects a gadget
    that was created with the [GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) flag set.  The [IntuiMessage](../Libraries_Manual_guide/node01D9.html)
    structure's [IAddress](../Libraries_Manual_guide/node01D9.html#line73) field will contain a pointer to the selected
    gadget.
```
IDCMP_GADGETUP

```c
    IDCMP_GADGETUP messages are sent when the user selects a gadget that
    was created with the [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) flag set.  The [IntuiMessage](../Libraries_Manual_guide/node01D9.html)
    structure's [IAddress](../Libraries_Manual_guide/node01D9.html#line73) field will contain a pointer to the selected
    gadget.
```
IDCMP_CLOSEWINDOW

```c
    IDCMP_CLOSEWINDOW messages are sent when the user selects the
    window's close gadget.  Intuition does not close the window when the
    close gadget is selected.  Rather, an IDCMP_CLOSEWINDOW message is
    sent to the window's IDCMP.  It is up to the application to clean up
    and close the window itself.  If closing a window means losing some
    data (perhaps the spreadsheet the user was working on), it would be
    appropriate for the application to first confirm that the user really
    meant to close the window.
```
