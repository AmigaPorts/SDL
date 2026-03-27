# 28 / Using Bobs / Using Bob Flags


The following paragraphs describe how to set the [Flags](../Libraries_Manual_guide/node0398.html#line5) field in the [Bob](../Libraries_Manual_guide/node0398.html)
structure (note that these flags do not apply to the Flags field of the
[VSprite](../Libraries_Manual_guide/node0381.html) structure).

[SAVEBOB](../Includes_and_Autodocs_2._guide/node00C3.html#line32)

```c
    To tell the system not to erase the old image of the Bob when the Bob
    is moved, specify the SAVEBOB flag in the [Bob](../Libraries_Manual_guide/node0398.html) structure [Flags](../Libraries_Manual_guide/node0398.html#line5) field.
    This makes the Bob behave like a paintbrush.  It has the opposite
    effect of [SAVEBACK](../Libraries_Manual_guide/node0397.html#line5).

    It's Faster To Draw A New Bob.
    ------------------------------
    It takes longer to preserve and restore the raster image than simply
    to draw a new Bob image wherever required.
```
[BOBISCOMP](../Includes_and_Autodocs_2._guide/node00C3.html#line32)

```c
    If this Bob is part of an [AnimComp](../Libraries_Manual_guide/node03B9.html#line3), set the BOBISCOMP flag in the [Bob](../Libraries_Manual_guide/node0398.html)
    structure to 1.  If the flag is a 1, the pointer named [BobComp](../Libraries_Manual_guide/node0398.html#line10) must
    have been initialized.  Otherwise, the system ignores the pointer,
    and it may be left alone (though it's good practice to initialize it
    to NULL).  See "[Animation Data Structures](../Libraries_Manual_guide/node03B9.html)" for a discussion
    of AnimComps.
```
[BWAITING](../Includes_and_Autodocs_2._guide/node00C3.html#line36)

```c
    This flag is used solely by the system, and should be left alone.
    When a Bob is waiting to be drawn, the system sets the BWAITING flag
    in the [Bob](../Libraries_Manual_guide/node0398.html) structure to 1.  This occurs only if the system has found
    a [Before](../Libraries_Manual_guide/node03A4.html) pointer in this Bob's structure that points to another Bob.
    Thus, the system flag BWAITING provides current draw-status to the
    system.  Currently, the system clears this flag on return from each
    call to [DrawGList()](../Libraries_Manual_guide/node038C.html).
```
[BDRAWN](../Includes_and_Autodocs_2._guide/node00C3.html#line36)

```c
    This is a system status flag that indicates to the system whether or
    not this Bob has already been drawn.  Therefore, in the process of
    examining the various [Before](../Libraries_Manual_guide/node03A4.html) and [After](../Libraries_Manual_guide/node03A4.html) flags, the drawing routines
    can determine the drawing sequence.  The system clears this flag on
    return from each call to [DrawGList()](../Libraries_Manual_guide/node038C.html).
```
[BOBSAWAY](../Includes_and_Autodocs_2._guide/node00C3.html#line36)

```c
    To initiate the removal of a Bob during the next call to [DrawGList()](../Libraries_Manual_guide/node038C.html),
    set BOBSAWAY to 1.  Either the application or the system may set this
    [Bob](../Libraries_Manual_guide/node0398.html) structure system flag.  The system restores the background where
    it has last drawn the Bob.  The system will unlink the Bob from the
    system GEL list the next time DrawGList() is called, unless the
    application is using double-buffering.  In that case, the Bob will
    not be unlinked and completely removed until two calls to DrawGList()
    have occurred and the Bob has been removed from both buffers.  The
    [RemBob()](../Libraries_Manual_guide/node03A6.html) macro sets the BOBSAWAY flag.
```
[BOBNIX](../Includes_and_Autodocs_2._guide/node00C3.html#line36)

```c
    When a Bob has been completely removed, the system sets the BOBNIX
    flag to 1 on return from [DrawGList()](../Libraries_Manual_guide/node038C.html).  In other words, when the
    background area has been fully restored and the Bob has been removed
    from the GEL list, this flag in is set to a 1.  BOBNIX is especially
    significant when double-buffering because when an application asks
    for a Bob to be removed, the system must remove it from both the
    drawing buffer and from the display buffer.  Once BOBNIX has been
    set, it means the Bob has been removed from both buffers and the
    application is free to reuse or deallocate the Bob.
```
[SAVEPRESERVE](../Includes_and_Autodocs_2._guide/node00C3.html#line36)

```c
    The SAVEPRESERVE flag is a double-buffer version of the [SAVEBACK](../Libraries_Manual_guide/node0397.html#line5)
    flag.  If using double-buffering and wishing to save and restore the
    background, set SAVEBACK to 1.  SAVEPRESERVE is used by the system to
    indicate whether the Bob in the "other" buffer has been restored; it
    is for system use only.
```
