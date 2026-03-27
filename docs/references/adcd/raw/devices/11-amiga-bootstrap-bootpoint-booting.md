# 11 / Amiga BootStrap / Bootpoint Booting


BootPoint booting follows this sequence:

   1. The eb_MountList node must contain a valid BootPoint:


```c
       a) [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line32) pointer (in ln_Name) is non-zero,

       b) diagnostic area pointer (in cd_Rom er_Reserved0c) is non-zero,

       c) DAC_CONFIGTIME set in da_Config.
```
   2. The boot routine of a valid boot node is invoked as follows:


```c
       a) The address of the boot routine is calculated from da_BootPoint.

       b) The resulting boot routine is invoked with the [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line32) pointer
          on the stack in C fashion (i.e., (*boot)(configDev);). Moreover,
          register A2 will contain the address of the associated
          eb_MountList node.
```
   3. Return from the boot routine indicates failure to boot.

If all entries fail to boot, the user is prompted to put a bootable disk
into a floppy drive with the "strap screen".  The system floppy drives
are polled for new disks.  When one appears, the "strap screen" is removed
and the appropriate boot mechanism is applied as described above.  The
process of prompting and trying continues till a successful boot occurs.

