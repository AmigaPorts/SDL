# 15 / GadTools Gadgets / Creating Gadgets


The main call used to create a gadget with GadTools is [CreateGadget()](../Includes_and_Autodocs_2._guide/node03E8.html).
This function can be used to create a single gadget or it can be called
repeatedly to create a linked list of gadgets.  It takes three arguments
followed by a set of tags:


```c
    struct Gadget *CreateGadget( ULONG kind, struct Gadget *prevgad,
                                 struct NewGadget *newgad,
                                 struct TagItem *taglist)
    struct Gadget *CreateGadgetA(ULONG kind, struct Gadget *prevgad,
                                 struct NewGadget *newgad,
                                 struct Tag tag1, ...)
```
Set the kind argument to one of the 12 gadget types supported by GadTools.
Set the prevgad argument to the gadget address returned by [CreateContext()](../Libraries_Manual_guide/node026D.html)
if this is the first (or only) gadget in the list.  Subsequent calls to
[CreateGadget()](../Includes_and_Autodocs_2._guide/node03E8.html) can be used to create and link AutoDocs/gadgets together in a list
in which case the prevgad argument is set to the address of the gadget
returned by the preceding call to CreateGadget().

Set the newgad argument to the address of the [NewGadget](../Libraries_Manual_guide/node0259.html) structure
describing the gadget to be created and set any special attributes for
this gadget type using the tag arguments, tag1 or taglist.  For instance,
the following code fragment might be used to create the color slider
discussed earlier:


```c
    slidergad = CreateGadget(SLIDER_KIND, newgadget, prevgad,
        GTSL_Min, 0,
        GTSL_Max, 15,
        GTSL_Level, 11,
        TAG_END);
```
[CreateGadget()](../Includes_and_Autodocs_2._guide/node03E8.html) typically allocates and initializes all the necessary
Intuition structures, including in this case the [Gadget](../Libraries_Manual_guide/node0149.html), [IntuiText](../Libraries_Manual_guide/node01C7.html) and
[PropInfo](../Libraries_Manual_guide/node0161.html) structures, as well as certain buffers.  For more about these
underlying structures, see the "[Intuition Gadgets](../Libraries_Manual_guide/node012F.html)" chapter.

Since [CreateGadget()](../Includes_and_Autodocs_2._guide/node03E8.html) is a tag-based function, it is easy to add more tags
to get a fancier gadget.  For example, GadTools can optionally display the
running level beside the slider.  The caller must supply a [printf()](../Includes_and_Autodocs_2._guide/node0162.html)-style
formatting string and the maximum length that the string will resolve to
when the number is inserted:


```c
    slidergad = CreateGadget(SLIDER_KIND, newgadget, prevgad,
        GTSL_Min, 0,
        GTSL_Max, 15,
        GTSL_Level, 11,
        GTSL_LevelFormat, "%2ld" /* printf()-style formatting string */
        GTSL_MaxLevelLen, 2,     /* maximum length of string         */
        TAG_END);
```
The level, 0 to 15 in this example, would then be displayed beside the
slider.  The formatting string could instead be "%2ld/15", so the level
would be displayed as "0/15" through "15/15".

