# 28 / / Animation Components / Linking Multiple AnimComp Sequences


When an [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) is built from multiple [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) sequences, the sequences
are linked together by the the [PrevComp](../Includes_and_Autodocs_2._guide/node00C3.html#line186) and [NextComp](../Includes_and_Autodocs_2._guide/node00C3.html#line186) fields of the
AnimComps.  These pointers must be initialized only in the initial
AnimComp of each sequence.  The other components that are not initially
active should have their PrevComp and NextComp pointers set to NULL.


```c
    Do Not Use Empty Fields.
    ------------------------
    You cannot store data in the empty [PrevComp](../Includes_and_Autodocs_2._guide/node00C3.html#line186) and [NextComp](../Includes_and_Autodocs_2._guide/node00C3.html#line186) fields.  As
    the system cycles through the [AnimComp](../Libraries_Manual_guide/node03B9.html#line3)s, the NextComp and PrevComp
    fields are set to NULL when an old AnimComps is replaced by a new
    AnimComp.  The new AnimComp is then linked in to the list of
    sequences in place of the old one.
```
