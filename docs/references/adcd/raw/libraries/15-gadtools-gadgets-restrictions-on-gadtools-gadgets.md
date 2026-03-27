# 15 / GadTools Gadgets / Restrictions on GadTools Gadgets


There is a strict set of functions and operations that are permitted on
GadTools gadgets.  Even if a technique is discovered that works for a
particular case, be warned that it cannot be guaranteed and should not be
used.  If the trick concocted only works most of the time, it may
introduce subtle problems in the future.

Never selectively or forcibly refresh gadgets.  The only gadget refresh
that should ever be performed is the initial [GT_RefreshWindow()](../Libraries_Manual_guide/node026F.html#line5) after a
window is opened with GadTools gadgets attached.  It is also possible to
add gadgets after the window is opened by calling AddGlist() and
RefreshGlist() followed by GT_RefreshWindow().  These refresh functions
should not be called at any other time.

GadTools gadgets may not overlap with each other, with other gadgets or
with other imagery.  Doing this to modify the gadget's appearance is not
supported.

GadTools gadgets may not be selectively added or removed from a window.
This has to do with the number of Intuition gadgets that each call to
[CreateGadget()](../Libraries_Manual_guide/node025A.html) produces and with refresh constraints.

Never use [OnGadget()](../Libraries_Manual_guide/node0147.html#line10) or [OffGadget()](../Libraries_Manual_guide/node0147.html#line10) or directly modify the [GFLG_DISABLED](../Libraries_Manual_guide/node014A.html#line73)
Flags bit.  The only approved way to disable or enable a gadget is to use
[GT_SetGadgetAttrs()](../Libraries_Manual_guide/node025E.html) and the GA_Disabled tag.  Those kinds of GadTools
gadgets that do not support GA_Disabled may not be disabled (for now).

The application should never write into any of the fields of the [Gadget](../Libraries_Manual_guide/node0149.html)
structure or any of the structures that hang off it, with the exception
noted earlier for [GENERIC_KIND](../Libraries_Manual_guide/node026A.html) gadgets.  Avoid making assumptions about
the contents of these fields unless they are explicitly programmer fields
([GadgetID](../Libraries_Manual_guide/node0149.html#line137) and [UserData](../Libraries_Manual_guide/node0149.html#line142), for example) or if they are guaranteed meaningful
([LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [TopEdge](../Libraries_Manual_guide/node0149.html#line33), [Width](../Libraries_Manual_guide/node0149.html#line33), [Height](../Libraries_Manual_guide/node0149.html#line33), [Flags](../Libraries_Manual_guide/node0149.html#line33)).  On occasion, the program is
specifically invited to read a field, for example the [StringInfo->Buffer](../Libraries_Manual_guide/node016B.html#line19)
field.

GadTools gadgets may not be made relative sized or relative positioned.
This means that the gadget flags [GFLG_RELWIDTH](../Libraries_Manual_guide/node014A.html#line47), [GFLG_RELHEIGHT](../Libraries_Manual_guide/node014A.html#line55),
[GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29) and [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38) may not be specified.  The activation
type of the gadget may not be modified (for example changing
[GACT_IMMEDIATE](../Libraries_Manual_guide/node014B.html#line9) to [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14)).  The imagery or the highlighting method
may not be changed.

These restrictions are not imposed without reason; subtle or blatant
problems may arise now or in future versions of GadTools for programs that
violate these guidelines.

