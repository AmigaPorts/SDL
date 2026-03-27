/* Source: ADCD 2.1
 * Section: dos-library-datestamp
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-datestamp.md
 */

    DateStamp() takes a structure of three longwords that is set to the
    current time.  The first element in the vector is a count of the
    number of days.  The second element is the number of minutes elapsed
    in the day.  The third is the number of ticks elapsed in the current
    minute.  A tick happens 50 times a second.  DateStamp() ensures that
    the day and minute are consistent.  All three elements are zero if
    the date is unset. DateStamp() currently only returns even
    multiples of 50 ticks.  Therefore the time you get is always an even
    number of ticks.

    Time is measured from Jan 1, 1978.
