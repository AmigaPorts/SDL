/* Source: ADCD 2.1
 * Section: 14-workbench-environment-wbstartup-message
 * Library: libraries
 * ADCD reference: libraries/14-workbench-environment-wbstartup-message.md
 */

    Workbench Locks Belong to Workbench.
    ------------------------------------
    You must never call [UnLock()](../Includes_and_Autodocs_2._guide/node0307.html) on a wa_Lock.  These locks belong to
    Workbench, and Workbench will UnLock() them when the WBStartup
    message is replied by your startup code.  You must also never
    UnLock() your program's initial current directory lock (i.e., the
    lock returned by an initial [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html) call).  The classic symptom
    caused by unlocking Workbench locks is a system hang after your
    program exits, even though the same program exits with no problems
    when started from the Shell.

    You should save the lock returned from an initial [CurrentDir()](../Includes_and_Autodocs_2._guide/node028F.html), and
    CurrentDir() back to it before exiting.  In the Workbench
    environment, depending on your startup code, the current directory
    will generally be set to one of the wa_Locks.  By using
    CurrentDir(wa_Lock) and then referencing wa_Name, you can find, read,
    and modify the files that have been passed to your program as WBArgs.
