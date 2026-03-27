/* Source: ADCD 2.1
 * Section: amiga-lib-invertstring
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-invertstring.md
 */

    This function returns a linked list of input events which would
    translate into the string using the supplied keymap (or the system
    default keymap if 'km' is NULL).

    'str' is null-terminated and may contain:
       - ANSI character codes
       - backslash escaped characters:
            n   -   CR
            r   -   CR
            t   -   TAB
            0   -   illegal, do not use!
            \   -   backslash
       - a text description of an input event as used by [ParseIX()](../Includes_and_Autodocs_2._guide/node01AF.html),
         enclosed in angle brackets.

    An example is:

      abc<alt f1>nhi there.
