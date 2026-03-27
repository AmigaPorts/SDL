# 3 / DrawInfo and the 3D Look / The Font Specification in DrawInfo


Font information for a screen comes from a number of different places.

[SA_Font](../Libraries_Manual_guide/node00E5.html#line125)

```c
    The application may specify the font to be used in a screen by
    providing the SA_Font tag with a [TextAttr](../Libraries_Manual_guide/node03D6.html#line21) structure.  In this case,
    the font will be used by the screen and will be the default font for
    the [RastPort](../Libraries_Manual_guide/node0102.html#line8) of any window opening in the screen.
```
[SA_SysFont](../Libraries_Manual_guide/node00E5.html#line130), 0

```c
    If the application requests the user's preferred monospace font, it
    is taken from [GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24).  Any window's [RastPorts](../Libraries_Manual_guide/node0102.html#line8) are also
    initialized to use this same font.
```
SA_SysFont, 1

```c
    The screen font selected by the user from the Preferences font editor
    may be used for the screen by using the SA_SysFont tag.  This font,
    the "preferred screen font", may be proportional.  For compatibility
    reasons, if this font is specified for the screen, the window's
    [RastPort](../Libraries_Manual_guide/node0102.html#line8) will be initialized to [GfxBase->DefaultFont](../Includes_and_Autodocs_2._guide/node00AE.html#line24) (a
    non-proportional font).
```
To access information on an open screen's font, the application may
reference [Screen.Font](../Libraries_Manual_guide/node00DD.html#line76) or [DrawInfo.dri_Font](../Libraries_Manual_guide/node00EB.html#line8).  These fonts are identical,
the [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structure simply provides an alternate method of accessing
the information.  Note that Screen.Font is a pointer to a [TextAttr](../Libraries_Manual_guide/node03D6.html#line21)
structure and that DrawInfo.dri_Font is a pointer to a [TextFont](../Libraries_Manual_guide/node03DE.html) structure.
The application may use whichever form is best suited to its requirements.

It is illegal to change the screen's font after the screen is opened.
This means that the font specified in the [Screen](../Libraries_Manual_guide/node00DE.html#line6) and [DrawInfo](../Libraries_Manual_guide/node00DE.html#line6) structures
is guaranteed to remain open as long is the screen is open.

The menu bar, window titles, menu items, and the contents of a string
gadget all use the screen's font.  The font used for menu items can be
overridden in the menu item's [IntuiText](../Libraries_Manual_guide/node01C7.html) structure.  Under V36 and higher,
the font used in a string gadget can be overridden through the
[StringExtend](../Libraries_Manual_guide/node016D.html) structure.  The font of the menu bar and window titles cannot
be overridden.

For more information on screen fonts, see the description of the [SA_Font](../Libraries_Manual_guide/node00E5.html#line125)
and [SA_SysFont](../Libraries_Manual_guide/node00E5.html#line130) tags in the "Screen Attributes" section above.

