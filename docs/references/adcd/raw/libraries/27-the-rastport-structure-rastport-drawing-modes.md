# 27 / / The RastPort Structure / RastPort Drawing Modes


Four drawing modes may be specified in the [RastPort](../Libraries_Manual_guide/node034A.html).DrawMode field:

JAM1

```c
    Whenever you execute a graphics drawing command, one color is jammed
    into the target drawing area. You use only the primary drawing pen
    color, and for each pixel drawn, you replace the color at that
    location with the [FgPen](../Libraries_Manual_guide/node0350.html#line3) color.
```
JAM2

```c
    Whenever you execute a graphics drawing command, two colors are
    jammed into the target drawing area. This mode tells the system that
    the pattern variables (both line pattern and area pattern--see
    the [next section](../Libraries_Manual_guide/node0352.html)) are to be used for the drawing. Wherever there is a
    1 bit in the pattern variable, the [FgPen](../Libraries_Manual_guide/node0350.html#line3) color replaces the color of
    the pixel at the drawing position. Wherever there is a 0 bit in the
    pattern variable, the [BgPen](../Libraries_Manual_guide/node0350.html#line6) color is used.
```
COMPLEMENT

    For each 1 bit in the pattern, the corresponding bit in the target
    area is complemented--that is, its state is reversed. As with all
    other drawing modes, the write mask can be used to protect specific
    bitplanes from being modified. Complement mode is often used for
    drawing and then erasing lines.
INVERSVID

```c
    This is the drawing mode used primarily for text. If the drawing mode
    is (JAM1 | INVERSVID), the text appears as a transparent letter
    surrounded by the [FgPen](../Libraries_Manual_guide/node0350.html#line3) color. If the drawing mode is
    (JAM2|INVERSVID), the text appears as in (JAM1|INVERSVID) except that
    the [BgPen](../Libraries_Manual_guide/node0350.html#line6) color is used to draw the text character itself. In this
    mode, the roles of FgPen and BgPen are effectively reversed.
```
You set the drawing modes using the statement:


```c
    SetDrMd(&rastPort, newmode);
```
Set the newmode argument to one of the four drawing modes listed above.

