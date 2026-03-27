---
title: 32 / / ROM Based and Autoboot Drivers / Events At ROMTAG INIT Time
manual: libraries
chapter: libraries
section: 32-rom-based-and-autoboot-drivers-events-at-romtag-init-time
functions: [Enqueue, InitResident]
libraries: [exec.library]
---

# 32 / / ROM Based and Autoboot Drivers / Events At ROMTAG INIT Time

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Next, most resident system modules (for example graphics) are initialized.
As part of the system initialization procedure a search is made of the
expansion.library's private list of boards (which contains a [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md)
structure for each of the AUTOCONFIG hardware boards). If the [cd_Flags](libraries/32-expansion-library-the-expansion-sequence.md)
specify CONFIGME and the [er_Type](libraries/32-expansion-library-the-expansion-sequence.md) specifies [DIAGVALID](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md), the system
initialization will do three things:

First, it will set the current [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) as the current binding (see the
expansion.library [SetCurrentBinding()](autodocs-2.0/expansion-library-setcurrentbinding.md) function).  Second, it will check
the [DiagArea](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md)'s da_Config flag to make sure that the [CONFIGTIME](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md) bit is set.
Third, it will search the ROM "image" associated with this hardware board
for a valid [Resident](libraries/18-adding-a-library-resident-romtag-structure.md) structure (<exec/[resident.h](autodocs-2.0/includes-exec-resident-h.md)>); and, if one is
located, will call [InitResident()](libraries/32-expansion-board-drivers-disk-based-drivers.md) on it, passing a NULL segment list
pointer as part of the call.

Next, the board's device driver is initialized.  The [Resident](libraries/18-adding-a-library-resident-romtag-structure.md) structure
associated with this board's device driver (which has now been patched by
the ROM/diagnostic routine) should follow standard system conventions in
initializing the device driver provided in the boot ROMs.  This driver
should obtain the address of its associated [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure via
[GetCurrentBinding()](libraries/32-expansion-board-drivers-disk-based-drivers.md).

Once the driver is initialized, it is responsible for some further steps.
It must clear the CONFIGME bit in the cd_Flags of its [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure,
so that the system knows not to configure this device again if binddrivers
is run after bootstrap.  Also, though it is not currently mandatory, the
driver should place a pointer to its Exec node in the cd_Driver field of
the ConfigDev structure.  This will generally be a device (NT_DEVICE)
node.  And for this device to be bootable, the driver must create a
[BootNode](autodocs-2.0/includes-libraries-expansionbase-h.md) structure, and link this BootNode onto the expansion.library's
[eb_MountList](autodocs-2.0/includes-libraries-expansionbase-h.md).

The BootNode structure (see <libraries/[expansionbase.h](autodocs-2.0/includes-libraries-expansionbase-h.md)>) contains a Node
of the new type NT_BOOTNODE (see <exec/[nodes.h](autodocs-2.0/includes-exec-nodes-h.md)>).  The driver must
initialize the ln_Name field to point to the [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) structure which it
has obtained via the [GetCurrentBinding()](libraries/32-expansion-board-drivers-disk-based-drivers.md) call.  The bn_Flags subfield is
currently unused and should be initialized to NULL.  The bn_DeviceNode
must be initialized to point to the DosNode for the device.

When the DOS is initialized later, it will attempt to boot from the first
[BootNode](autodocs-2.0/includes-libraries-expansionbase-h.md) on the [eb_MountList](autodocs-2.0/includes-libraries-expansionbase-h.md).  The eb_MountList is a priority sorted List,
with nodes of the highest priority at the head of the List.  For this
reason, the device driver must enqueue a BootNode onto the list using the
Exec library function [Enqueue()](libraries/23-list-functions-prioritized-insertion.md).

In the case of an [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md) of AmigaDOS, the [BootNode](autodocs-2.0/includes-libraries-expansionbase-h.md) must be linked to a
DeviceNode of the AmigaDOS type (see <libraries/[filehandler.h](autodocs-2.0/includes-libraries-filehandler-h.md)>), which the
driver can create via the expansion library [MakeDosNode()](libraries/32-expansion-board-drivers-expansion-drivers-and-dos.md) function call.
When the DOS "wakes up", it will attempt to boot from this DeviceNode.

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [InitResident — exec.library](../autodocs/exec.library.md#initresident)
