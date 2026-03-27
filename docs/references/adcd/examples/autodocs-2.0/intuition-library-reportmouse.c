/* Source: ADCD 2.1
 * Section: intuition-library-reportmouse
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-reportmouse.md
 */

    Some compilers and link files switch the arguments to this function
    about in unpredictable ways.  We apologize for this confusion
    wrapped around an error enclosing a mistake.
    The call will take one of two forms:

            ReportMouse(Boolean, Window);
                    -or-
            ReportMouse(Window, (ULONG)Boolean);

    The first form is the one that corresponds to the amiga.lib supplied
    by Commodore.  The linker libraries and "pragmas" of some compilers
    supply the alternate form.

    A key point to remember is that the form of the function in ROM
    has always been the same, so there has always been object code
    compatibility.  However some care should be taken when switching
    compilers or switching between stubs and pragmas.

    From assembler the interface has always been:
            Boolean in D0, [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797) in A0

    Also, it is still endorsed to simply set the WFLG_REPORTMOUSE flag bit
    in Window->Flags, or reset it, on your own.  Make the operation
    an atomic assembly instruction (OR.W #WFLG_REPORTMOUSE,wd_Flags+2(A0)
    where A0 contains your window pointer).  Most compilers will produce
    an atomic operation when faced with:
                    Window->Flags |= WFLG_REPORTMOUSE;
                    Window->Flags &=~WFLG_REPORTMOUSE;
    or else bracket the operation between [Forbid()/Permit()](../Includes_and_Autodocs_2._guide/node0369.html).
