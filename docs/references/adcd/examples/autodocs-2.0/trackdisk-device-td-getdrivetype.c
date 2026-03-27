/* Source: ADCD 2.1
 * Section: trackdisk-device-td-getdrivetype
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/trackdisk-device-td-getdrivetype.md
 */

    This command returns the type of the disk drive to the user.
    This number will be a small integer and will come from the set of
    DRIVEXXX constants defined in [<devices/trackdisk.h>](../Includes_and_Autodocs_2._guide/node005B.html).

    The only way you can actually use this command is if the trackdisk
    device understands the drive type of the hardware that is plugged in.
    This is because the [OpenDevice()](../Includes_and_Autodocs_2._guide/node0366.html) call will fail if the trackdisk device
    does not understand the drive type. To find raw drive identifiers see
    the disk.resource's DR_GETUNITID entry point.
