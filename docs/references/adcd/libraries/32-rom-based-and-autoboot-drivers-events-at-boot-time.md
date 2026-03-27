---
title: 32 / / ROM Based and Autoboot Drivers / Events At BOOT Time
manual: libraries
chapter: libraries
section: 32-rom-based-and-autoboot-drivers-events-at-boot-time
functions: [Enqueue, FindResident]
libraries: [exec.library]
---

# 32 / / ROM Based and Autoboot Drivers / Events At BOOT Time

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If there is no boot disk in the internal floppy drive, the system strap
module will call a routine to perform [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md). It will examine the
[eb_MountList](autodocs-2.0/includes-libraries-expansionbase-h.md); find the highest priority [BootNode](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md) structure at the head of
the List; validate the BootNode; determine which [ConfigDev](libraries/32-expansion-library-the-expansion-sequence.md) is associated
with this BootNode; find its [DiagArea](libraries/32-rom-based-and-autoboot-drivers-events-at-diag-time.md); and call its da_BootPoint function
in the ROM "image" to bootstrap the appropriate DOS.  Generally, the
BootPoint code of a ROM driver will perform the same function as the boot
code installed on a floppy disk, i.e., it will [FindResident()](autodocs-2.0/exec-library-findresident.md) the
dos.library, and jump to its RT_INIT vector.  The da_BootPoint call, if
successful, should not return.

If a boot disk is in the internal floppy drive, the system strap will
[Enqueue()](libraries/23-list-functions-prioritized-insertion.md) a [BootNode](libraries/32-rom-based-and-autoboot-drivers-events-at-romtag-init-time.md) on the [eb_MountList](autodocs-2.0/includes-libraries-expansionbase-h.md) for DF0: at the suggested
priority (see the Autodoc for the expansion.library [AddDosNode()](autodocs-2.0/expansion-library-adddosnode.md)
function).  Strap will then open AmigaDOS, overriding the [autoboot](libraries/32-expansion-board-drivers-rom-based-and-autoboot-drivers.md).
AmigaDOS will boot from the highest priority node on the eb_MountList
which should, in this case, be DF0:.  Thus, games and other bootable
floppy disks will still be able to obtain the system for their own use.

In the event that there is no boot disk in the internal floppy drive and
there are no ROM bootable devices on the autoconfiguration chain, the
system does the normal thing, asking the user to insert a Workbench disk,
and waiting until its request is satisfied before proceeding.

---

## See Also

- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [FindResident — exec.library](../autodocs/exec.library.md#findresident)
