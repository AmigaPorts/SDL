/* Source: ADCD 2.1
 * Section: 3-device-interface-writing-to-the-clipboard-device
 * Library: devices
 * ADCD reference: devices/3-device-interface-writing-to-the-clipboard-device.md
 */

    LONG slen = strlen ("Enterprise");
    BOOL odd = (slen & 1);      /* pad byte flag */

    /* set length depending on whether string is odd or even length */
    LONG length = (odd) ? slen + 1 : slen;

    /* Reset the clip id */
    ClipIO->io_ClipID = 0;
    ClipIO->io_Offset = 0;

    error = writeLong ((LONG *) "FORM");/* "FORM" */

    /* add 12 bytes for FTXT,CHRS & length byte to string length */
    length += 12;
    error = writeLong (&length);
    error = writeLong ((LONG *) "FTXT");/* "FTXT" for example */
    error = writeLong ((LONG *) "CHRS");/* "CHRS" for example */
    error = writeLong (&slen);      /* #  (length of string) */

    ClipIO->io_Command = CMD_WRITE;
    ClipIO->io_Data = (char *) string;
    ClipIO->io_Length = slen;               /* length of string */
    error = (LONG) DoIO (clipIO);   /* text string */

    LONG writeLong (LONG * ldata)
    {
        ClipIO->io_Command = CMD_WRITE;
        ClipIO->io_Data = (char *) ldata;
        ClipIO->io_Length = 4L;
        return ( (LONG) DoIO (clipIO) );
    }
