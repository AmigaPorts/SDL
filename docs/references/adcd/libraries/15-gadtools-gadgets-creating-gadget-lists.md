---
title: 15 / GadTools Gadgets / Creating Gadget Lists
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-creating-gadget-lists
functions: [CreateContext]
libraries: [gadtools.library]
---

# 15 / GadTools Gadgets / Creating Gadget Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

In the discussion of [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) presented earlier, the examples showed
only how to make a single gadget.  For most applications that use
GadTools, however, a whole list of gadgets will be needed.  To do this,
the application could use code such as this:


```c
    struct NewGadget *newgad1, *newgad2, *newgad3;
    struct Gadget *glist = NULL;
    struct Gadget *pgad;

    ...
    /* Initialize NewGadget structures */
    ...

    /* Note that CreateContext() requires a POINTER to a NULL-initialized
     * pointer to struct Gadget:
     */
    pgad = CreateContext(&glist);

    pgad = CreateGadget(BUTTON_KIND, pgad, newgad1, TAG_END);
    pgad = CreateGadget(STRING_KIND, pgad, newgad2, TAG_END);
    pgad = CreateGadget(MX_KIND,     pgad, newgad3, TAG_END);

    if (!pgad)
        {
        FreeGadgets(glist);
        exit_error();
        }
    else
        {
        if ( mywin=OpenWindowTags(NULL,
                                  WA_Gadgets,   glist,
                                  ...
                                  /* Other tags... */
                                  ...
                                  TAG_END) )
            {
            /* Complete the rendering of the gadgets */
            GT_RefreshWindow(win, NULL);
            ...
            /* and continue on... */
            ...
            CloseWindow(mywin);
            }

        FreeGadgets(glist);
        }
```
The pointer to the previous gadget, pgad in the code fragment above, is
used for three purposes.  First, when [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) is called multiple
times, each new gadget is automatically linked to the previous gadget's
[NextGadget](libraries/5-intuition-gadgets-gadget-structure.md) field, thus creating a gadget list.  Second, if one of the
gadget creations fails (usually due to low memory, but other causes are
possible), then for the next call to CreateGadget(), pgad will be NULL and
CreateGadget() will fail  immediately.  This means that the program can
perform several successive calls to CreateGadget() and only have to check
for failure at the end.

Finally, although this information is hidden in the implementation and not
important to the application, certain calls to [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) actually
cause several Intuition gadgets to be allocated and these are
automatically linked together without program interaction, but only if a
previous gadget pointer is supplied.  If several gadgets are created by a
single CreateGadget() call, they work together to provide the
functionality of a single GadTools gadget.  The application should always
act as though the gadget pointer returned by CreateGadget() points to a
single gadget instance.  See "Documented Side-Effects" for a warning.

There is one exception to the fact that a program only has to check for
failure after the last [CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) call and that is when the
application depends on the successful creation of a gadget and caches or
immediately uses the gadget pointer returned by CreateGadget().

 For instance, if the program wants to create a string gadget and save a
pointer to the string buffer, it might do so as follows:


```c
    gad = CreateGadget(STRING_KIND, gad, &ng,
                            GTST_String, "Hello World",
                            TAG_END);
    if (gad)
        {
        stringbuffer = ((struct StringInfo *)(gad->SpecialInfo))->Buffer;
        }

    /* Creation can continue here: */
    gad = CreateGadget(..._KIND, gad, &ng2,
        ...
        TAG_END);
```
A major benefit of having a reusable [NewGadget](libraries/15-gadtools-gadgets-the-newgadget-structure.md) structure is that often
many fields do not change and some fields change incrementally.  For
example, the application can set just the NewGadget's [ng_VisualInfo](libraries/15-gadtools-gadgets-the-newgadget-structure.md) and
[ng_TextAttr](libraries/15-gadtools-gadgets-the-newgadget-structure.md) only once and never have to modify them again even if the
structure is reused to create many gadgets.  A set of similar gadgets may
share size and some positional information so that code such as the
following might be used:


```c
    /* Assume that the NewGadget structure 'ng' is fully
     * initialized here for a button labelled "OK"
     */
    gad = CreateGadget(BUTTON_KIND, gad, &ng,
        TAG_END);

    /* Modify only those fields that need to change: */
    ng.ng_GadgetID++;
    ng.ng_LeftEdge += 80;
    ng.ng_GadgetText = "Cancel";
    gad = CreateGadget(BUTTON_KIND, gad, &ng,
                            TAG_END);

    Warning:
    --------
    All gadgets created by GadTools currently have the GADTOOL_TYPE bit
    set in their [GadgetType](libraries/5-intuition-gadgets-gadget-structure.md) field.  It is not correct to check for,
    set, clear or otherwise rely on this since it is subject to change.
```

---

## See Also

- [CreateContext — gadtools.library](../autodocs/gadtools.library.md#createcontext)
