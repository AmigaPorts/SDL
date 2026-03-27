# A Register Summary / STREQU, STRHOR, STRLONG, STRVBL


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
STREQU     038      S       D     Strobe for horizontal sync with VB
                                      and EQU
STRHOR     03C      S      D P    Strobe for horizontal sync
STRLONG    03E      S      D( [E](../Hardware_Manual_guide/node00AB.html#line18) ) Strobe for identification of long

```c
                                      horizontal line

                 One of the first three strobe addresses above is
                 placed on the destination address bus during the
                 first refresh time slot.  The fourth strobe shown
                 above is used during the second refresh time slot of
                 every other line to identify lines with long counts
                 (228).  There are four refresh time slots, and any
                 not used for strobes will leave a null (FF) address
                 on the destination address bus.
```
STRVBL     03A      S       D     Strobe for horizontal sync with VB

```c
                                  (vertical blank)
```
