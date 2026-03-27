# graphics.library/GetRGB4



   NAME

```c
       GetRGB4 -- Inquire value of entry in [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).
```
   SYNOPSIS

```c
       value = GetRGB4( colormap, entry )
          d0              a0       d0
```
	ULONG GetRGB4(struct [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) *, LONG);

   FUNCTION
	[Read](../Includes_and_Autodocs_3._guide/node01A0.html) and format a value from the [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142).

   INPUTS
	colormap - pointer to [ColorMap](../Includes_and_Autodocs_3._guide/node05ED.html#line142) structure
	entry - index into colormap

   RESULT
	returns -1 if no valid entry
	return [UWORD](../Includes_and_Autodocs_3._guide/node0654.html#line43) RGB value 4 bits per gun right justified

   NOTE
	Intuition's [DisplayBeep()](../Includes_and_Autodocs_3._guide/node03A4.html) changes color 0. Reading Color 0 during a
	[DisplayBeep()](../Includes_and_Autodocs_3._guide/node03A4.html) will lead to incorrect results.

   BUGS

   SEE ALSO

```c
       [SetRGB4()](../Includes_and_Autodocs_3._guide/node032A.html) [LoadRGB4()](../Includes_and_Autodocs_3._guide/node02FC.html) [GetColorMap()](../Includes_and_Autodocs_3._guide/node02E3.html) [FreeColorMap()](../Includes_and_Autodocs_3._guide/node02D7.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
