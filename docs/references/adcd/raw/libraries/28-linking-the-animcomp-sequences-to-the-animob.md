# 28 / / / Linking the AnimComp Sequences to the AnimOb


Within each [AnimOb](../Libraries_Manual_guide/node03B9.html#line34) there may be one or more [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) sequences.  The
[HeadComp](../Libraries_Manual_guide/node03B9.html#line50) of the AnimOb points to the first AnimComp in the list of
sequences.

Each sequence is identified by its "active" [AnimComp](../Libraries_Manual_guide/node03B9.html#line3).  There can only be
one active AnimComp in each sequence.  The sequences are linked together
by their active AnimComps; for each of these the [NextComp](../Libraries_Manual_guide/node03C2.html) and [PrevComp](../Libraries_Manual_guide/node03C2.html)
fields link the sequences together to create a list.  The first sequence
in the list ([HeadComp](../Libraries_Manual_guide/node03B9.html#line50) of the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34)), has its PrevComp set to NULL.  The
last sequence in the list has its NextComp set to NULL.  None of the
inactive AnimComps should have NextComp or PrevComp fields set.

To find the active [AnimComp](../Libraries_Manual_guide/node03B9.html#line3) at run time, you can look in the [AnimOb](../Libraries_Manual_guide/node03B9.html#line34)'s
[HeadComp](../Libraries_Manual_guide/node03B9.html#line50) field.  To find the active AnimComp from any another AnimComp,
use the [HeadOb](../Libraries_Manual_guide/node03B9.html#line22) field to find the controlling AnimOb first and then look in
its HeadComp field to find the active AnimComp.

The figure below shows all the linkages in data structures needed to
create the animation GELs.

  ___________________
 |                   |
 |    Next AnimOb    |
 |___________________|
 |                   |
 |  Previous AnimOb  |                                  Non-Current
 |___________________|          Original                -----------
 |                   |          --------             Additional views
 | \\\\\\\\\\\\\\\\\ |        (first view)          of each component,
 | \\\\\\\\\\\\\\\\\ |        of an AnimOb          waiting to be used.
 |___________________|     ___________________      _ _ _ _ _ _ _ _ _ _
 |                   |----|                   |    |                   |
 |     HeadComp      |  _\|   Next AnimComp   |__  |   Next AnimComp   |
 |___________________| | /|___________________|  | |_ _ _ _ _ _ _ _ _ _|

                       |  |                   |  | |                   |
                       |  | Previous AnimComp |  | | Previous AnimComp |
                       |  |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                       |  |                   |  | |                   |
                       |  | Sequence Linkage  |--|-| Sequence linkage  |--
                       |  |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                       |  |                   |  | |                   |
                       |  | \\\\\\\\\\\\\\\\\ |  | | \\\\\\\\\\\\\\\\\ |
                       |  |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                       |                         |
                       |                         |
                       |   ___________________   |  _ _ _ _ _ _ _ _ _ _
                       |  |                   |/_| |                   |
                      _|_\|   Next AnimComp   |\   |   Next AnimComp   |
                     | | /|___________________|--. |_ _ _ _ _ _ _ _ _ _|
                     | |  |                   |  | |                   |
                     | |__| Previous AnimComp |  | | Previous AnimComp |
                     |    |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                     |    |                   |  | |                   |
                     |    | Sequence Linkage  |--|-| Sequence linkage  |--
                     |    |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                     |    |                   |  | |                   |
                     |    | \\\\\\\\\\\\\\\\\ |  | | \\\\\\\\\\\\\\\\\ |
                     |    |___________________|  | |_ _ _ _ _ _ _ _ _ _|
                     |                           |
                     |                           |
                     |     ___________________   |  _ _ _ _ _ _ _ _ _ _
                     |    |                   |/_| |                   |
                     |    |   Next AnimComp   |\   |   Next AnimComp   |
                     |    |___________________|    |_ _ _ _ _ _ _ _ _ _|
                     |    |                   |    |                   |
                     |____| Previous AnimComp |    | Previous AnimComp |
                          |___________________|    |_ _ _ _ _ _ _ _ _ _|
                          |                   |    |                   |
                          | Sequence Linkage  |----| Sequence linkage  |--
                          |___________________|    |_ _ _ _ _ _ _ _ _ _|
                          |                   |    |                   |
                          | \\\\\\\\\\\\\\\\\ |    | \\\\\\\\\\\\\\\\\ |
                          |___________________|    |_ _ _ _ _ _ _ _ _ _|


                    Figure 28-6: Linking of an AnimOb
