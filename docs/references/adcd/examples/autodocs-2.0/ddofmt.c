/* Source: ADCD 2.1
 * Section: ddofmt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/ddofmt.md
 */

    FormatString - a "C"-language-like null terminated format
            string, with the following supported % types:
    DataStream - a stream of data that is interpreted according to
            the format string.
    PutChProc - the procedure to call with each character to be
            output, called as:
        PutChProc(Char,  PutChData);
                  D0-0:8 A3
            the procedure is called with a null Char at the end of
            the format string.
    PutChData - an address register that passes thru to PutChProc.
