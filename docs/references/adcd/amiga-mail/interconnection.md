---
title: Interconnection
manual: amiga-mail
chapter: amiga-mail
section: interconnection
functions: []
libraries: []
---

# Interconnection

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The boopsi gadgets in [boopsi1.c](amiga-mail/iv-23-boopsi1-c.md) are not very powerful.  The gadgets work
independently of each other, forcing the application to unify them.  It
is possible to make gadget objects update each other without the
application's intervention.

Gadgetclass defines two attributes used in this updating process:
ICA_Target and ICA_Map.  The ICA_Target attribute specifies a pointer to
a target object.  If an object's attribute changes (and the OM_NOTIFY
method applies to that attribute), the object sends itself an OM_NOTIFY
message.  If the object has a target object, the target will receive an
OM_UPDATE message which usually tells the target to set one of its own
attributes.  For example, when the user slides the knob of a propgclass
object, its PGA_Top attribute changes.  If this object has a second
propgclass object as its target, the second object will receive an
OM_UPDATE message and will set its corresponding PGA_Top attribute to
the PGA_Top value of the first propgclass object.

Because objects of different classes do not always have corresponding
attributes, there is a way to map attributes of one object to the
attributes of another.  The ICA_Map accepts a TagItem array of attribute
pairs.  The first entry in the pair is the source attribute ID and the
second is the target object's attribute.  For example, an ICA_Map that
maps a prop gadget's PGA_Top attribute to a string gadget's
STRINGA_LongVal attribute would look like this:


```c
    struct TagItem slidertostring[] = {
        {PGA_Top, STRINGA_LongVal},
        {TAG_END, }
    };
```
Note that the OM_UPDATE method has to apply to the target attribute for
the change to take place.

Although the gadget attributes ICA_Target and ICA_Map allow boopsi
gadgets to update each other, by themselves these attributes do not
provide the application with any information on changes to the gadgets.
Instead of using another gadget as a target object, an object targets an
icclass object.  Icclass  (or InterConnection) objects are simple
information forwarders.

Icclass defines two attributes: ICA_Target and ICA_Map, which are almost
identical to the gadgetclass attributes.  The difference is that icclass
objects can send the application an IDCMPUPDATE IntuiMessage when it
receives an OM_UPDATE.  If an icclass object receives an OM_UPDATE, it
will send the IntuiMessage only if the icclass object's ICA_Target is
ICTARGET_IDCMP and the updated attribute is mapped to a special dummy
attribute, ICSPECIAL_CODE.  The IntuiMessage's Code field contains the
lower 16 bits of the updated attribute.

Icclass has a more powerful subclass called modelclass.  A modelclass
object sends OM_UPDATE messages to an entire list of objects that the
modelclass object maintains.  This makes it possible for gadgets to
update each other and for the application to find out about the changes.
A modelclass object "broadcasts" attribute changes to its list of
boopsi objects and it also lets the application know about attribute
changes because it inherits the ICTARGET_IDCMP mechanism from icclass.
To add objects to a modelclass object's list, use the OM_ADDMEMBER
method.

The power of icclass and modelclass lies in using them to create a
custom subclass.  Consider a group of prop gadgets each of which is used
to control one of a color's R, G, B, H, S, and V components.  When the
user changes one of the color components with a prop gadget, the custom
model will be notified of that change and, because it is customized for
this specific purpose, it will recalculate the values for the remaining
components.   The model will then let the rest of the prop gadget
objects (which are attached to icclass objects in the custom model's
personal list) know about the changes to their component values so they
can move their slider to its new position.  All this work is done by the
objects themselves; the application does not have to process any of the
intermediate input.

In general, boopsi's power lies in its Intuition-supported
extensibility.  Using the existing boopsi classes as a foundation,  you
can create entirely new subclasses.  This makes it possible to create
your own custom gadgetry and have it work perfectly with Intuition, just
like any existing gadget.   New subclasses of modelclass can be used to
create gadgets that talk directly to ARexx or the clipboard device.  If
new classes are general enough, they can be made public so other
applications can use them.

