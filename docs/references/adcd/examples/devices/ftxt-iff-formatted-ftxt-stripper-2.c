/* Source: ADCD 2.1
 * Section: ftxt-iff-formatted-ftxt-stripper
 * Library: devices
 * ADCD reference: devices/ftxt-iff-formatted-ftxt-stripper.md
 */

    BEGIN
    WHILE something left to read in the LIST or CAT
    DO BEGIN
       read the next chunk header;
       CASE the chunk's ID OF
             "LIST", "CAT ": ReadCAT4CHRS();
             "FORM": ReadFORM4CHRS();
             "PROP": IF we're reading a LIST AND the PROP's subtype = "FTXT"
                    THEN read the PROP for "FONS" chunks;
             OTHERWISE error--malformed IFF file;
          END
       END
    END;
