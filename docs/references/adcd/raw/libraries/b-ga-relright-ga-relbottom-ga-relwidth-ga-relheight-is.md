# B / / GA_RelRight, GA_RelBottom, GA_RelWidth, GA_RelHeight (IS)


These attributes correspond to the [Gadget](../Libraries_Manual_guide/node0149.html) structure's [LeftEdge](../Libraries_Manual_guide/node0149.html#line33), [TopEdge](../Libraries_Manual_guide/node0149.html#line33),
[Width](../Libraries_Manual_guide/node0149.html#line33), and [Height](../Libraries_Manual_guide/node0149.html#line33) fields.  Setting any of these attributes also sets the
corresponding "relative" flag in the Gadget structure's [Flags](../Libraries_Manual_guide/node0149.html#line48) field
(respectively, [GFLG_RELRIGHT](../Libraries_Manual_guide/node014A.html#line38), [GFLG_RELBOTTOM](../Libraries_Manual_guide/node014A.html#line29), [GFLG_RELWIDTH](../Libraries_Manual_guide/node014A.html#line47), and
[GFLG_RELHEIGHT](../Libraries_Manual_guide/node014A.html#line55)).  Note that the value passed in this attribute is normally
a negative LONG.  See the "[Intuition Gadgets](../Libraries_Manual_guide/node014A.html)" chapter of the Amiga ROM
Kernel Reference Manual: Libraries for more information on these flags.

