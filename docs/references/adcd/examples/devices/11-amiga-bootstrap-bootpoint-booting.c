/* Source: ADCD 2.1
 * Section: 11-amiga-bootstrap-bootpoint-booting
 * Library: devices
 * ADCD reference: devices/11-amiga-bootstrap-bootpoint-booting.md
 */

       a) The address of the boot routine is calculated from da_BootPoint.

       b) The resulting boot routine is invoked with the [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line32) pointer
          on the stack in C fashion (i.e., (*boot)(configDev);). Moreover,
          register A2 will contain the address of the associated
          eb_MountList node.
