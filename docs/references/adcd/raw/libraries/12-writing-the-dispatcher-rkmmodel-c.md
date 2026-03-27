# 12 / / Writing The Dispatcher / RKMModel.c


The following code, RKMModel.c,  makes up an initialization function and
the dispatcher function for a private class informally called
[rkmmodelclass](../Libraries_Manual_guide/node020F.html).


```c
     [RKMModel.c](../Libraries_Manual_guide/node0581.html) 
```
Below is a diagram showing how an application could use an [rkmmodelclass](../Libraries_Manual_guide/node020F.html)
object:


```c
     [Figure 12-5: Rkmmodelclass Object Diagram](../Libraries_Manual_guide/node05DF.html) 
```
In this diagram, the application uses [buttongclass](../Libraries_Manual_guide/node020A.html#line14) Boopsi gadgets to send
the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) the [RKMMOD_Up](../Libraries_Manual_guide/node0210.html#line8) and [RKMMOD_Down](../Libraries_Manual_guide/node0210.html#line8) attribute pulses.

The example takes advantage of an odd feature of [buttongclass](../Libraries_Manual_guide/node020A.html#line14).  When the
user clicks on a buttongclass gadget, it sends an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) to its
[ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20), even though no Boopsi attribute of buttongclass has changed.
It does this because it's a convenient way to report button clicks.

Whenever a gadget sends a notification, the list of attribute/value pairs
in the [OM_NOTIFY](../Libraries_Manual_guide/node0211.html#line56) message always contains the gadget's [GA_ID](../Libraries_Manual_guide/node0501.html). This is an
easy way for the button to inform its target of its ID so the target knows
which gadget sent the [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message.  When a [buttongclass](../Libraries_Manual_guide/node020A.html#line14) sends a
notification because of a button click, it only sends out an OM_UPDATE
about its GA_ID because none of its attributes changed.

When the user clicks one of the buttons in the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) diagram, the
button uses an [ICA_MAP](../Libraries_Manual_guide/node020B.html#line63) to map its [GA_ID](../Libraries_Manual_guide/node0501.html) to one of the "dummy" pulse
attributes, [RKMMOD_Up](../Libraries_Manual_guide/node0210.html#line8) and [RKMMOD_Down](../Libraries_Manual_guide/node0210.html#line8).  When the rkmmodel receives the
[OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message about RKMMOD_Up or RKMMOD_Down, it increments or
decrements its internal value.

There is one more important thing to note about [rkmmodelclass](../Libraries_Manual_guide/node020F.html). Looking at
the rkmmodelclass Object diagram above, an rkmmodel's [RKMMOD_CurrVal](../Libraries_Manual_guide/node020F.html)
changes because it received an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message from one of its gadgets.
RKMMOD_CurrVal can also change if the application explicitly set
RKMMOD_CurrVal using [SetAttrs()](../Libraries_Manual_guide/node0205.html) or [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5).

The primary difference between the [OM_SET](../Libraries_Manual_guide/node0211.html#line28) message that [SetAttrs()](../Libraries_Manual_guide/node0205.html) sends
and the OM_SET message that [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5) sends is that SetAttrs()
passes a NULL in [opSet.ops_GInfo](../Libraries_Manual_guide/node020E.html#line37) instead of a [GadgetInfo](../Libraries_Manual_guide/node0219.html#line23) pointer.  This
doesn't present a problem for the rkmmodel object, because it doesn't use
the GadgetInfo structure.  The problem is that when the rkmmodel notifies
its targets, some of which are gadgets, they can't update their visual
state because they need a GadgetInfo to render themselves.  For this
reason, the [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher returns a positive non-zero value
when an attribute change occurs that could cause a change in the visual
state of any objects in its broadcast list.  An application that uses
rkmmodelclass must test the return value when calling SetAttrs() on an
rkmmodelclass object to tell if the attribute change requires a visual
refresh of the gadgets (see the Intuition Autodocs for [RefreshGadgets()](../Includes_and_Autodocs_2._guide/node0240.html)).


```c
    Boopsi Dispatchers Can Execute on Intuition's Context.
    ------------------------------------------------------
    Notice that the gadgets in the figure above send [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) messages
    to the rkmmodel when the user manipulates them.  Because Intuition
    handles the user input that triggers the OM_UPDATE messages,
    Intuition itself is sending the OM_UPDATE messages.  This means the
    [rkmmodelclass](../Libraries_Manual_guide/node020F.html) dispatcher must be able to run on Intuition's context,
    which puts some limitations on what the dispatcher is permitted to
    do: it can't use dos.library, it can't wait on application signals or
    message ports, and it can't call any Intuition functions which might
    wait on Intuition.
```
Although [rkmmodelclass](../Libraries_Manual_guide/node020F.html) serves as an example of a class, it leaves a little
to be desired in a real-world implementation.  To create the
"prop-integer-up/down" super gadget from the diagram above, the
application has to create, initialize, and link nine Boopsi objects, which
is tedious, especially if the application needs several of these super
gadgets.  Ideally, all these functions would be rolled into some subclass
of [gadgetclass](../Libraries_Manual_guide/node020A.html).  If there were such a class, an application would only
have to create one instance of this subclass to get such a gadget.  When
the subclass received an [OM_NEW](../Libraries_Manual_guide/node0211.html#line20) message, it would take care of creating,
initializing, and linking all of the Boopsi objects that make up the whole
super gadget.

