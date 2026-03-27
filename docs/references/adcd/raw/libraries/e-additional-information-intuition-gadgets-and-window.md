# E / Additional Information / Intuition Gadgets and Window Borders


If 2.0 Intuition finds a gadget whose hit area ([Gadget](../Libraries_Manual_guide/node0149.html) [LeftEdge](../Libraries_Manual_guide/node0149.html#line33)/[TopEdge](../Libraries_Manual_guide/node0149.html#line33)/
[Width](../Libraries_Manual_guide/node0149.html#line33)/[Height](../Libraries_Manual_guide/node0149.html#line33)) is substantially inside the border, it will be treated as
though it was declared in the border.  This is called "bordersniffing".
Gadgets declared as being in the border or detected by Intuition as being
in the border are refreshed each time after the border is refreshed, and
thus aren't clobbered.

Noteworthy special cases:

 1) A gadget that has several pixels not in the border is not

```c
    bordersniffed. An example would be an 18-pixel high gadget in the
    bottom border of a [SIZEBBOTTOM](../Libraries_Manual_guide/node0125.html#line19) window.  About half the gadget will be
    clobbered by the border rendering.
```
 2) A gadget that is not substantially in the border but has imagery that

    extends into the border cannot be sniffed out by Intuition.
 3) A gadget that is substantially in the border but has imagery that

```c
    extends into the main part of the window will be sniffed out as a
    border gadget, and this could change the refreshing results.  A
    common trick to put imagery in a window is to put a 1x1 or 0x0 dummy
    gadget at window location (0,0) and attach the window imagery to it.
    To support this, Intuition will never bordersniff gadgets of size 1x1
    or smaller.

    All these cases can be fixed by setting the appropriate
    GACT_xxxBORDER gadget [Activation](../Libraries_Manual_guide/node0149.html#line53) flag.
```
 4) In rare cases, buttons rendered with [Border](../Libraries_Manual_guide/node01C1.html) structures and [JAM1](../Libraries_Manual_guide/node01C1.html#line25) text

    may appear invisible under Release 2.
The height of the window's title bar is affected by the current font
settings.  See the discussion of "[Screen Attributes](../Libraries_Manual_guide/node00E5.html#line125)" in the "Intuition
Screens" chapter. To predict your window's titlebar height before you call
[OpenWindow()](../Libraries_Manual_guide/node0103.html):


```c
    topborder = screen->WBorTop + screen->Font->ta_YSize + 1
```
The screen's font may not legally be changed after a screen is opened.

Be sure the screen cannot go away on you.  This is true if:


```c
    1) You opened the screen yourself.

    2) You currently have a window open on the screen.

    3) You currently hold a lock on this screen (see [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34)).
```
[IntuiText](../Libraries_Manual_guide/node01C7.html) rendered into a window (either through [PrintIText()](../Libraries_Manual_guide/node01C8.html) or as a
gadget's [GadgetText](../Libraries_Manual_guide/node0149.html#line111)) defaults to the Window [RastPort](../Libraries_Manual_guide/node034A.html) font, but can be
overridden using its [ITextFont](../Libraries_Manual_guide/node01C7.html#line59) field.  Text rendered with the [Text()](../Libraries_Manual_guide/node03D5.html)
function appears in the Window RastPort font.

The Window's [RPort](../Libraries_Manual_guide/node0121.html#line66)'s font shown above is the initial font that Intuition
sets for you in your window's [RastPort](../Libraries_Manual_guide/node034A.html). It is legal to change that
subsequently with [SetFont()](../Libraries_Manual_guide/node03D6.html).

