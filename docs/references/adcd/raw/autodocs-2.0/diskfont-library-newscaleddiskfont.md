# diskfont.library/NewScaledDiskFont



NAME

```c
     NewScaledDiskFont -- Create a DiskFont scaled from another. (V36)
```
SYNOPSIS

```c
     header = NewScaledDiskFont(srcFont, destTextAttr)
     D0                         A0       A1

     struct [DiskFontHeader](../Includes_and_Autodocs_2._guide/node0102.html#line63) *NewScaledDiskFont( struct [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) *,
             struct [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73) * );
```
INPUTS

```c
     srcFont - the font from which the scaled font is to be
         constructed.
     destTextAttr - the desired attributes for the new scaled
         font.  This may be a structure of type [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) or
         [TTextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line73).
```
RESULT

```c
     header - a pointer to a [DiskFontHeader](../Includes_and_Autodocs_2._guide/node0102.html#line63) structure.  This is not
             being managed by the diskfont.library, however.
```
NOTES

```c
     o   This function may use the blitter.
     o   Fonts containing characters that render wholly outside
         the character advance cell are currently not scalable.
     o   The font, and memory allocated for the scaled font can
         can be freed by calling [StripFont()](../Includes_and_Autodocs_2._guide/node0480.html) on the font,
         and then calling [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html) on the segment created
         by this function.

         Both the [TextFont](../Includes_and_Autodocs_2._guide/node00A8.html#line90) structure, and segment pointer are contained
         within the [DiskFontHeader](../Includes_and_Autodocs_2._guide/node0102.html#line63) struct.  The [DiskFontHeader](../Includes_and_Autodocs_2._guide/node0102.html#line63) structure
         will also be freed as part of the [UnLoadSeg()](../Includes_and_Autodocs_2._guide/node0306.html) call.
         [StripFont()](../Includes_and_Autodocs_2._guide/node0480.html) is a new graphics.library call as of V36.
```
