# 32 / / ROM Based and Autoboot Drivers / Events At BOOT Time


If there is no boot disk in the internal floppy drive, the system strap
module will call a routine to perform [autoboot](../Libraries_Manual_guide/node041B.html). It will examine the
[eb_MountList](../Includes_and_Autodocs_2._guide/node00FA.html#line45); find the highest priority [BootNode](../Libraries_Manual_guide/node041D.html#line22) structure at the head of
the List; validate the BootNode; determine which [ConfigDev](../Libraries_Manual_guide/node0416.html#line6) is associated
with this BootNode; find its [DiagArea](../Libraries_Manual_guide/node041C.html#line29); and call its da_BootPoint function
in the ROM "image" to bootstrap the appropriate DOS.  Generally, the
BootPoint code of a ROM driver will perform the same function as the boot
code installed on a floppy disk, i.e., it will [FindResident()](../Includes_and_Autodocs_2._guide/node0350.html) the
dos.library, and jump to its RT_INIT vector.  The da_BootPoint call, if
successful, should not return.

If a boot disk is in the internal floppy drive, the system strap will
[Enqueue()](../Libraries_Manual_guide/node02E2.html) a [BootNode](../Libraries_Manual_guide/node041D.html#line22) on the [eb_MountList](../Includes_and_Autodocs_2._guide/node00FA.html#line45) for DF0: at the suggested
priority (see the Autodoc for the expansion.library [AddDosNode()](../Includes_and_Autodocs_2._guide/node03B0.html)
function).  Strap will then open AmigaDOS, overriding the [autoboot](../Libraries_Manual_guide/node041B.html).
AmigaDOS will boot from the highest priority node on the eb_MountList
which should, in this case, be DF0:.  Thus, games and other bootable
floppy disks will still be able to obtain the system for their own use.

In the event that there is no boot disk in the internal floppy drive and
there are no ROM bootable devices on the autoconfiguration chain, the
system does the normal thing, asking the user to insert a Workbench disk,
and waiting until its request is satisfied before proceeding.

