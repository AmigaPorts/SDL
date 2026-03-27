# gadtools.library/CreateContext



NAME

```c
    CreateContext -- Create a place for GadTools context data. (V36)
```
SYNOPSIS

```c
    gad = CreateContext(glistpointer);
    D0                  A0

    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *CreateContext(struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) **);
```
FUNCTION

    Creates a place for GadTools to store any context data it might
    need for your window.  In reality, an unselectable invisible
    gadget is created, with room for the context data.
    This function also establishes the linkage from a glist type
    pointer to the individual gadget pointers.  Call this function
    before any of the other gadget creation calls.
INPUTS

```c
    glistptr - Address of a pointer to a [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215), which was previously
        set to NULL.  When all the gadget creation is done, you may
        use that pointer as your NewWindow.FirstGadget, or
        in [intuition.library/AddGList()](../Includes_and_Autodocs_2._guide/node01FD.html), [intuition.library/RefreshGList()](../Includes_and_Autodocs_2._guide/node0241.html),
        [FreeGadgets()](../Includes_and_Autodocs_2._guide/node03EB.html), etc.
```
RESULT

    gad - Pointer to context gadget, or NULL if failure.
EXAMPLE


```c
    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *gad;
    struct [Gadget](../Includes_and_Autodocs_2._guide/node00D4.html#line215) *glist = NULL;
    gad = CreateContext(&glist);
    /*  Other creation calls go here */
    if (gad)
    {
        myNewWindow.FirstGadget = glist;
        if ( myWindow = OpenWindow(&myNewWindow) )
        {
            GT_RefreshWindow(win);
            /* other stuff */
            CloseWindow(myWindow);
        }
    }
    FreeGadgets(glist);
```
NOTES

BUGS

SEE ALSO

