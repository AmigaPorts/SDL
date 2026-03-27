/* Source: ADCD 2.1
 * Section: iii-1-ispy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-1-ispy-c.md
 */

    Write(Output(), (STRPTR) VerTitle, strlen((STRPTR) VerTitle));
    Write(Output(), Copyright, strlen(Copyright));

    if (SysBase->LibNode.lib_Version > 36)
    {
        if (IntuitionBase = OpenLibrary("intuition.library", 37))
        {
            if (GfxBase = OpenLibrary("graphics.library", 37))
            {
                if (InstallWedge())
                {
                    Write(Output(), CBreak, strlen(CBreak));
                    Wait(SIGBREAKF_CTRL_C);
                    RemoveWedge();
                }
                CloseLibrary(GfxBase);
            }
            else
                Write(Output(), "Couldn't open graphics.library\n", 31);
            CloseLibrary(IntuitionBase);
        }
        else
            Write(Output(), "Couldn't open intuition.library\n", 32);
    }
    else
        Write(Output(), "Requires at least Kickstart 2.04\n", 33);
