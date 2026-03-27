/* Source: ADCD 2.1
 * Section: exec-library-sendio
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-sendio.md
 */

    This function requests the device driver start processing the given
    I/O request.  The device will return control without waiting for
    the I/O to complete.

    The io_Flags field of the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) will be set to zero before the
    request is sent.  See [BeginIO()](../Includes_and_Autodocs_2._guide/node04CB.html) for more details.
