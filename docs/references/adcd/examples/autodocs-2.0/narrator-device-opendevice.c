/* Source: ADCD 2.1
 * Section: narrator-device-opendevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/narrator-device-opendevice.md
 */

    The OpenDevice routine grants access to the narrator device.
    OpenDevice checks the unit number, and if non-zero, returns an
    error (ND_UnitErr).  If this is the first time the driver has
    been opened, OpenDevice will attempt to open the audio device
    and allocate the driver's static buffers.  If either of these
    operations fail, an error is returned.  See the .h and .i
    include files for possible error return codes.  Next, OpenDevice
    (done for all opens, not just the first one) initializes various
    fields in the user's [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block (see below).  If users wish
    to use non-default values for these parms, the values must be set
    after the open is done.  OpenDevice also assigns a pseudo unit
    number to the IORB for use in synchronizing read and write requests.
    See the read command for more details.  Finally, OpenDevice stores
    the device node pointer in the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block and clears the
    delayed expunge bit.

    ***** NEW FOR V37 NARRATOR *****

    Several new fields in the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block have been added for V37
    narrator.  These fields are initialized when the device is opened
    if the NDB_NEWIORB bit is set in the flags field of the user's
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.  Note that NDB_NEWIORB is set in the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19)
    block, NOT in the "flags" input parm to the OpenDevice call.
