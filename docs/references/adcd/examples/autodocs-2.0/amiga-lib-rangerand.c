/* Source: ADCD 2.1
 * Section: amiga-lib-rangerand
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-rangerand.md
 */

    RangeRand() accepts a value from 0 to 65535, and returns a value
    within that range.

    maxValue is passed on stack as a 32-bit integer but used as though
    it is only a 16-bit integer. Variable named RangeSeed is available
    beginning with V33 that contains the global seed value passed from
    call to call and thus can be changed in a program by declaring:

      extern ULONG RangeSeed;
