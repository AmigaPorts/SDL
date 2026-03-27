# 27 / Advanced Topics / Creating a Double-Buffered Display


To produce smooth animation or similar effects, it is occasionally
necessary to double-buffer your display.  To prevent the user from seeing
your graphics rendering while it is in progress, you will want to draw
into one memory area while actually displaying a different area.

There are two methods of creating and displaying a double-buffered
display.  The simplest method is to create two complete Views and switch
back and forth between them with [LoadView()](../Libraries_Manual_guide/node0333.html) and [WaitTOF()](../Libraries_Manual_guide/node0390.html).

The second method consists of creating two separate display areas and two
sets of pointers to those areas for a single [View](../Libraries_Manual_guide/node032B.html#line51).  This is more
complicated but takes less memory.

  * Allocate one [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure and one [View](../Libraries_Manual_guide/node032B.html#line51) structure.

  * Allocate two [BitMap](../Libraries_Manual_guide/node032B.html#line74) structures and one [RasInfo](../Libraries_Manual_guide/node032B.html#line69) structure. Initialize

```c
    each BitMap structure to describe one drawing area and allocate
    memory for the bitplanes themselves. Initialize the RasInfo
    structure, setting the [RasInfo.BitMap](../Includes_and_Autodocs_2._guide/node00B8.html#line106) field to the address of one of
    the two BitMaps you created.
```
  * Call [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9), [MrgCop()](../Libraries_Manual_guide/node0332.html#line27) and [LoadView()](../Libraries_Manual_guide/node0333.html). When you call MrgCop(),

```c
    the system uses the information you have provided to create a Copper
    instruction list for the Copper to execute.  The system allocates
    memory for a long-frame (LOF) Copper list and, if this is an
    interlaced display, a short-frame (SHF) Copper list as well.  The
    system places a pointer to the long-frame Copper list in
    [View.LOFCprList](../Includes_and_Autodocs_2._guide/node00B8.html#line57) and a pointer to a short-frame Copper list (if this
    is an interlaced display) in [View.SHFCprList](../Includes_and_Autodocs_2._guide/node00B8.html#line57).  The Copper instruction
    stream referenced by these pointers applies to the first [BitMap](../Libraries_Manual_guide/node032B.html#line74).
```
  * Save the values in [View.LOFCprList](../Includes_and_Autodocs_2._guide/node00B8.html#line57) and [View.SHFCprlist](../Includes_and_Autodocs_2._guide/node00B8.html#line57) and reset

```c
    these fields to zero.  Place a pointer to the second [BitMap](../Libraries_Manual_guide/node032B.html#line74) structure
    in the [RasInfo.BitMap](../Includes_and_Autodocs_2._guide/node00B8.html#line40) field.  Next call [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9) and [MrgCop()](../Libraries_Manual_guide/node0332.html#line27).
```
  * When you perform [MrgCop()](../Libraries_Manual_guide/node0332.html#line27) with the Copper instruction list fields of

```c
    the [View](../Libraries_Manual_guide/node032B.html#line51) set to zero, the system automatically allocates and fills in
    a new list of instructions for the Copper.  Now you have created two
    sets of instruction streams for the Copper, one that works with data
    in the first [BitMap](../Libraries_Manual_guide/node032B.html#line74) and the other that works with data in the second
    BitMap.
```
  * You can save pointers to the second list of Copper instructions as

```c
    well.  Then, to perform the double-buffering, alternate between the
    two Copper lists.  The code for the double-buffering loop would be as
    follows: call [WaitTOF()](../Libraries_Manual_guide/node0390.html), change the Copper instruction list pointers
    in the [View](../Libraries_Manual_guide/node032B.html#line51), call [LoadView()](../Libraries_Manual_guide/node0333.html) to show one of the [BitMap](../Libraries_Manual_guide/node032B.html#line74)s while drawing
    into the other BitMap, and repeat.
```
Remember that you will have to call [FreeCprList()](../Libraries_Manual_guide/node0334.html) on both sets of Copper
lists when you have finished.

