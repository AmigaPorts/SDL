# 28 / / Specifying Animation Components / Sequencing AnimComps


To specify the sequencing of [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) images, the pointers called [PrevSeq](../Includes_and_Autodocs_2._guide/node00C3.html#line190)
and [NextSeq](../Includes_and_Autodocs_2._guide/node00C3.html#line190) are used to build a doubly-linked list.  The sequence can be
made circular (and usually is) by linking the first and last AnimComps in
the sequence: the NextSeq of the last AnimComp must point back to the
first AnimComp, and the PrevSeq of the first AnimComp must point to the
last AnimComp.  If the list is a loop, then the system will continue to
cycle through the list until it is stopped.  If the list is not a loop,
then the program must act to restart the sequence after the last item is
displayed.  The AnimCRoutine field of the last AnimComp can be used to do
this.

