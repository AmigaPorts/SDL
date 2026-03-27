/* Source: ADCD 2.1
 * Section: 14-workbench-environment-wbstartup-message
 * Library: libraries
 * ADCD reference: libraries/14-workbench-environment-wbstartup-message.md
 */

    sm_Message
        A standard Exec message.  The reply port is set to the Workbench.

    sm_Process
        The process descriptor for the tool (as returned by
        [CreateProc()](../Includes_and_Autodocs_2._guide/node028E.html))

    sm_Segment
        The loaded code for the tool (returned by [LoadSeg()](../Includes_and_Autodocs_2._guide/node02C5.html))

    sm_NumArgs
        The number of arguments in sm_ArgList

    sm_ToolWindow
        Reserved (not currently passed in startup message)

    sm_ArgList
        This is the argument list itself.  It is a pointer to an array
        of WBArg structures with sm_NumArgs elements.
