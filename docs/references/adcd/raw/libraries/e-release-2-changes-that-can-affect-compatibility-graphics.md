# E / Release 2 Changes That Can Affect Compatibility / Graphics


  * Do not rely on the order of Copper list instructions.  The Release 2

```c
    [MrgCop()](../Libraries_Manual_guide/node038E.html) function builds different Copper lists to that of 1.3, by
    including new registers in the list (e.g., MOVE xxxx,DIWHIGH).  This
    changes the positions of  the  other  instructions.  We  know  of one
    game that 'assumes' the BPLxPTRs  would be at a certain offset in the
    Copper list, and that is now broken on machines running 2.0 with the
    new Denise chip.
```
  * Graphics and layers functions which use the blitter generally return

```c
    after starting the final blit.  If you are mixing graphics rendering
    calls and processor access of the same memory, you must [WaitBlit()](../Libraries_Manual_guide/node0368.html)
    before touching (or deallocating) the source or destination memory
    with the processor.  For example, the [Text()](../Libraries_Manual_guide/node03D5.html) function is faster in
    Release 2, causing some programs to trash partial lines of text.
```
  * [ColorMap](../Libraries_Manual_guide/node00F5.html) structure is bigger.  Programs must use [GetColorMap()](../Libraries_Manual_guide/node0331.html) to

    create one.
  * Blitter rtns decide ascend/descend on 1st plane only.

  * Changing the display mode of an existing screen or viewport while

    open is still not a supported operation.
  * [GfxBase DisplayFlags](../Includes_and_Autodocs_2._guide/node00AE.html#line46) and row/cols may not match Workbench screen.

  * Do not hardcode modulo values - use [BitMap->BytesPerRow](../Includes_and_Autodocs_2._guide/node00A6.html#line47).

  * If the graphics Autodocs say that you need a [TmpRas](../Libraries_Manual_guide/node034D.html#line32) of a certain size

```c
    for some functions, then you must make that the minimum size.  In
    some cases, before 2.0, you may have gotten away with using a smaller
    TmpRas with some functions (for example [Flood()](../Libraries_Manual_guide/node035E.html#line9)).  To be more robust,
    graphics now checks the TmpRas size and will fail the function call
    if the TmpRas is too small.
```
  * ECS chips under 2.0 generate displays differently. The display window

    registers now control DMA.
  * [LoadRGB4()](../Libraries_Manual_guide/node0331.html) used to poke colors into the active copperlist with no

```c
    protection against deallocation of that copperlist while it was being
    poked.  Under 2.0, semaphore protection of the copperlist was added
    to LoadRGB4() which makes it totally incorrect and extremely
    dangerous to call LoadRGB4() during an interrupt.  The general
    symptom of this problem is that a system deadlock can be caused by
    dragging one screen up and down while another is cycling.  Color
    cycling should be performed from within a task, not an interrupt.  In
    general, the only functions which may be safely called from within an
    interrupt are the small list of Exec functions documented in the
    "[Exec Interrupts](../Libraries_Manual_guide/node030F.html)" chapter.
```
