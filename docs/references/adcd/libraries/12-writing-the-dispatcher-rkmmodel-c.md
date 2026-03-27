---
title: 12 / / Writing The Dispatcher / RKMModel.c
manual: libraries
chapter: libraries
section: 12-writing-the-dispatcher-rkmmodel-c
functions: [RefreshGadgets]
libraries: [intuition.library]
---

# 12 / / Writing The Dispatcher / RKMModel.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following code, RKMModel.c,  makes up an initialization function and
the dispatcher function for a private class informally called
[rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md).


```c
     [RKMModel.c](libraries/lib-examples-rkmmodel-c.md) 
```
Below is a diagram showing how an application could use an [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md)
object:


```c
     [Figure 12-5: Rkmmodelclass Object Diagram](libraries/lib-pics-12-5-pic.md) 
```
In this diagram, the application uses [buttongclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) Boopsi gadgets to send
the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) the [RKMMOD_Up](libraries/12-building-on-existing-public-classes-building.md) and [RKMMOD_Down](libraries/12-building-on-existing-public-classes-building.md) attribute pulses.

The example takes advantage of an odd feature of [buttongclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md).  When the
user clicks on a buttongclass gadget, it sends an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) to its
[ICA_TARGET](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md), even though no Boopsi attribute of buttongclass has changed.
It does this because it's a convenient way to report button clicks.

Whenever a gadget sends a notification, the list of attribute/value pairs
in the [OM_NOTIFY](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message always contains the gadget's [GA_ID](libraries/b-gadgetclass-attributes-ga-border-ga-specialinfo-is.md). This is an
easy way for the button to inform its target of its ID so the target knows
which gadget sent the [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message.  When a [buttongclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md) sends a
notification because of a button click, it only sends out an OM_UPDATE
about its GA_ID because none of its attributes changed.

When the user clicks one of the buttons in the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) diagram, the
button uses an [ICA_MAP](libraries/12-oop-overview-making-gadget-objects-talk-to-each-other.md) to map its [GA_ID](libraries/b-gadgetclass-attributes-ga-border-ga-specialinfo-is.md) to one of the "dummy" pulse
attributes, [RKMMOD_Up](libraries/12-building-on-existing-public-classes-building.md) and [RKMMOD_Down](libraries/12-building-on-existing-public-classes-building.md).  When the rkmmodel receives the
[OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message about RKMMOD_Up or RKMMOD_Down, it increments or
decrements its internal value.

There is one more important thing to note about [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md). Looking at
the rkmmodelclass Object diagram above, an rkmmodel's [RKMMOD_CurrVal](libraries/12-creating-a-boopsi-class-building-on-existing-public.md)
changes because it received an [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message from one of its gadgets.
RKMMOD_CurrVal can also change if the application explicitly set
RKMMOD_CurrVal using [SetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) or [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md).

The primary difference between the [OM_SET](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message that [SetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) sends
and the OM_SET message that [SetGadgetAttrs()](libraries/12-using-boopsi-setting-an-existing-object-s-attributes.md) sends is that SetAttrs()
passes a NULL in [opSet.ops_GInfo](libraries/12-boopsi-object-oriented-intuition-creating-a-boopsi-class.md) instead of a [GadgetInfo](libraries/12-boopsi-gadgets-the-boopsi-gadget-methods.md) pointer.  This
doesn't present a problem for the rkmmodel object, because it doesn't use
the GadgetInfo structure.  The problem is that when the rkmmodel notifies
its targets, some of which are gadgets, they can't update their visual
state because they need a GadgetInfo to render themselves.  For this
reason, the [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher returns a positive non-zero value
when an attribute change occurs that could cause a change in the visual
state of any objects in its broadcast list.  An application that uses
rkmmodelclass must test the return value when calling SetAttrs() on an
rkmmodelclass object to tell if the attribute change requires a visual
refresh of the gadgets (see the Intuition Autodocs for [RefreshGadgets()](autodocs-2.0/intuition-library-refreshgadgets.md)).


```c
    Boopsi Dispatchers Can Execute on Intuition's Context.
    ------------------------------------------------------
    Notice that the gadgets in the figure above send [OM_UPDATE](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) messages
    to the rkmmodel when the user manipulates them.  Because Intuition
    handles the user input that triggers the OM_UPDATE messages,
    Intuition itself is sending the OM_UPDATE messages.  This means the
    [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) dispatcher must be able to run on Intuition's context,
    which puts some limitations on what the dispatcher is permitted to
    do: it can't use dos.library, it can't wait on application signals or
    message ports, and it can't call any Intuition functions which might
    wait on Intuition.
```
Although [rkmmodelclass](libraries/12-creating-a-boopsi-class-building-on-existing-public.md) serves as an example of a class, it leaves a little
to be desired in a real-world implementation.  To create the
"prop-integer-up/down" super gadget from the diagram above, the
application has to create, initialize, and link nine Boopsi objects, which
is tedious, especially if the application needs several of these super
gadgets.  Ideally, all these functions would be rolled into some subclass
of [gadgetclass](libraries/12-the-public-classes-the-gadgetclass-subclasses.md).  If there were such a class, an application would only
have to create one instance of this subclass to get such a gadget.  When
the subclass received an [OM_NEW](libraries/12-creating-a-boopsi-class-writing-the-dispatcher.md) message, it would take care of creating,
initializing, and linking all of the Boopsi objects that make up the whole
super gadget.

---

## See Also

- [RefreshGadgets — intuition.library](../autodocs/intuition.library.md#refreshgadgets)
