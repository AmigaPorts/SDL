# graphics.library/LoadView



   NAME

```c
       LoadView -- Use a (possibly freshly created) coprocessor instruction
                   list to create the current display.
```
   SYNOPSIS

```c
       LoadView( [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) )
                  A1
```
	void LoadView( struct [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) * );

   FUNCTION
	Install a new view to be displayed during the next display
	refresh pass.

```c
       Coprocessor instruction list has been created by
       [InitVPort()](../Includes_and_Autodocs_3._guide/node02FA.html), [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html), and [MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html).
```
   INPUTS

```c
       [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) - a pointer to the [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) structure which contains the
       pointer to the constructed coprocessor instructions list, or NULL.
```
   RESULT
	If the [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) pointer is non-NULL, the new [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) is displayed,
	according to your instructions.  The vertical blank routine
	will pick this pointer up and direct the copper to start
	displaying this [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63).

	If the [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) pointer is NULL, no [View](../Includes_and_Autodocs_3._guide/node05ED.html#line63) is displayed.

   NOTE
	Even though a LoadView(NULL) is performed, display DMA will still be
	active.  Sprites will continue to be displayed after a LoadView(NULL)
	unless an OFF_SPRITE is subsequently performed.

   BUGS

   SEE ALSO
```c
       [InitVPort()](../Includes_and_Autodocs_3._guide/node02FA.html) [MakeVPort()](../Includes_and_Autodocs_3._guide/node02FF.html) [MrgCop()](../Includes_and_Autodocs_3._guide/node0303.html) [intuition/RethinkDisplay()](../Includes_and_Autodocs_3._guide/node03E7.html)
```
	[graphics/view.h](../Includes_and_Autodocs_3._guide/node05ED.html)

