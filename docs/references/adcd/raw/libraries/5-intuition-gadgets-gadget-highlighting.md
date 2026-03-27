# 5 Intuition Gadgets / Gadget Highlighting


In general, the appearance of an active or selected gadget changes to
inform the user the gadget state has changed.  A highlighting method is
specified by setting one of the highlighting flags in the [Gadget](../Libraries_Manual_guide/node0149.html)
structure's [Flags](../Libraries_Manual_guide/node0149.html#line48) field.

Intuition supports three methods of activation or selection highlighting:

  * Highlighting by color complementing ([GFLG_GADGHCOMP](../Libraries_Manual_guide/node014A.html#line8))

  * Highlighting by drawing a box ([GFLG_GADGHBOX](../Libraries_Manual_guide/node014A.html#line12))

  * Highlighting by an alternate image or border ([GFLG_GADGHIMAGE](../Libraries_Manual_guide/node014A.html#line16))

  * No highlighting ([GFLG_GADGHNONE](../Libraries_Manual_guide/node014A.html#line5))

One of the highlighting types or [GFLG_GADGHNONE](../Libraries_Manual_guide/node014A.html#line5) must be specified for each
gadget.

 [Highlighting by Color Complementing](../Libraries_Manual_guide/node013F.html) 
 [Highlighting by Drawing a Box](../Libraries_Manual_guide/node0140.html) 
 [Highlighting with an Alternate Image or Alternate Border](../Libraries_Manual_guide/node0141.html) 

