/* Source: ADCD 2.1
 * Section: serial-device-sdcmd-setparams
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/serial-device-sdcmd-setparams.md
 */

    This command allows the caller to change parameters for the
    serial device. Except for xON-xOFF enable/disable, it will
    reject a setparams call if any reads or writes are active
    or pending.
       Note specifically:

    1. Valid input for io_Baud is between 112 and 292000 baud inclusive;
       asynchronous i/o above 32KB (especially on a busy system) may
       be ambitious.
    2. The EOFMODE and QUEUEDBRK bits of io_SerFlags can be set/reset
       in the io_Rqst block without a call to SetParams. The SHARED
       and 7WIRE bits of io_SerFlags can be used in [OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html) calls.
       ALL OTHER PARAMETERS CAN ONLY BE CHANGED BY THE SetParams
       COMMAND.
    3. RBufLen must be at least 64.  The buffer may be any multiple of
        64 bytes.
    4. If not used, io_ExtFlags MUST be set to zero.
    5. xON-xOFF is by default enabled. The XDISABLED bit is the only
       parameter that can be changed via a SetParams call while the
       device is active. Note that this will return the value
       SerErr_DevBusy in the io_Error field.

        xON/xOFF handshaking is inappropriate for certain binary transfer
        protocalls, such as Xmodem.  The binary data might contain the
        xON (ASCII 17) and xOFF (ASCII 19) characters.

    6. If trying to run MIDI, you should set the RAD_BOOGIE bit of
       io_SerFlags to eliminate unneeded overhead. Specifically, this skips
       checks for parity, x-OFF handling, character lengths other than
       8 bits, and testing for a break signal. Setting RAD_BOOGIE will
       also set the XDISABLED bit.
       Note that writing data (that's already in MIDI format) at MIDI rates
       is easily accomplished. Using this driver alone for MIDI reads may,
       however, may not be reliable, due to MIDI timestamping requirements,
       and possibility of overruns in a busy multitasking and/or display
       intensive environment.
    7. If you select mark or space parity (see io_ExtFlags in serial.h),
       this will cause the SERB_PARTY_ON bit to be set, and the setting
       of SERB_PARTY_ODD to be ignored.
    8. For best results, set the RAD_BOOGIE flag whenever possible.  See
        #6 for details.
    9. Note that at this time parity is *not* calculated for the xON-xOFF
        characters.  If you have a system that is picky about the parity of
        these, you must set your own xON-xOFF characters in io_CtlChar.
