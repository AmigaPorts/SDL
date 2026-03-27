/* Source: ADCD 2.1
 * Section: ftxt-iff-formatted-ftxt-stripper
 * Library: devices
 * ADCD reference: devices/ftxt-iff-formatted-ftxt-stripper.md
 */

    BEGIN
    WHILE something left to read in the CHRS chunk
    DO
       CASE read the next character OF
          LF:  start a new output line;
          ESC: SkipControl([' '..'/'], ['0'..'~']);
          IN [' '..'~'], IN [NBSP..'ÿ']: output the character;
          SS2, SS3: ; {Just handle the following G0 character directly,
                      ignoring the shift to G2 or G3.}
          CSI: SkipControl([' '..'?'], ['@'..'~']);
            DCS, OSC, PM, APC: SkipControl([' '..'~'] + [NBSP..'ÿ'], [ST]);
       END
    END;
