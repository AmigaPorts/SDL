# 35 Math Libraries / Compile and Link Commands for SAS C 5.10


FFP Basic, Transcendental and Math Support functions
----------------------------------------------------


    lc -b1 -cfistq -ff -v -y <filename>.c
    blink lib:c.o + <filename>.o TO
        <filename> LIB lib:lcmffp.lib + lib:lc.lib + lib:amiga.lib
IEEE Single-Precision and Double-Precision Basic and Transcendental
Functions
-------------------------------------------------------------------

    lc -b1 -cfistq -fi -v -y <filename>.c
    blink lib:c.o + <filename>.o TO
         <filename> LIB lib:lcmieee.lib + lib:lc.lib + lib:amiga.lib
