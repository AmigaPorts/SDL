/* Source: ADCD 2.1
 * Section: trackdisk-device-td-seek
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/trackdisk-device-td-seek.md
 */

    These commands are currently provided for internal diagnostics,
    disk repair, and head cleaning only.

    TD_SEEK and ETD_SEEK move the drive heads to the track specified. The
    io_Offset field should be set to the (byte) offset to which the seek is
    to occur. TD_SEEK and ETD_SEEK do not verify their position until the
    next read. That is, they only move the heads; they do not actually read
    any data.
