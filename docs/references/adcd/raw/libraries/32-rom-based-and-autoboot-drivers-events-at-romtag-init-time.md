# 32 / / ROM Based and Autoboot Drivers / Events At ROMTAG INIT Time


Next, most resident system modules (for example graphics) are initialized.
As part of the system initialization procedure a search is made of the
expansion.library's private list of boards (which contains a [ConfigDev](../Libraries_Manual_guide/node0416.html#line6)
structure for each of the AUTOCONFIG hardware boards). If the [cd_Flags](../Libraries_Manual_guide/node0416.html#line15)
specify CONFIGME and the [er_Type](../Libraries_Manual_guide/node0416.html#line52) specifies [DIAGVALID](../Libraries_Manual_guide/node041C.html#line6), the system
initialization will do three things:

First, it will set the current [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) as the current binding (see the
expansion.library [SetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03BE.html) function).  Second, it will check
the [DiagArea](../Libraries_Manual_guide/node041C.html#line29)'s da_Config flag to make sure that the [CONFIGTIME](../Libraries_Manual_guide/node041C.html#line55) bit is set.
Third, it will search the ROM "image" associated with this hardware board
for a valid [Resident](../Libraries_Manual_guide/node0298.html) structure (<exec/[resident.h](../Includes_and_Autodocs_2._guide/node00A0.html#line19)>); and, if one is
located, will call [InitResident()](../Libraries_Manual_guide/node0419.html#line28) on it, passing a NULL segment list
pointer as part of the call.

Next, the board's device driver is initialized.  The [Resident](../Libraries_Manual_guide/node0298.html) structure
associated with this board's device driver (which has now been patched by
the ROM/diagnostic routine) should follow standard system conventions in
initializing the device driver provided in the boot ROMs.  This driver
should obtain the address of its associated [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) structure via
[GetCurrentBinding()](../Libraries_Manual_guide/node0419.html#line28).

Once the driver is initialized, it is responsible for some further steps.
It must clear the CONFIGME bit in the cd_Flags of its [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) structure,
so that the system knows not to configure this device again if binddrivers
is run after bootstrap.  Also, though it is not currently mandatory, the
driver should place a pointer to its Exec node in the cd_Driver field of
the ConfigDev structure.  This will generally be a device (NT_DEVICE)
node.  And for this device to be bootable, the driver must create a
[BootNode](../Includes_and_Autodocs_2._guide/node00FA.html#line31) structure, and link this BootNode onto the expansion.library's
[eb_MountList](../Includes_and_Autodocs_2._guide/node00FA.html#line45).

The BootNode structure (see <libraries/[expansionbase.h](../Includes_and_Autodocs_2._guide/node00FA.html#line31)>) contains a Node
of the new type NT_BOOTNODE (see <exec/[nodes.h](../Includes_and_Autodocs_2._guide/node0091.html#line60)>).  The driver must
initialize the ln_Name field to point to the [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) structure which it
has obtained via the [GetCurrentBinding()](../Libraries_Manual_guide/node0419.html#line28) call.  The bn_Flags subfield is
currently unused and should be initialized to NULL.  The bn_DeviceNode
must be initialized to point to the DosNode for the device.

When the DOS is initialized later, it will attempt to boot from the first
[BootNode](../Includes_and_Autodocs_2._guide/node00FA.html#line31) on the [eb_MountList](../Includes_and_Autodocs_2._guide/node00FA.html#line45).  The eb_MountList is a priority sorted List,
with nodes of the highest priority at the head of the List.  For this
reason, the device driver must enqueue a BootNode onto the list using the
Exec library function [Enqueue()](../Libraries_Manual_guide/node02E2.html).

In the case of an [autoboot](../Libraries_Manual_guide/node041B.html) of AmigaDOS, the [BootNode](../Includes_and_Autodocs_2._guide/node00FA.html#line31) must be linked to a
DeviceNode of the AmigaDOS type (see <libraries/[filehandler.h](../Includes_and_Autodocs_2._guide/node0100.html)>), which the
driver can create via the expansion library [MakeDosNode()](../Libraries_Manual_guide/node041A.html) function call.
When the DOS "wakes up", it will attempt to boot from this DeviceNode.

