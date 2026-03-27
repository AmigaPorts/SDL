/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    UBYTE *bstr, *str, *s;
    int c;

    bstr = BADDR(b);
    str = s = (UBYTE*) calloc(1, (c = *bstr++) + 1);
    while(c--)
        *s++ = *bstr++;

    return str;
