# 8 / Creating Borders / Border Structure Definition


To use a border, the application must create one or more instances of the
[Border](../Includes_and_Autodocs_2._guide/node00D4.html#line591) structure.  Here is the specification:


```c
    struct Border
        {
        WORD LeftEdge, TopEdge;
        UBYTE FrontPen, BackPen;
        UBYTE DrawMode;
        BYTE Count;
        WORD *XY;
        struct Border *NextBorder;
        };
```
Here is a brief description of the fields of the Border structure.

LeftEdge, TopEdge

```c
    These fields are used to determine the position of the Border
    relative to its base position (the base position is the upper left
    corner for requesters, menus, or gadgets and is specified in the call
    to [DrawBorder()](../Libraries_Manual_guide/node01C2.html) for windows and screens).
```
FrontPen, BackPen

    These fields contain color registers numbers.  FrontPen is the color
    used to draw the lines.  BackPen is currently unused.
DrawMode

    Set the DrawMode field to one of the following:

    JAM1
        Use FrontPen to draw the line.

    COMPLEMENT
        Change the pixels within the lines to their complement color.
Count

    Specify the number of data points used in this border.  Each data
    point is described by two words of data in the XY array.
XY  A pointer to an array of coordinate pairs, one pair for each point.

    These coordinates are measured relative to the position of the border.
NextBorder

    This field is a pointer to another instance of a Border structure.
    Set this field to NULL if this is the last Border structure in the
    linked list.
