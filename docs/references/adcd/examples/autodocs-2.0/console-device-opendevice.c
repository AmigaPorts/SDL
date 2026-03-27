/* Source: ADCD 2.1
 * Section: console-device-opendevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/console-device-opendevice.md
 */

    The open routine grants access to a device.  There are two
    fields in the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) block that will be filled in: the
    io_Device field and possibly the io_Unit field.

    As of (V37) the flags field may also be filled in with
    a value described below (see conunit.h or conunit.i).

    This open command differs from most other device open commands
    in that it requires some information to be supplied in the
    io_Data field of the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28) block.  This initialization
    information supplies the window that is used by the console
    device for output.

    The unit number that is a standard parameter for an open call
    is used specially by this device.  See conunit.h, or conunit.i
    for defined valid unit numbers.


    unit number: -1 (CONU_LIBRARY)

            Used to get a pointer to the device library vector
    which is returned in the io_Device field of the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28)
    block.  No actual console is opened.  You must still close
    the device when you are done with it.

    unit number: 0 (CONU_STANDARD)

            A unit number of zero binds the supplied window to
    a unique console.  Sharing a console must be done at a level
    higher than the device.


    unit number: 1 (CONU_CHARMAP) (V36)

            A unit number of one is similar to a unit number of
    zero, but a console map is also created, and maintained by
    the console.device.  The character map is used by the console
    device to restore obscured portions of windows which are
    revealed, and to redraw a window after a resize.  Character
    mapped console.device windows must be opened as SIMPLE REFRESH
    windows.

            The character map is currently for internal use
    only, and is not accessible by the programmer.  The character
    map stores characters, attributes, and style information for
    each character written with the [CMD_WRITE](../Includes_and_Autodocs_2._guide/node0508.html) command.

    unit number: 3 (CONU_SNIPMAP) (V36)

            A unit number of three is similar to a unit number
    of one, but also gives the user the ability to highlight
    text with the mouse which can be copied by pressing
    RIGHT AMIGA C.  See NOTES below.


    flags: 0 (CONFLAG_DEFAULT)

            The flags field should be set to 0 under V34, or less.

    flags: 1 (CONFLAG_NODRAW_ON_NEWSIZE) (V37)

            The flags field can be set to 0, or 1 as of V37.  The
    flags field is ignored under V36, so can be set, though it
    will have no effect.  When set to 1, it means that you don't
    want the console.device to redraw the window when the window
    size is changed (assuming you have opened the console.device
    with a character map - unit numbers 1, or 3).  This flag is
    ignored if you have opened a console.device with a unit
    number of 0.  Typically you would use this flag when you
    want to perform your own window refresh on a newsize, and
    you want the benefits of a character mapped console.
