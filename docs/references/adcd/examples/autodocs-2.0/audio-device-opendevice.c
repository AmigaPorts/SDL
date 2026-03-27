/* Source: ADCD 2.1
 * Section: audio-device-opendevice
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/audio-device-opendevice.md
 */

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
