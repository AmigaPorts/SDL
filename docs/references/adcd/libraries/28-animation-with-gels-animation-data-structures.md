---
title: 28 / Animation with GELs / Animation Data Structures
manual: libraries
chapter: libraries
section: 28-animation-with-gels-animation-data-structures
functions: []
libraries: []
---

# 28 / Animation with GELs / Animation Data Structures

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There are two main data structures involved in Amiga animation: AnimComp
and AnimOb.

The [AnimComp](autodocs-2.0/includes-graphics-gels-h.md) (Animation Component), is an extension of the [Bob](libraries/28-using-bobs-the-bob-structure.md) structure
discussed in the [previous section](libraries/28-adding-user-extensions-to-gel-data-structures.md).  An AnimComp provides a convenient way
to link together a series of images so that they can be sequenced
automatically, and so multiple sequences can be grouped together.  An
AnimComp is analogous to one sheet of celluloid representing a single
image to be placed over the background.


```c
    struct AnimComp
    {
        WORD Flags;                 /* AnimComp flags for system & user */
        WORD Timer;
        WORD TimeSet;
        struct AnimComp  *NextComp;
        struct AnimComp  *PrevComp;
        struct AnimComp  *NextSeq;
        struct AnimComp  *PrevSeq;
        WORD (*AnimCRoutine)();
        WORD YTrans;
        WORD XTrans;
        struct AnimOb    *HeadOb;
                           /* Pointer back to the controlling AnimOb */
        struct Bob       *AnimBob;
                           /* Underlying Bob structure for this AnimComp */
    };
```
The AnimComp structure contains pointers, [PrevSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md) and [NextSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md), that lets
you group these cells into stacks that will be viewed sequentially.  The
AnimComp structure also has [PrevComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) and [NextComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) pointers that let you
group stacks into complex objects containing multiple independently moving
parts.

The second animation data structure is the [AnimOb](autodocs-2.0/includes-graphics-gels-h.md) which provides the
variables needed for overall control over a group of AnimComps.  The
AnimOb itself contains no imagery; it simply provides a common reference
point for the sequenced images and specifies how the system should move
that point.


```c
    struct AnimOb
    {
        struct AnimOb    *NextOb, *PrevOb;
        LONG Clock;
        WORD AnOldY, AnOldX;            /* old y,x coordinates          */
        WORD AnY, AnX;                  /* y,x coordinates of the AnimOb*/
        WORD YVel, XVel;                /* velocities of this object    */
        WORD YAccel, XAccel;            /* accelerations of this object */
        WORD RingYTrans, RingXTrans;    /* ring translation values      */
        WORD (*AnimORoutine)();         /* address of user procedure    */
        struct AnimComp  *HeadComp;     /* pointer to first component   */
        AUserStuff AUserExt;            /* AnimOb user extension        */
    };
```
These structures can be used in various ways.  A simple animation of a
rotating ball could be created with three or four AnimComps linked
together in a circular list by their [NextSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md) and [PrevSeq](libraries/28-specifying-animation-components-sequencing-animcomps.md) fields.  The
system displays the initial AnimComp (the "top of the stack"), then
switches to the AnimComp pointed to by NextSeq, and then switches to its
NextSeq and so on until it reaches the end of the sequence.  The sequence
starts over again automatically if the last AnimComp.NextSeq points back
to the first AnimComp in the stack.

For a more complex animation of a walking human, you could use five
stacks, i.e., five circular lists of AnimComps; four stacks for the arms
and legs and a single stack for the head and torso.  To group these stacks
into one cohesive unit showing a human figure, you use the [PrevComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) and
[NextComp](libraries/28-animation-components-linking-multiple-animcomp-sequences.md) pointers in the AnimComp structure.  All the stacks would also
share a common AnimOb, so that the combined sequences can be moved as a
single object.


```c
     [Figure 28-4: Linking AnimComps For a Multiple Component AnimOb](libraries/lib-pics-28-4-pic.md) 
```
