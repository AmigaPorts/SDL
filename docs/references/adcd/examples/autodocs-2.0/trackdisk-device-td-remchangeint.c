/* Source: ADCD 2.1
 * Section: trackdisk-device-td-remchangeint
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/trackdisk-device-td-remchangeint.md
 */

    This command did not function properly under versions of Kickstart
    earlier than V36. A valid workaround under these older versions of
    Kickstart is:

            Forbid();
            Remove(ioRequest);
            Permit();

    Do not use this workaround in versions of Kickstart >= V36, use
    TD_REMCHANGEINT instead (for future compatibility with V38+).
