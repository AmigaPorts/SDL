# 29 Graphics Library and Text / The Text Function


Amiga text rendering is centered around the graphics.library function
[Text()](../Includes_and_Autodocs_2._guide/node0482.html), which renders text into a rastport:


```c
    void Text( struct RastPort *myrp, STRPTR mystring, ULONG count );
```
where myrp is a pointer to the target rastport, mystring is the string to
render, and count is the number of characters of mystring to render.
[Text()](../Includes_and_Autodocs_2._guide/node0482.html) renders at the current rastport position and it takes care of
moving the rastport's current X position as it renders each letter.
Text() only renders text horizontally, so repositioning the rastport's Y
position (for example, for a new line) is the responsibility of the
application.  This is covered in [more detail](../Libraries_Manual_guide/node03D8.html#line10) later in this chapter.

Like the other rastport based graphics primitives, most of the text
rendering attributes are specified within the [RastPort](../Libraries_Manual_guide/node034A.html) structure itself.
The current position, the color of the text, and even the font itself are
all specified in the RastPort structure.

 [Choosing the Font](../Libraries_Manual_guide/node03D6.html)                      [Rendering the Text](../Libraries_Manual_guide/node03D8.html) 
 [Setting the Text Drawing Attributes](../Libraries_Manual_guide/node03D7.html)    [Setting the Font Style](../Libraries_Manual_guide/node03D9.html) 

