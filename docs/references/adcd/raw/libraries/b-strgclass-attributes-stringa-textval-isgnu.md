# B / strgclass / Attributes: STRINGA_TextVal (ISGNU)


This attribute tells [strgclass](../Libraries_Manual_guide/node0510.html) that this gadget is a plain string gadget.
The attribute points to a string which the object copies into the string
gadget's current string value buffer.

When a [strgclass](../Libraries_Manual_guide/node0510.html) gadget's internal [STRINGA_LongVal](../Libraries_Manual_guide/node0512.html) or STRINGA_TextVal
value changes (usually because the user manipulated the gadget), it sends
itself an [OM_NOTIFY](../Libraries_Manual_guide/node04F9.html) message.  The OM_NOTIFY message will contain two
attribute/value pairs, GA_ID and either STRINGA_LongVal or STRINGA_TextVal
(depending on what kind of strgclass gadget it is).  Strgclass gadgets
only send a final OM_NOTIFY message (one's with the OPUF_INTERIM flag of
the [opUpdate.opu_Flags](../Libraries_Manual_guide/node04C4.html#line26) field cleared).

