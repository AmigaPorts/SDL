/* Source: ADCD 2.1
 * Section: 37-utility-library-date-functions
 * Library: libraries
 * ADCD reference: libraries/37-utility-library-date-functions.md
 */

    struct ClockData
    {
        UWORD sec;     /* seconds (0 - 59)*/
        UWORD min;     /* minutes (0 - 59) */
        UWORD hour;    /* hour (0 - 23) */
        UWORD mday;    /* day of the month (1 - 31) */
        UWORD month;   /* month of the year (1 - 12)
        UWORD year;    /* 1978 - */
        UWORD wday;    /* day of the week (0 - 6, where 0 is Sunday) */
    };
