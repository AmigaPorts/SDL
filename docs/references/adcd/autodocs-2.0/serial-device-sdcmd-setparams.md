---
title: serial.device/SDCMD_SETPARAMS
manual: autodocs-2.0
chapter: autodocs-2.0
section: serial-device-sdcmd-setparams
functions: []
libraries: []
---

# serial.device/SDCMD_SETPARAMS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    SetParams -- change parameters for the serial port
FUNCTION
```c
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
       and 7WIRE bits of io_SerFlags can be used in [OpenDevice](autodocs-2.0/serial-device-opendevice.md) calls.
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
```
   10. 7WIRE (CTS/RTS) handshake is bi-directional.  The external side


        is expected to drop CTS several character times before the external
        buffer is full.  The Amiga will drop RTS several character times
        before the Amiga's buffer is full.
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       preset by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Unit         preset by [OpenDevice](autodocs-2.0/serial-device-opendevice.md)
    io_Command      SDCMD_SETPARAMS (0x0B)
                     NOTE that the following fields are filled in by Open
                    to reflect the serial device's current configuration.
    io_CtlChar      a longword containing byte values for the
                    xON,xOFF,INQ,ACK fields (respectively)
                    (INQ/ACK not used at this time)
    io_RBufLen      length in bytes of input buffer
                     NOTE that any change in buffer size causes the
                    current buffer to be deallocated and a new,
                    correctly sized one to be allocated. Thusly,
                    the CONTENTS OF THE OLD BUFFER ARE LOST.
    io_ExtFlags     additional serial flags (bitdefs in [devices/serial.h)](autodocs-2.0/includes-devices-serial-h.md)
                     mark & space parity may be specified here.
    io_Baud         baud rate for reads AND writes. (See 1 above)
    io_BrkTime      duration of break signal in MICROseconds
    io_TermArray    ASCII descending-ordered 8-byte array of
                    termination characters. If less than 8 chars
                    used, fill out array w/lowest valid value.
                    Terminators are checked only if EOFMODE bit of
                    io_Serflags is set. (e.g. x512F040303030303 )
    io_ReadLen      number of bits in read word (1-8) not including parity
    io_WriteLen     number of bits in write word (1-8) "      "       "
    io_StopBits     number of stop bits (0, 1 or 2)
    io_SerFlags     see [devices/serial.h](autodocs-2.0/includes-devices-serial-h.md) for bit equates, NOTE that x00
                    yields exclusive access, xON/OFF-enabled, no
                    parity checking, 3-wire protocol and TermArray
                    inactive.
```
RESULTS

    Error -- if the SetParams succeded, then Error will be null.
        If the SetParams failed, then the Error will be non-zero.
SEE ALSO

```c
    [exec/OpenDevice](autodocs-2.0/serial-device-opendevice.md)
```
