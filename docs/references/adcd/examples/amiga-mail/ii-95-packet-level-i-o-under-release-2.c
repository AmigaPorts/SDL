/* Source: ADCD 2.1
 * Section: ii-95-packet-level-i-o-under-release-2
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-95-packet-level-i-o-under-release-2.md
 */

        . . .

        my_pkt->dp_Type = ACTION_READ;
        my_pkt->dp_Arg1 = ((struct FileHandle *)BADDR(myfh))->fh_Arg1;
        my_pkt->dp_Arg2 = buffer;
        my_pkt->dp_Arg3 = BUFSIZE;

        . . .
