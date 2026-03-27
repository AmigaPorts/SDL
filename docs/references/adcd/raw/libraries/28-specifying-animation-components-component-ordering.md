# 28 / / Specifying Animation Components / Component Ordering


The [PrevSeq](../Libraries_Manual_guide/node03BF.html), [NextSeq](../Libraries_Manual_guide/node03BF.html), [PrevComp](../Libraries_Manual_guide/node03C2.html) and [NextComp](../Libraries_Manual_guide/node03C2.html) linkages have no bearing on
the order in which [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)s in any given video frame are drawn.  To
specify the inter-component priorities (so that the closest objects appear
frontmost) the [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html) pointers in the initially active
AnimComp's underlying [Bob](../Libraries_Manual_guide/node0398.html) structure are linked in to the rest of the
system, as described previously in the discussion of Bobs.

This setup needs to be done once, for the initially active [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)s of
the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) only.

The animation system adjusts the [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html) pointers of all the
underlying [Bob](../Libraries_Manual_guide/node0398.html) structures to constantly maintain the inter-component
drawing sequence, even though different components are being made active
as sequencing occurs.

These pointers also assure that one complete object always has priority
over another object. The [Bob](../Libraries_Manual_guide/node0398.html) [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html) pointers are used to link
together the last [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)'s Bob of one [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) to the first AnimComp's Bob
of the next AnimOb.

