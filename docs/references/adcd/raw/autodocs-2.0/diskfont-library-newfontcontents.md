# diskfont.library/NewFontContents



NAME

```c
     NewFontContents -- Create a [FontContents](../Includes_and_Autodocs_2._guide/node0102.html#line29) image for a font. (V34)
```
SYNOPSIS

```c
     fontContentsHeader = NewFontContents(fontsLock,fontName)
    D0                                   A0        A1

     struct [FontContentsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line53) *NewFontContents( BPTR, char * );
```
FUNCTION

```c
     This function creates a new array of [FontContents](../Includes_and_Autodocs_2._guide/node0102.html#line29) entries
     that describe all the fonts associated with the fontName,
     specifically, all those in the font directory whose name
     is that of the font sans the ".font" suffix.
```
INPUTS

```c
     fontsLock - a DOS lock on the FONTS: directory (or other
         directory where the font contents file and associated
         font directory resides).
     fontName - the font name, with the ".font" suffix, which
         is also the name of the font contents file.
```
RESULT

```c
     fontContentsHeader - a struct [FontContentsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line53) pointer.
```
EXCEPTIONS

     This command was first made available as of version 34.

     D0 is zero if the fontName is does not have a ".font" suffix,
     if the fontName is too long, if a DOS error occurred, or if
     memory could not be allocated for the fontContentsHeader.
SEE ALSO

```c
     [DisposeFontContents](../Includes_and_Autodocs_2._guide/node01F4.html) to free the structure acquired here.
```
