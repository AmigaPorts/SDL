/* Source: ADCD 2.1
 * Section: 17-libraries-and-devices-calling-a-library-function
 * Library: libraries
 * ADCD reference: libraries/17-libraries-and-devices-calling-a-library-function.md
 */

    /* This global declaration is here so amiga.lib can find
       the intuition.library base pointer.
    */
    struct Library *IntuitionBase;
            ...

    void main(void)
    {
            ...

            /* initialize IntuitionBase */
            if (IntuitionBase = OpenLibrary("intuition.library", 33L))
            {
                    ...

                    /* When this code gets linked with amiga.lib, the
                       linker extracts the DisplayBeep() stub routine from
                       from amiga.lib and copies it into the executable.
                       The stub copies whatever is in the variable
                       IntuitionBase into A6, and JSRs to
                       _LVODisplayBeep(A6).
                    */
                    DisplayBeep();
                    ...

                    CloseLibrary(IntuitionBase);
            }
            ...
    }
