/* Source: ADCD 2.1
 * Section: 21-processor-and-cache-control-the-68040-and-cpu-caches
 * Library: libraries
 * ADCD reference: libraries/21-processor-and-cache-control-the-68040-and-cpu-caches.md
 */

    extern struct ExecBase *SysBase;
    . . .

    /* If we are in 2.0, call CacheClearU() before CreateProc() */
    if (SysBase->LibNode.lib_Version >= 37) CacheClearU();

    /* Now do the CreateProc() call... */
    proc=CreateProc(... /* whatever your call is like */ ...);
    . . .
