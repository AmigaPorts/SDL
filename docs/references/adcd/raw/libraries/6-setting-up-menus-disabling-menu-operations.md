# 6 / Setting Up Menus / Disabling Menu Operations


If an application does not use menus at all, it may set the [WFLG_RMBTRAP](../Libraries_Manual_guide/node0125.html#line95)
flag, which allows the program to trap right mouse button events for its
own use.

By setting the [WFLG_RMBTRAP](../Libraries_Manual_guide/node0125.html#line95) flag with the [WA_Flags](../Libraries_Manual_guide/node0125.html#line147) tag when the window is
opened, the program indicates that it does not want any menu operations at
all for the window.  Whenever the user presses the right button while this
window is active, the program will receive right button events as normal
[IDCMP_MOUSEBUTTONS](../Libraries_Manual_guide/node01DC.html) events.

