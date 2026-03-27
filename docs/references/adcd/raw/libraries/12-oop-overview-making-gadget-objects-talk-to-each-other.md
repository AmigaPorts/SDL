# 12 / OOP Overview / Making Gadget Objects Talk to Each Other


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
see the "[Intuition Input and Output Methods](../Libraries_Manual_guide/node01D6.html)" chapter of this manual).  To
connect the string and prop gadgets from the previous paragraph, an
application would have to listen for the IDCMP messages from two different
gadgets, interpret the IDCMP message's meaning, and manually update the
gadgets accordingly. Essentially, the application is responsible for
"gluing" the gadgets together.  This unnecessarily complicates an
application, especially when that application already has to listen for
and interpret many other events.

Boopsi gadgets simplify this.  By setting the appropriate attributes, an
application can ask a Boopsi gadget to tell some other object when its
state changes.  One of the attributes defined by [gadgetclass](../Libraries_Manual_guide/node020A.html) is [ICA_TARGET](../Libraries_Manual_guide/node04FB.html)
(defined in <intuition/[icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line26)>).  The ICA_TARGET attribute points to
another Boopsi object.  When certain attributes in a Boopsi gadget change
(like the integer value of a prop gadget), that gadget looks to see if it
has an ICA_TARGET.  If it does, it sends the target a message telling it
to perform an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) method.

The [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) method is defined by [rootclass](../Libraries_Manual_guide/node0200.html#line50).  This is basically a special
type of [OM_SET](../Libraries_Manual_guide/node0211.html#line28) method that is used specifically to tell a Boopsi object
that another Boopsi object's state changed.  Only Boopsi objects send
OM_UPDATE messages.  Note that standard classes of Boopsi gadgets only
send out OM_UPDATE messages as a result of the user changing the state of
the gadget (scrolling the prop gadget, typing a new number into an integer
gadget, etc.).  These gadgets do not send out OM_UPDATE messages when they
receive OM_SET or OM_UPDATE messages.

A Boopsi [propgclass](../Libraries_Manual_guide/node020A.html#line4) object has only one attribute that triggers it to send
an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) request: [PGA_Top](../Libraries_Manual_guide/node050F.html). This attribute contains the integer value
of the prop gadget.  Every time the user moves a prop gadget, the PGA_Top
attribute changes.  If the prop gadget has an [ICA_TARGET](../Libraries_Manual_guide/node04FB.html), the prop gadget
will tell the target object that the PGA_Top value has changed.

A Boopsi integer string gadget (a [strgclass](../Libraries_Manual_guide/node020A.html#line7) object) also has only one
attribute that triggers it to send an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) request: [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html).
value contains the integer value of the integer string gadget.  Like
the prop gadget, if the integer string gadget has an [ICA_TARGET](../Libraries_Manual_guide/node04FB.html), when the
user changes the gadget's integer value (STRINGA_LongVal), the string
gadget will tell the target object that the STRINGA_LongVal value has
changed.

When a Boopsi gadget sends an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message, it passes the ID of the
attribute that changed plus that attribute's new value.  For example, if
the user typed a 25 into a Boopsi integer string gadget, that gadget would
send an OM_UPDATE message to its [ICA_TARGET](../Libraries_Manual_guide/node04FB.html) saying in essence, "Hey,
[STRINGA_LongVal](../Libraries_Manual_guide/node0512.html) is 25".

If this string gadget's [ICA_TARGET](../Libraries_Manual_guide/node04FB.html) is a [propgclass](../Libraries_Manual_guide/node020A.html#line4) object, the propgclass
object will become confused because it has no idea what a [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html)
attribute is.  The string gadget needs to map its STRINGA_LongVal ID to
the [PGA_Top](../Libraries_Manual_guide/node050F.html) ID.  This is what the [ICA_MAP](../Libraries_Manual_guide/node04FC.html) attribute is for.

The ICA_MAP attribute is defined by [gadgetclass](../Libraries_Manual_guide/node04FC.html) (it is also defined for
[icclass](../Libraries_Manual_guide/node04C9.html)--more on that later).  It accepts a tag list of attribute
mappings.  When a gadget sends out an [OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) message, it uses this map
to translate a specific attribute ID to another attribute ID, without
changing the value of the attribute.  Each [TagItem](../Libraries_Manual_guide/node0497.html) in the ICA_MAP makes up
a single attribute mapping. The TagItem.ti_Tag of the mapping is the ID of
an attribute to translate.  The gadget translates that attribute ID to the
attribute ID in TagItem.ti_Data.  For example, an ICA_MAP that maps a
string gadget's [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html) attribute to a prop gadget's [PGA_Top](../Libraries_Manual_guide/node050F.html)
attribute looks like this:


```c
    struct TagItem slidertostring[] = {
        {PGA_Top, STRINGA_LongVal},
        {TAG_END, }
    };
```
Note that it is OK to have an ICA_TARGET without having an ICA_MAP.  In
cases where a gadget and its [ICA_TARGET](../Libraries_Manual_guide/node04FB.html) have a set of attributes in
common, it would be unnecessary to use an [ICA_MAP](../Libraries_Manual_guide/node04FC.html) to match a gadget's
attributes, as they already match.

The following example, Talk2boopsi.c, creates a prop gadget and an integer
string gadget which update each other without the example program having
to process any messages from them.


```c
     [Talk2boopsi.c](../Libraries_Manual_guide/node0582.html) 
```
