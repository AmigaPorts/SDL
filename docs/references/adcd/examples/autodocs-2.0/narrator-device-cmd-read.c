/* Source: ADCD 2.1
 * Section: narrator-device-cmd-read
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/narrator-device-cmd-read.md
 */

    Currently, there are three events which the user can inquire
    about from the narrator device.  These are: mouth shape changes,
    start of word, and start of syllable.  Each read request returns
    information about any or all of these events as determined by
    the bits set in the sync field of the read [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.  In
    the case of mouth shape changes, each shape returned is guaranteed
    to be different from the previously returned shape to allow
    updating to be done only when necessary.  Each read request is
    associated with a write request by information contained in the
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block used to open the device.  Since the first field
    in the read [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block is a write [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) structure, this
    association is easily made by copying the write [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block
    (after the [OpenDevice](../Includes_and_Autodocs_2._guide/node04C8.html) call) into the voice field of the read
    [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block.  If there is no write in progress or in the
    device input queue with the same pseudo unit number as the read
    request, the read will be returned to the user with an error.  This
    is also how the user knows that the write request has finished and
    that s/he should not issue any more reads.  Note that in this case
    the mouth shapes may not be different from previously returned values.
