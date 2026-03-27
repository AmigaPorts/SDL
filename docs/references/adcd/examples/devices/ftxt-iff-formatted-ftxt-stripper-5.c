/* Source: ADCD 2.1
 * Section: ftxt-iff-formatted-ftxt-stripper
 * Library: devices
 * ADCD reference: devices/ftxt-iff-formatted-ftxt-stripper.md
 */

    BEGIN
    IF the document FORM's subtype = "FTXT"
        THEN ReadFTXT4CHRS()
    ELSE WHILE something left to read in the FORM
         DO BEGIN
            read the next chunk header;
