/* Source: ADCD 2.1
 * Section: ftxt-iff-formatted-ftxt-stripper
 * Library: devices
 * ADCD reference: devices/ftxt-iff-formatted-ftxt-stripper.md
 */

    BEGIN
    WHILE something left to read in the FORM FTXT
    DO BEGIN
       read the next chunk header;
       CASE the chunk's ID OF
          "CHRS": ReadCHRS();
          "FONS": BEGIN
                   read the chunk's contents into a FontSpecifier variable;
                   IF the font specifier's id = 1
                   THEN use this font;
                  END;
            OTHERWISE skip the chunk's body;
        END
      END
    END;
