# 4 / Window Types / Borderless Window Type


The borderless window type has no borders rendered by Intuition.  Such a
window will have no visual delineation from the rest of the display.  Be
aware that a Borderless window which does not cover the entire display may
cause visual confusion for the user.  When using a borderless window that
does not cover the entire display, the application should provide some
form of graphics to replace the borders provided by Intuition.

In general, none of the system gadgets or the window title should be
specified for a borderless window, as they may cause at least part of the
border to be rendered.

A typical application of a borderless window is to simulate graphics drawn
directly into the screen, while remaining compatible with windows and
menus. In this case, the application will often create a full sized,
borderless, backdrop window.

Use the WFLG_BORDERLESS flag or the [WA_Borderless](../Libraries_Manual_guide/node0125.html#line68) tag to get this window
type.

