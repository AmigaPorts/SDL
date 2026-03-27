# B / groupgclass / Changed: GM_GOACTIVE/GM_GOINACTIVE/GM_HANDLEINPUT


This method passes the message to the active member's dispatcher for
processing.   For GM_GOINACTIVE and GM_HANDLEINPUT, the coordinates passed
to the member's dispatcher in the message's [gpi_Mouse.X and gpi_Mouse.Y](../Libraries_Manual_guide/node04F5.html#line18)
fields are translated so that they are relative to the gadget's upper-left
corner.

