---
title: 29 Graphics Library and Text / The Text Function
manual: libraries
chapter: libraries
section: 29-graphics-library-and-text-the-text-function
functions: [Text]
libraries: [graphics.library]
---

# 29 Graphics Library and Text / The Text Function

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Amiga text rendering is centered around the graphics.library function
[Text()](autodocs-2.0/graphics-library-text.md), which renders text into a rastport:


```c
    void Text( struct RastPort *myrp, STRPTR mystring, ULONG count );
```
where myrp is a pointer to the target rastport, mystring is the string to
render, and count is the number of characters of mystring to render.
[Text()](autodocs-2.0/graphics-library-text.md) renders at the current rastport position and it takes care of
moving the rastport's current X position as it renders each letter.
Text() only renders text horizontally, so repositioning the rastport's Y
position (for example, for a new line) is the responsibility of the
application.  This is covered in [more detail](libraries/29-the-text-function-rendering-the-text.md) later in this chapter.

Like the other rastport based graphics primitives, most of the text
rendering attributes are specified within the [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure itself.
The current position, the color of the text, and even the font itself are
all specified in the RastPort structure.

 [Choosing the Font](libraries/29-the-text-function-choosing-the-font.md)                      [Rendering the Text](libraries/29-the-text-function-rendering-the-text.md) 
 [Setting the Text Drawing Attributes](libraries/29-the-text-function-setting-the-text-drawing-attributes.md)    [Setting the Font Style](libraries/29-the-text-function-setting-the-font-style.md) 

---

## See Also

- [Text — graphics.library](../autodocs/graphics.library.md#text)
