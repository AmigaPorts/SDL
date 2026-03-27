---
title: 3 / Intuition Screens and the Graphics Library / Direct Screen Access
manual: libraries
chapter: libraries
section: 3-intuition-screens-and-the-graphics-library-direct-screen
functions: [ShowTitle, SizeLayer, SizeWindow]
libraries: [intuition.library, layers.library]
---

# 3 / Intuition Screens and the Graphics Library / Direct Screen Access

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sometimes an application may want direct access to the custom screen's
bitmap to use with low-level graphics library calls.  This may be useful
if the application needs to do custom manipulation of the display but also
needs Intuition functionality.  For instance, an application may want to
use the graphics library primitives to perform double buffering then, when
detecting user input, switch to Intuition control of the screen so that
windows, gadgets and menus may be used to process the user input.  If an
application chooses to combine these techniques, it must take special care
to avoid conflicts with Intuition rendered graphics.  An example of how to
do this is listed in the next section, "[Advanced Screen Programming](libraries/3-advanced-screen-programming-double-buffering.md)".

Application programs that open [custom screens](libraries/3-intuition-screens-custom-screen-functions.md) may use the screen's display
memory in any way they choose.  However, this memory is also used by
Intuition for windows and other high level display components on the
screen.  Writing directly to the screen memory, whether through direct
access or through graphics library calls that access the screen's
[RastPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md), is not compatible with many Intuition constructs such as windows
and menus.

Techniques such as this require great care and understanding of the Amiga.
If possible, the application should avoid these techniques and only use
standard Intuition display and input processing.  Directly accessing the
screen's bitmap, while possible, is not recommended.  A better way to
access the screen display is through windows.  Windows provide access to
the screen through layers which perform clipping and arbitration between
multiple drawing areas.

Alternatives to writing directly to a screen, such as using a backdrop
window, greatly limit the number of cases where an application must access
screen memory.  The [ShowTitle()](libraries/3-other-screen-functions-miscellaneous-screen-functions.md) function allows the screen's title bar
layer to be positioned in front of or behind any backdrop windows that are
opened on the screen.  Hence, a backdrop window may be created that uses
the entire visible area of the monitor. Application programs that use
existing [public screens](libraries/3-intuition-screens-public-screen-functions.md) do not have the same freedom to access the
screen's display memory as they do with [custom screens](libraries/3-intuition-screens-custom-screen-functions.md).  In general,
public screens must be shared through the use of windows and menus rather
than directly accessing the screen's display memory.


```c
    Use Direct Access Only On Screens You Own.
    ------------------------------------------
    An application may not steal the bitmap of a screen that it does not
    own.  Stealing the Workbench screen's bitmap, or that of any other
    [public screen](libraries/3-intuition-screens-public-screen-functions.md), is strictly illegal.  Accessing the underlying
    graphics structures of a screen may only be done on [custom screens](libraries/3-intuition-screens-custom-screen-functions.md)
    opened by the application itself.

    Do Not Perform Layers Operations Directly.
    ------------------------------------------
    While [layers](libraries/30-layers-library.md) are not part of the graphics library, it is appropriate
    to mention them here.  Certain types of layers operations are not
    allowed with Intuition.  You may not, for example, call [SizeLayer()](libraries/30-layers-creating-and-using-new-layers.md)
    on a window (use [SizeWindow()](libraries/4-other-window-functions-program-control-of-window.md) instead). To access layers library
    features with screens, use Intuition windows!
```
A [custom screen](libraries/3-intuition-screens-custom-screen-functions.md) may be created to allow for modification of the screen's
Copper list.  The Copper is the display synchronized co-processor that
handles the actual video display by directly affecting the hardware
registers.  See the Amiga [Hardware](hardware/amiga-hardware-reference-manual-2-coprocessor-hardware.md) Reference Manual or the [graphics](libraries/graphics-libraries.md)
library chapters for more information on programming the Copper.

---

## See Also

- [ShowTitle — intuition.library](../autodocs/intuition.library.md#showtitle)
- [SizeLayer — layers.library](../autodocs/layers.library.md#sizelayer)
- [SizeWindow — intuition.library](../autodocs/intuition.library.md#sizewindow)
