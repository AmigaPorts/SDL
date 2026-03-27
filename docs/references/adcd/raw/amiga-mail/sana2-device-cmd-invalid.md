# sana2.device/CMD_INVALID


NAME

    Invalid -- Return with error IOERR_NOCMD.
FUNCTION

    This command causes device driver to reply with an error IOERR_NOCMD
    as defined in <exec/errors.h> indicating the command is not supported.
IO REQUEST

    ios2_Command    - CMD_INVALID.
RESULTS

    ios2_Error      - IOERR_NOCMD.
NOTES

SEE ALSO

BUGS

    Not known to be useful.
