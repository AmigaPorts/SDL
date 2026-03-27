---
title: audio.device/OpenDevice
manual: autodocs-2.0
chapter: autodocs-2.0
section: audio-device-opendevice
functions: []
libraries: []
---

# audio.device/OpenDevice

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    OpenDevice - open the audio device
SYNOPSIS

```c
    error = OpenDevice("audio.device", unitNumber, iORequest, flags);
```
FUNCTION

```c
    The OpenDevice routine grants access to the audio device.  It takes an
    I/O audio request block (iORequest) and if it can successfully open
    the audio device, it loads the device pointer (io_Device) and the
    allocation key (ioa_AllocKey); otherwise, it returns an error
    (IOERR_OPENFAIL).  OpenDevice increments the open count keeping the
    device from being expunged (Expunge).  If the length (ioa_Length) is
    non-zero, OpenDevice tries to allocate (ADCMD_ALLOCATE) audio channels
    from a array of channel combination options (ioa_Data). If the
    allocation succeeds, the allocated channel combination is loaded into
    the unit field (ioa_Unit); otherwise, OpenDevice returns an error
    (ADIOERR_ALLOCFAILED).  OpenDevice does not wait for allocation to
    succeed and closes (CloseDevice) the audio device if it fails.  To
    allocate channels, OpenDevice also requires a properly initialized
    reply port (mn_ReplyPort) with an allocated signal bit.
```
INPUTS

```c
    unitNumber- not used
    iORequest - pointer to audio request block (struct IOAudio)
            ln_Pri      - allocation precedence (-128 thru 127), only
                          necessary for allocation (non-zero length)
            mn_ReplyPort- pointer to message port for allocation, only
                          necessary for allocation (non-zero length)
            ioa_AllocKey- allocation key; zero to generate new key.
                          Otherwise, it must be set by (or copied from I/O
                          block that is set by) previous OpenDevice
                          function or [ADCMD_ALLOCATE](autodocs-2.0/audio-device-adcmd-allocate.md) command (non-zero
                          length)
            ioa_Data    - pointer to channel combination options (byte
                          array, bits 0 thru 3 correspond to channels 0
                          thru 3), only necessary for allocation (non-zero
                          length)
            ioa_Length  - length of the channel combination option array
                          (0 thru 16), zero for no allocation
    flags     - not used
```
OUTPUTS

```c
    iORequest - pointer to audio request block (struct IOAudio)
            io_Device   - pointer to device node if OpenDevice succeeds,
                          otherwise -1
            io_Unit     - bit map of successfully allocated channels (bits
                          0 thru 3 correspond to channels 0 thru 3)
            io_Error    - error number:
                          0                   - no error
                          IOERR_OPENFAIL      - open failed
                          ADIOERR_ALLOCFAILED - allocation failed, no open
            ioa_AllocKey- allocation key, set to a unique number if passed
                          a zero and OpenDevice succeeds
    error     - copy of io_Error
```
