/* Source: ADCD 2.1
 * Section: arexx-cl-am-execute
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/arexx-cl-am-execute.md
 */

    NAME
        AM_EXECUTE -- [Execute](../Includes_and_Autodocs_3._guide/node015E.html) an ARexx macro.

    FUNCTION
        This method allows you to execute a macro in another host.  The
        default host is the ARexx server.  This is how you would execute
        disk-based ARexx macros, by passing the name of the file as the
        command string to the ARexx server.

        This method uses the following custom message structure:

          struct [apExecute](../Includes_and_Autodocs_3._guide/node05D5.html#line97)
          {
              ULONG MethodID;
              [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) ape_CommandString;
              [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) ape_PortName;
              [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *ape_RC;
              [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *ape_RC2;
              [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) *ape_Result;
              [BPTR](../Includes_and_Autodocs_3._guide/node05F8.html#line129) ape_IO;
          };

        ape_CommandString (STRPTR)
            This must point to the command including arguments to execute.
            If the command is found in the host command list it will be
            executed.  Unknown commands will be shipped off to the ARexx
            server.

        ape_RC, ape_RC2, ape_Result (LONG *, [LONG](../Includes_and_Autodocs_3._guide/node0654.html#line39) *, [STRPTR](../Includes_and_Autodocs_3._guide/node0654.html#line57) *)
            After the command executed you will find the results in here if
            the command was one in your host, or if there was a problem
            sending the command to the specified host.  You will NOT get the
            result of the command if it is sent to another host, since the
            command is sent asychronously.  Use AREXX_ReplyHook for this.

        ape_IO (BPTR)
            If you execute a script using this method you can pass a pointer
            to the IO channel ARexx must  use here.  This IO channel will be
            closed automatically for you after the command executed.

    RESULT
        As errors are reported in acme_RC and acme_RC2 this method has no
        specific return code.
