---
title: 28 / / / Linking the AnimComp Sequences to the AnimOb
manual: libraries
chapter: libraries
section: 28-linking-the-animcomp-sequences-to-the-animob
functions: []
libraries: []
---

# 28 / / / Linking the AnimComp Sequences to the AnimOb

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Within each [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md) there may be one or more [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) sequences.  The
[HeadComp](libraries/28-animation-with-gels-animation-data-structures.md) of the AnimOb points to the first AnimComp in the list of
sequences.

Each sequence is identified by its "active" [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md).  There can only be
one active AnimComp in each sequence.  The sequences are linked together
by their active AnimComps; for each of these the [NextComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) and [PrevComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md)
fields link the sequences together to create a list.  The first sequence
in the list ([HeadComp](libraries/28-animation-with-gels-animation-data-structures.md) of the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)), has its PrevComp set to NULL.  The
last sequence in the list has its NextComp set to NULL.  None of the
inactive AnimComps should have NextComp or PrevComp fields set.

To find the active [AnimComp](libraries/28-animation-with-gels-animation-data-structures.md) at run time, you can look in the [AnimOb](libraries/28-animation-with-gels-animation-data-structures.md)'s
[HeadComp](libraries/28-animation-with-gels-animation-data-structures.md) field.  To find the active AnimComp from any another AnimComp,
use the [HeadOb](libraries/28-animation-with-gels-animation-data-structures.md) field to find the controlling AnimOb first and then look in
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
