# 12 / OOP Overview / Making Gadgets Talk to an Application


There are two questions that the [example](../Libraries_Manual_guide/node0582.html) above brings to mind.  The first
is, "What happens if the user types a value into the string gadget that is
beyond the bounds of the prop gadget?"  The answer is simple: very little.
The prop gadget is smart enough to make sure its integer value does not go
beyond the bounds of its display.  In the example, the prop gadget can
only have values from 0 to 90.  If the user tries to type a value greater
than 90, the prop gadget will set itself to its maximum of 90.  Because
the integer string gadget doesn't have any bounds checking built into it,
the example needs to find an alternative way to check the bounds.

The other question is, "How does [talk2boopsi.c](../Libraries_Manual_guide/node0582.html) know the current value of
the gadgets?"  That answer is simple too: it doesn't.  The example doesn't
ask the gadgets what their current values are (which it would do using
[GetAttr()](../Libraries_Manual_guide/node0206.html)) and the example doesn't pay attention to gadget events at the
window's IDCMP port, so it isn't going to hear about them.

One easy way to hear about changes to the gadget events is to listen for a
"release verify".  Conventional Intuition gadgets can trigger a release
verify IDCMP event when the user finishes manipulating the gadget.  Boopsi
gadgets can do this, too, while continuing to update each other.

To make [Talk2boopsi.c](../Libraries_Manual_guide/node0582.html) do this would require only a few changes. First, the
window's IDCMP port has to be set up to listen for [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) events.
Next, the example needs to set the gadget's [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) flags.  It can
do this by setting the [gadgetclass](../Libraries_Manual_guide/node020A.html) [GA_RelVerify](../Libraries_Manual_guide/node0504.html) attribute to TRUE for both
gadgets.  That's enough to trigger the release verify message, so all
Talk2boopsi.c needs to do is account for the new type of IDCMP message,
IDCMP_GADGETUP.  When Talk2boopsi.c gets a release verify message, it can
use [GetAttr()](../Libraries_Manual_guide/node0206.html) to ask the integer gadget its value.  If this value is out
of range, it should explicitly set the value of the integer gadget to a
more suitable value using [SetGadgetAttrs()](../Libraries_Manual_guide/node0205.html#line5).

Using the [GACT_RELVERIFY](../Libraries_Manual_guide/node014B.html#line14) scheme above, an application will only hear about
changes to the gadgets after the user is finished changing them.  The
application does not hear all of the interim updates that, for example, a
prop gadget generates.  This is useful if an application only needs to
hear the final value and not the interim update.

It is also possible to make the IDCMP port of a Boopsi gadget's window the
[ICA_TARGET](../Libraries_Manual_guide/node020B.html#line20) of the gadget.  There is a special value for ICA_TARGET called
ICTARGET_IDCMP (defined in <intuition/[icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line35)>). This tells the gadget
to send an [IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) class [IntuiMessage](../Libraries_Manual_guide/node01D9.html) to its window's IDCMP
port.  Of course, the window has to be set up to listen for
IDCMP_IDCMPUPDATE IntuiMessages.  The Boopsi gadget passes an address in
the [IntuiMessage.IAddress](../Libraries_Manual_guide/node01D9.html#line73) field.  It points to an attribute tag list
containing the attribute (and its new value) that triggered the
IDCMP_IDCMPUPDATE message.  An application can use the utility.library tag
functions to access the gadget's attributes in this list.  Using this
scheme, an application will hear all of the interim gadget updates.  If
the application is using a gadget that generates a lot of interim
[OM_UPDATE](../Libraries_Manual_guide/node0211.html#line32) messages (like a prop gadget), the application should be
prepared to handle a lot of messages.

Using this [IDCMP_IDCMPUPDATE](../Libraries_Manual_guide/node01E1.html#line98) scheme, if the gadget uses an [ICA_MAP](../Libraries_Manual_guide/node020B.html#line63) to map
the attribute to a special dummy attribute ICSPECIAL_CODE (defined in
<intuition/[icclass.h](../Includes_and_Autodocs_2._guide/node00DB.html#line26)>), the [IntuiMessage.Code](../Libraries_Manual_guide/node01D9.html#line33) field will contain the value
of the attribute.  Because the attribute's value is a 32-bit quantity and
the IntuiMessage.Code field is only 16 bits wide, only the least
significant 16 bits of the attribute will appear in the IntuiMessage.Code
field, so it can't hold a 32-bit quantity, like a pointer.  Applications
should only use the lower 16 bits of the attribute value.

