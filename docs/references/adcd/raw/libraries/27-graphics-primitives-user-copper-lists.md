# 27 Graphics Primitives / User Copper Lists


The Copper coprocessor allows you to produce mid-screen changes in certain
hardware registers in addition to changes that the system software already
provides.  For example, it is the Copper that allows the Amiga to split
the viewing area into multiple draggable screens, each with its own
independent set of colors.

To create your own mid-screen effects on the system hardware registers,
you provide "user Copper lists" that can be merged into the system Copper
lists.

In the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) data structure there is a pointer named UCopIns.  If this
pointer value is non-NULL, it points to a user Copper list that you have
dynamically allocated and initialized to contain your own special
hardware-stuffing instructions.

You allocate a user Copper list by an instruction sequence such as the
following:


```c
    struct UCopList *uCopList = NULL;

    /* Allocate memory for the Copper list.  Make certain that the */
    /* initial memory is cleared.                                  */
    uCopList = (struct UCopList *)
            AllocMem(sizeof(struct UCopList), MEMF_PUBLIC|MEMF_CLEAR);

    if (uCopList == NULL)
            return(FALSE);


    Note:
    -----
     User Copper lists do not have to be in Chip RAM.
```
 [Copper List Macros](../Libraries_Manual_guide/node036B.html)    [Copper List Example](../Libraries_Manual_guide/node059E.html) 

