# 27 / / Loading and Displaying the View / Exiting Gracefully


The preceding sample program provides a way of exiting gracefully with the
cleanup() subroutine.  This function returns to the memory manager all
dynamically-allocated memory chunks.  Notice the calls to [FreeRaster()](../Includes_and_Autodocs_2._guide/node0442.html) and
[FreeColorMap()](../Includes_and_Autodocs_2._guide/node043E.html). These calls correspond directly to the allocation calls
[AllocRaster()](../Libraries_Manual_guide/node032E.html) and [GetColorMap()](../Libraries_Manual_guide/node0331.html) located in the body of the program. Now
look at the calls within cleanup() to [FreeVPortCopLists()](../Includes_and_Autodocs_2._guide/node0444.html) and
[FreeCprList()](../Includes_and_Autodocs_2._guide/node0440.html). When you call [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9), the graphics system dynamically
allocates some space to hold intermediate instructions from which a final
Copper instruction list is created. When you call [MrgCop()](../Libraries_Manual_guide/node0332.html#line27), these
intermediate Copper lists are merged together into the final Copper list,
which is then given to the hardware for interpretation. It is this list
that provides the stable display on the screen, split into separate
[ViewPort](../Libraries_Manual_guide/node032B.html#line59)s with their own colors and resolutions and so on.

When your program completes, you must see that it returns all of the
memory resources that it used so that those memory areas are again
available to the system for reassignment to other tasks.  Therefore, if
you use the routines [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9) or [MrgCop()](../Libraries_Manual_guide/node0332.html#line27), you must also arrange to use
[FreeCprList()](../Includes_and_Autodocs_2._guide/node0440.html) (pointing to each of those lists in the [View](../Libraries_Manual_guide/node032B.html#line51) structure) and
[FreeVPortCopLists()](../Includes_and_Autodocs_2._guide/node0444.html) (pointing to the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) that is about to be
deallocated).  If your View is interlaced, you will also have to call
FreeCprList(&view.SHFCprList) because an interlaced view has a separate
Copper list for each of the two fields displayed. Do not confuse
FreeVPortCopLists() with FreeCprList(). The former works on intermediate
Copper lists for a specific ViewPort, the latter directly on a hardware
Copper list from the View.

As a final caveat, notice that when you do free everything, the memory
manager or other programs may immediately change the contents of the freed
memory.  Therefore, if the Copper is still executing an instruction stream
(as a result of a previous [LoadView()](../Libraries_Manual_guide/node0333.html)) when you free that memory, the
display will malfunction. Once another [View](../Libraries_Manual_guide/node032B.html#line51) has been installed via
LoadView(), do a [WaitTOF()](../Libraries_Manual_guide/node0390.html) for the new View to begin displaying, and then
you can begin freeing up your resources.  WaitTOF() waits for the vertical
blanking period to begin and all vertical blank interrupts to complete
before returning to the caller. The routine [WaitBOVP()](../Includes_and_Autodocs_2._guide/node048A.html) (for
"WaitBottomOfViewPort") busy waits until the vertical beam reaches the
bottom of the specified [ViewPort](../Libraries_Manual_guide/node032B.html#line59) before returning to the caller.  This
means no other tasks run until this function returns.

