/* Source: ADCD 2.1
 * Section: intuition-library-buildeasyrequestargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-buildeasyrequestargs.md
 */

    A pointer to the system request window opened.  In the event
    of problems, you may also be returned the value '0' which
    is to be interpreted as the "FALSE, Cancel" choice, or
    (if you have a second gadget defined) the value '1', which
    is to be taken to mean the equivalent of your corresponding
    left-most gadget.

    If there is a problem creating the window, a recoverable alert may
    be substituted for the requester, and the result, either 0 or 1,
    returned.
