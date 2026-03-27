/* Source: ADCD 2.1
 * Section: 14-workbench-and-the-startup-code-module-workbench-startup
 * Library: libraries
 * ADCD reference: libraries/14-workbench-and-the-startup-code-module-workbench-startup.md
 */

    Avoid the DOS Exit() function.
    ------------------------------
    The DOS [Exit()](../Includes_and_Autodocs_2._guide/node029F.html) function does not return an application to the
    startup code that called it.  If you wish to exit your application,
    use the exit function provided by your startup code (usually
    lower-case exit(), or _exit for assembler), passing it a valid
    DOS return code as listed in the include file <libraries/[dos.h](../Includes_and_Autodocs_2._guide/node0108.html)>.
