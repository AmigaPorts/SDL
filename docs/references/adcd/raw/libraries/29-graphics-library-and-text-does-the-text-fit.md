# 29 Graphics Library and Text / Does the Text Fit?


The [Text()](../Libraries_Manual_guide/node03D5.html) function renders its text on a single horizontal line without
considering whether or not the text it renders will actually fit in the
visible portion of the display area.  Although for some applications this
behavior is acceptable, other applications, for example a word processor,
need to render all of their text where the user can see it.  These
applications need to measure the display area to determine how much text
can fit along a given baseline.  The graphics.library contains several
functions that perform some of the necessary measurements:


```c
    WORD TextLength( struct RastPort *my_rp, STRPTR mystring,
                     ULONG mycount );

    void TextExtent( struct RastPort *my_rp, STRPTR mystring, LONG mycount,
                     struct TextExtent *textExtent );

    void FontExtent( struct TextFont *font,
                     struct TextExtent *fontExtent );

    ULONG TextFit  ( struct RastPort *rp, STRPTR mystring, ULONG strLen,
                     struct TextExtent *textExtent,
                     struct TextExtent *constrainingExtent,
                     LONG strDirection, ULONG constrainingBitWidth,
                     ULONG constrainingBitHeight );
```
The [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html) function is intended to mimic the [Text()](../Libraries_Manual_guide/node03D5.html) function without
rendering the text.  Using the exact same parameters as the Text()
function, TextLength() returns the change in my_rp's current X position
(my_rp.cp_x) that would result if the text had been rendered using the
Text() function.  As in Text(), the mycount parameter tells how many
characters of mystring to measure.

Some fonts have characters that intrinsically render outside of the normal
rectangular bounds.  This can result for example, from the Amiga's version
of [kerning](../Libraries_Manual_guide/node03DE.html#line139) (which is discussed later in this chapter) or from algorithmic
italicizing.  In such cases, [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html) is insufficient for determining
whether a text string can fit within a given rectangular bounds.

The [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html) function offers a more complete measurement of a string
than the [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html) function.  TextExtent(), which was introduced in
Release 2, fills in the TextExtent structure passed to it based on the
current rendering settings in my_rp. T The TextExtent structure
<graphics/[text.h](../Includes_and_Autodocs_2._guide/node00A8.html#line164)>) supplies the dimensions of mystring's bounding box:


```c
    struct TextExtent {
        UWORD   te_Width;           /* same as TextLength */
        UWORD   te_Height;          /* same as tf_YSize   */
        struct Rectangle te_Extent; /* relative to CP     */
    };
```
The Rectangle structure (from <graphics/[gfx.h](../Includes_and_Autodocs_2._guide/node00A6.html#line28)>):


```c
    struct Rectangle
    {
        WORD   MinX,MinY;
        WORD   MaxX,MaxY;
    };
```
[TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html) fills in the [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line164) as follows:


```c
    te_Width        the same value returned by [TextLength()](../Includes_and_Autodocs_2._guide/node0485.html).

    te_Height       the font's Y size.

    te_Extent.MinX  the pixel offset from the rastport's current X position
                    to the left side of the bounding box defined by the
                    rectangle structure.  Normally, this is zero.

    te_Extent.MinY  the distance in pixels from the baseline to the top of
                    the bounding box.

    te_Extent.MaxX  the pixel offset from the rastport's current X position
                    to the right side of the bounding box.  Normally, this
                    is te_Width - 1.

    te_Extent.MaxY  the distance from the baseline to the bottom of the
                    bounding box.
```
The [FontExtent()](../Includes_and_Autodocs_2._guide/node043D.html) function is similar to the [TextExtent()](../Includes_and_Autodocs_2._guide/node0483.html) function.  It
fills in a [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line164) structure that describes the bounding box of the
largest possible single character in a particular open font, including the
effects of kerning.  Because the FontExtent() function looks at an open
[TextFont](../Libraries_Manual_guide/node03DE.html) structure rather than a rastport to figure out values of the
TextExtent structure, it cannot consider the effects of algorithmic
styling.  Like TextExtent(), FontExtent() was introduced in Release 2, so
it is not available under the 1.3 or earlier OS releases.

The [TextFit()](../Includes_and_Autodocs_2._guide/node0484.html) function looks at a string and returns the number of
characters of the string that will fit into a given rectangular bounds.
TextFit() takes the current rastport rendering settings into consideration
when measuring the text.  Its parameters (from the prototype above) are:


```c
    my_rp                  tells which rastport to get the rendering
                           attributes from

    mystring               the string to "fit"

    strLen                 number of characters of mystring to "fit"

    constrainingExtent     a [TextExtent](../Includes_and_Autodocs_2._guide/node00A8.html#line164) describing the bounding
                           box in which to "fit" mystring

    strDirection           the offset to add to the string pointer to get
                           to the next character in mystring (can be
                           negative)

    constrainingBitWidth   an alternative way to specify the width of the
                           bounding box in which to "fit" mystring

    constrainingBitHeight  an alternative way to specify the height of the
                           bounding box in which to "fit" mystring
```
[TextFit()](../Includes_and_Autodocs_2._guide/node0484.html) will only pay attention to the constrainingBitWidth and
constrainingBitHeight fields if constrainingExtent is NULL.

 [Text Measuring Example](../Libraries_Manual_guide/node05B8.html) 

