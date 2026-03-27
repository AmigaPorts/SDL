/* Source: ADCD 2.1
 * Section: 31-commodities-exchange-library-commodity-tool-types
 * Library: libraries
 * ADCD reference: libraries/31-commodities-exchange-library-commodity-tool-types.md
 */

    tooltypearray = UBYTE **ArgArrayInit(LONG argc, UBYTE **argv);
                    void    ArgArrayDone(void);

    tooltypevalue = STRPTR  ArgString(UBYTE **tooltypearray,
                                      STRPTR tooltype,
                                      STRPTR defaultvalue);
    tooltypevalue = LONG  *ArgInt(UBYTE **tooltypearray,
                                  STRPTR tooltype,
                                  LONG defaultvalue);
