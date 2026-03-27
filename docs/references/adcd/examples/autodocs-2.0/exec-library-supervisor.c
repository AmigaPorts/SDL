/* Source: ADCD 2.1
 * Section: exec-library-supervisor
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-supervisor.md
 */

    Allow a normal user-mode program to execute a short assembly language
    function in the supervisor mode of the processor.  Supervisor() does
    not modify or save registers; the user function has full access to the
    register set.   All rules that apply to interrupt code must be
    followed.  In addition, no system calls are permitted.  The function
    must end with an RTE instruction.
