# 11 SCSI Device / Amiga BootStrap


At priority -40 in the system module initialization sequence, after most
other modules are initialized, appropriate expansion boards are
configured.  Appropriate boards will match a [FindConfigDev](../Includes_and_Autodocs_2._guide/node03B4.html)(, -1,-1)
 - these are all boards on the expansion library board list.
Furthermore, they will meet all of the following conditions:

   1. CDB_CONFIGME set in cd_Flags,

   2. ERTB_DIAGVALID set in cd_Rom->er_Type,

   3. diagnostic area pointer (in cd_Rom->er_Reserved0c) is non-zero,

   4. DAC_CONFIGTIME set in da_Config, and

   5. at least one valid resident tag within the diagnostic area, the first

```c
      of which is used by [InitResident()](../Includes_and_Autodocs_2._guide/node035C.html) below.  This resident structure
      was patched to be valid during the ROM diagnostic routine run when
      the expansion library first initialized the board.
```
Boards meeting all these conditions are initialized with the standard
[InitResident()](../Includes_and_Autodocs_2._guide/node035C.html) mechanism, with a NULL SegList.  The board initialization
code can find its [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line32) structure with the expansion library's
[GetCurrentBinding()](../Includes_and_Autodocs_2._guide/node03B7.html) function.  This is an appropriate time for drivers to
[Enqueue()](../Includes_and_Autodocs_2._guide/node034D.html) a boot node on the expansion library's eb_MountList for use by
the strap module below, and clear CDB_CONFIGME so a C:BindDrivers command
will not try to initialize the board a second time.

This module will also enqueue nodes for 3.5" trackdisk device
units.  These nodes will be at the following priorities:


                           Priority     Drive
                           --------     -----
                             5          df0:
                           -10          df1:
                           -20          df2:
                           -30          df3:
Next, at priority -60 in the system module initialization sequence, the
strap module is invoked.  Nodes from the prioritized eb_MountList list is
used in priority order in attempts to boot. An item on the list is given a
chance to boot via one of two different mechanisms, depending on whether
it it uses boot code read in off the disk ([BootBlock booting](../Devices_Manual_guide/node007D.html)), or uses
boot code provided in the device [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line32) diagnostic area
([BootPoint booting](../Devices_Manual_guide/node007E.html)).  Floppies always use the BootBlock method.  Other
entries put on the eb_MountList (e.g. hard disk partitions) used the
BootPoint mechanism for pre-V36 Kickstart, but can use either for V36/V37.

The eb_MountList is modified before each boot attempt, and then
restored and re-modified for the next attempt if the boot fails:

   1. The node associated with the current boot attempt is placed at the

      head of the eb_MountList.
   2. Nodes marked as unusable under AmigaDOS are removed from the list.

      Nodes that are unusable are marked by the longword
      bn_DeviceNode->dn_Handler having the most significant bit set.  This
      is used, for example, to keep UNIX partitions off the AmigaDOS device
      list when booting AmigaDOS instead of UNIX.
The selection of which of the two different boot mechanisms to use
proceeds as follows:

   1. The node must be valid boot node, i.e. meet both of the following

```c
      conditions:

       a) ln_Type is NT_BOOTNODE,
       b) bn_DeviceNode is non-zero,
```
   2. The type of boot is determined by looking at the DosEnvec pointed to

```c
      by fssm_Environ pointed to by the dn_Startup in the bn_DeviceNode:

       a) if the de_TableSize is less than DE_BOOTBLOCKS, or the
          de_BootBlocks entry is zero, BootPoint booting is specified,
          otherwise

       b) de_BootBlocks contains the number of blocks to read in from
          the beginning of the partition, checksum, and try to boot from.
```
 [Bootblock Booting](../Devices_Manual_guide/node007D.html) 
 [Bootpoint Booting](../Devices_Manual_guide/node007E.html) 

