# graphics.library/MrgCop



   NAME

       MrgCop -- Merge together coprocessor instructions.
   SYNOPSIS

```c
       error = MrgCop( [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) )
       d0              A1
```
	ULONG MrgCop( struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) * );

   FUNCTION

```c
       Merge together the display, color, sprite and user coprocessor
       instructions into a single coprocessor instruction stream.  This
       essentially creates a per-display-frame program for the coprocessor.
       This function MrgCop is used, for example, by the graphics animation
       routines which effectively add information into an essentially
       static background display.  This changes some of the user
       or sprite instructions, but not those which have formed the
       basic display in the first place.  When all forms of coprocessor
       instructions are merged together, you will have a complete per-
       frame instruction list for the coprocessor.

       Restrictions:  Each of the coprocessor instruction lists MUST be
       internally sorted in min to max Y-X order.  The merge routines
       depend on this! Each list must be terminated using CEND(copperlist).
```
   INPUTS

```c
       [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) - a pointer to the view structure whose coprocessor
              instructions are to be merged.
```
   RESULT

```c
       The view structure will now contain a complete, sorted/merged
       list of instructions for the coprocessor, ready to be used by
       the display processor.  The display processor is told to use
       this new instruction stream through the instruction [LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html).
```
	From V39, MrgCop() can return a ULONG error value (previous versions
	returned void), to indicate that either there was insufficient memory
	to build the system copper lists, or that MrgCop() had no work to do
	if, for example, there were no ViewPorts in the list.

	You should check for these error values - they are defined in
	[<graphics/view.h>](../Includes_and_Autodocs_3._guide/node05ED.html).

   BUGS

   SEE ALSO
```c
       [InitVPort()](../Includes_and_Autodocs_3._guide/node02FA.html) [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) [LoadView()](../Includes_and_Autodocs_3._guide/node02FD.html) [graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)
```
	[intuition.library/RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html)

