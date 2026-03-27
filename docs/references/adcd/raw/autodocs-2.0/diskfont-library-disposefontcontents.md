# diskfont.library/DisposeFontContents



NAME

```c
     DisposeFontContents -- Free the result from [NewFontContents](../Includes_and_Autodocs_2._guide/node01F5.html). (V34)
```
SYNOPSIS

```c
     DisposeFontContents(fontContentsHeader)
                         A1

     VOID DisposeFontContents( struct [FontContentsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line53) * );
```
FUNCTION

```c
     This function frees the array of [FontContents](../Includes_and_Autodocs_2._guide/node0102.html#line29) entries
     returned by [NewFontContents](../Includes_and_Autodocs_2._guide/node01F5.html).
```
INPUTS

```c
     fontContentsHeader - a struct [FontContentsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line53) pointer
         returned by [NewFontContents](../Includes_and_Autodocs_2._guide/node01F5.html).
```
EXCEPTIONS

```c
     This command was first made available as of version 34.

     A fontContentsHeader other than one acquired by a call
     [NewFontContents](../Includes_and_Autodocs_2._guide/node01F5.html) will crash.
```
SEE ALSO

```c
     [NewFontContents](../Includes_and_Autodocs_2._guide/node01F5.html) to get structure freed here.
```
