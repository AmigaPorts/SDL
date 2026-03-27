/* Source: ADCD 2.1
 * Section: amiga-lib-createtask
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-createtask.md
 */

    Under exec.library V37 or beyond, the [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html) function used
    internally by CreateTask() can fail whereas it couldn't fail in
    previous versions of Exec. Prior to amiga.lib V37.14, this function
    did not check for failure of [AddTask()](../Includes_and_Autodocs_2._guide/node032D.html) and thus might return a
    pointer to a task structure even though the task was not actually
    added to the system.
