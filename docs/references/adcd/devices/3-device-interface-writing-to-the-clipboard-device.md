---
title: 3 / Device Interface / Writing To The Clipboard Device
manual: devices
chapter: devices
section: 3-device-interface-writing-to-the-clipboard-device
functions: []
libraries: []
---

# 3 / Device Interface / Writing To The Clipboard Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

You write to the clipboard device by passing an [IOClipReq](devices/3-clipboard-device-device-interface.md) to the device
with CMD_WRITE set in io_Command, the number of bytes to be written set in
io_Length and the address of the write buffer set in io_Data.


```c
    ClipIO->io_Data = (char *) data;
    ClipIO->io_Length = 4L;
    ClipIO->io_Command = CMD_WRITE;
```
An initial write should set io_Offset to zero.  Each time a write is done,
the device will increment io_Offset by the length of the write.

As previously stated, the data you write to the clipboard must be in IFF
format.  This requires a certain amount of preparation prior to actually
writing the data if it is not already in IFF format.  A brief explanation
of the IFF format will be helpful in this regard.

For our purposes, we will limit our discussion to a simple formatted text
(FTXT) IFF file.  An FTXT file looks like:


           FORM <length of succeeding bytes>
           FTXT
           CHRS <length of succeeding bytes>
                <data bytes>
                <pad byte of zero if the preceding chunk has odd length>

           Note: Uppercase characters above are literals.
Based on the above file format, a hex dump of an IFF FTXT file containing
 the string "Enterprise" would look like:


```c
           0000   464F524D  FORM
           0004   00000016  (length of FTXT, CHRS, 0xA and data)
           0008   46545854  FTXT
           000C   43485253  CHRS
           0010   0000000A  (length of Enterprise)
           0014   456E7465  Ente
           0018   72707269  rpri
           001C   7365      se
```
A code fragment for doing this:


```c
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
```
The fragment above does no error checking because it's a fragment.  You
should always error check.  See the example programs at the end of this
chapter for the proper method of error checking.

   Iffparse That Data!
   -------------------
   Keep in mind that the functions in the [iffparse.library](libraries/33-iffparse-library.md) can be used
   to write data to the clipboard. See the "[IFFParse Library](libraries/33-iffparse-library.md)" chapter
   of the Amiga ROM Kernel Reference Manual: Libraries for more
   information.

