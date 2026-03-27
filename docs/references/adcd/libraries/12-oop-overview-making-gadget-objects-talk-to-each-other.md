---
title: 12 / OOP Overview / Making Gadget Objects Talk to Each Other
manual: libraries
chapter: libraries
section: 12-oop-overview-making-gadget-objects-talk-to-each-other
functions: []
libraries: []
---

# 12 / OOP Overview / Making Gadget Objects Talk to Each Other

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One use for a proportional gadget is to let the user change some integer
value, like the red, green, and blue components of a color. This type of
prop gadget is commonly accompanied by an integer string gadget, enabling
the user to adjust one integer value by either typing the value into the
string gadget or by scrolling the prop gadget.  Because these two gadgets
reflect the value of the same integer, when the user adjusts the state of
one of the gadgets (and thus changing the integer value), the other gadget
should automatically update to reflect the new integer value.

When the user manipulates a conventional gadget, the gadget sends messages
to an IDCMP port to indicate the state change (for information on IDCMP,
see the "[Intuition Input and Output Methods](libraries/9-intuition-input-and-output-methods-using-the-idcmp.md)" chapter of this manual).  To
connect the string and prop gadgets from the previous paragraph, an
application would have to listen for the IDCMP messages from two different
gadgets, interpret the IDCMP message's meaning, and manually update the
gadgets accordingly. Essentially, the application is responsible for
"gluing" the gadgets together.  This unnecessarily complicates an
application, especially when that application already has to listen for
and interpret many other events.

Boopsi gadgets simplify this.  By setting the appropriate attributes, an
application can ask a Boopsi gadget to tell some other object when its
state changes.  One of the attributes defined by [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) is [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md)
(defined in <intuition/[icclass.h](autodocs-2.0/includes-intuition-icclass-h.md)>).  The ICA_TARGET attribute points to
another Boopsi object.  When certain attributes in a Boopsi gadget change
(like the integer value of a prop gadget), that gadget looks to see if it
has an ICA_TARGET.  If it does, it sends the target a message telling it
to perform an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method.

The [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method is defined by [rootclass](libraries/12-boopsi-object-oriented-intuition-oop-overview.md).  This is basically a special
type of [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) method that is used specifically to tell a Boopsi object
that another Boopsi object's state changed.  Only Boopsi objects send
OM_UPDATE messages.  Note that standard classes of Boopsi gadgets only
send out OM_UPDATE messages as a result of the user changing the state of
the gadget (scrolling the prop gadget, typing a new number into an integer
gadget, etc.).  These gadgets do not send out OM_UPDATE messages when they
receive OM_SET or OM_UPDATE messages.

A Boopsi [propgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) object has only one attribute that triggers it to send
an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) request: [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md). This attribute contains the integer value
of the prop gadget.  Every time the user moves a prop gadget, the PGA_Top
attribute changes.  If the prop gadget has an [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md), the prop gadget
will tell the target object that the PGA_Top value has changed.

A Boopsi integer string gadget (a [strgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) object) also has only one
attribute that triggers it to send an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) request: [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md).
value contains the integer value of the integer string gadget.  Like
the prop gadget, if the integer string gadget has an [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md), when the
user changes the gadget's integer value (STRINGA_LongVal), the string
gadget will tell the target object that the STRINGA_LongVal value has
changed.

When a Boopsi gadget sends an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, it passes the ID of the
attribute that changed plus that attribute's new value.  For example, if
the user typed a 25 into a Boopsi integer string gadget, that gadget would
send an OM_UPDATE message to its [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md) saying in essence, "Hey,
[STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md) is 25".

If this string gadget's [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md) is a [propgclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) object, the propgclass
object will become confused because it has no idea what a [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md)
attribute is.  The string gadget needs to map its STRINGA_LongVal ID to
the [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md) ID.  This is what the [ICA_MAP](libraries/b-gadgetclass-attributes-ica-map-is.md) attribute is for.

The ICA_MAP attribute is defined by [gadgetclass](libraries/b-gadgetclass-attributes-ica-map-is.md) (it is also defined for
[icclass](libraries/b-icclass-attributes-ica-target-is.md)--more on that later).  It accepts a tag list of attribute
mappings.  When a gadget sends out an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, it uses this map
to translate a specific attribute ID to another attribute ID, without
changing the value of the attribute.  Each [TagItem](libraries/37-tags-tag-functions-and-structures.md) in the ICA_MAP makes up
a single attribute mapping. The TagItem.ti_Tag of the mapping is the ID of
an attribute to translate.  The gadget translates that attribute ID to the
attribute ID in TagItem.ti_Data.  For example, an ICA_MAP that maps a
string gadget's [STRINGA_LongVal](libraries/b-strgclass-attributes-stringa-longval-isgnu.md) attribute to a prop gadget's [PGA_Top](libraries/b-propgclass-pga-top-isgnu-pga-visible-pga-total-isu.md)
attribute looks like this:


```c
    struct TagItem slidertostring[] = {
        {PGA_Top, STRINGA_LongVal},
        {TAG_END, }
    };
```
Note that it is OK to have an ICA_TARGET without having an ICA_MAP.  In
cases where a gadget and its [ICA_TARGET](libraries/b-gadgetclass-attributes-ica-target-is.md) have a set of attributes in
common, it would be unnecessary to use an [ICA_MAP](libraries/b-gadgetclass-attributes-ica-map-is.md) to match a gadget's
attributes, as they already match.

The following example, Talk2boopsi.c, creates a prop gadget and an integer
string gadget which update each other without the example program having
to process any messages from them.


```c
     [Talk2boopsi.c](libraries/lib-examples-talk2boopsi-c.md) 
```
