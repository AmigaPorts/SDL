/* Source: ADCD 2.1
 * Section: iii-11-68040-compatibility-warning
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-11-68040-compatibility-warning.md
 */

    . . .

    /* If we are in 2.0, call CacheClearU() before CreateProc() */
    if (SysBase->LibNode.lib_Version >= 37) CacheClearU();

    /* Now do the CreateProc() call... */
    proc=CreateProc(... /* whatever your call is like */ ...);

    . . .
