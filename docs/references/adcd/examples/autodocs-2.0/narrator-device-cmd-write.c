/* Source: ADCD 2.1
 * Section: narrator-device-cmd-write
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/narrator-device-cmd-write.md
 */

    The narrator device range checks and performs other validity
    checks for all input parms.  If any input is in error, the device
    sets the io_Error field of the [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block to an appropriate
    value (see include files for error codes).  If everything is in
    order, the narrator device will produce the speech and clear the
    io_Error field.  The io_Actual field is set to the length of the
    input string that was actually processed.  If the return code
    indicates a phoneme error (ND_PhonErr), io_Actual is the NEGATIVE
    of the position in the input string where the error occured.
