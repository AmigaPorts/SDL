/* Source: ADCD 2.1
 * Section: 3-custom-screen-functions-screen-attributes
 * Library: libraries
 * ADCD reference: libraries/3-custom-screen-functions-screen-attributes.md
 */

    Alternative to SA_Font.  Selects one of the preferences system fonts.
    Data is a long, unsigned value, with the following values defined:

        0  Open screen with the user's preferred fixed width font
           (the default).
        1  Open screen with the user's preferred font, which may be
           proportional.

    The Workbench screen is opened with {SA_SysFont , 1}.  Table 3-4
    summarizes how the font selected at [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) time effects
    subsequent text operations in screens and windows.


                Table 3-4: Intuition Font Selection Chart

       What you tell
       [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6)            Screen font            Window.RPort font
       -------------           -----------            -----------------
    A. [NewScreen](../Libraries_Manual_guide/node00DE.html#line6).Font=myfont  myfont                  myfont
    B. NewScreen.Font=NULL    GfxBase->DefaultFont    GfxBase->DefaultFont
    C. {SA_Font, myfont}      myfont                  myfont
    D. {SA_SysFont, 0}        GfxBase->DefaultFont    GfxBase->DefaultFont
    E. {SA_SysFont, 1}        Font Prefs Screen text  GfxBase->DefaultFont

       Notes:
     * A and B are the options that existed in V34 and earlier OS versions.
     * C and D are tags in Release 2 equivalent to A and B respectively.
     * E is a new option for V36.  The Workbench screen uses this option.
     * For `myfont', any font may be used including a proportional one.
       This is true under all releases of the OS.
     * GfxBase->DefaultFont is always monospace.  (This is the "System
       Default Text" from Font Preferences.)
     * Font Prefs Screen text (the "Screen Text" choice from Font
       Preferences) can be monospace or proportional.


    The screen's font may not legally be changed after a screen is
    opened. The menu bar, window titles, menu items, and the contents of
    a string gadget all use the screen's font.  The font used for menu
    items can be overridden in the menu item's [IntuiText](../Libraries_Manual_guide/node01C7.html) structure.
    Under V36 and higher, the font used in a string gadget can be
    overridden through the [StringExtend](../Libraries_Manual_guide/node016D.html) structure.  The font of the menu
    bar and window titles cannot be overridden.

    The [Window.RPort](../Libraries_Manual_guide/node0121.html#line66) font shown above is the initial font that Intuition
    sets in your window's [RastPort](../Libraries_Manual_guide/node0102.html#line8).  It is legal to change that
    subsequently with [SetFont()](../Libraries_Manual_guide/node03D6.html).  [IntuiText](../Libraries_Manual_guide/node01C7.html) rendered into a window
    (either through [PrintIText()](../Libraries_Manual_guide/node01C8.html) or as a gadget's [GadgetText](../Libraries_Manual_guide/node0149.html#line111)) defaults to
    the window's RastPort font, but can be overridden using its [ITextFont](../Libraries_Manual_guide/node01C7.html#line59)
    field.  Text rendered with the graphics library call [Text()](../Libraries_Manual_guide/node03D5.html) uses the
    window's RastPort font.
