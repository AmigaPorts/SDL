/* Source: ADCD 2.1
 * Section: arexx-cl-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/arexx-cl-datasheet.md
 */

    NAME
        arexx_cl -- ARexx interface class.

    SUPERCLASS
        rootclass

    DESCRIPTION
        This class provides you with a very easy way to implement an ARexx
        interface.  It will setup a unique ARexx port, start ARexx macros,
        parse commands and dispatch command handler functions.

        All ARexx class methods and the callbacks you provide it are run in
        the context of the task you call ARexx class from. Thus if your
        application is a process, DOS is safe to use.

    METHODS
        OM_NEW -- Passed to superclass first.  Sets up the port.

        OM_GET -- Returns requested attributes.  Passed onto superclass.

        OM_DISPOSE -- Closes the port and frees all resources.  Passed onto
            superclass

        [AM_EXECUTE](../Includes_and_Autodocs_3._guide/node0054.html) -- Executes an ARexx command or macro.

        [AM_HANDLEINPUT](../Includes_and_Autodocs_3._guide/node0055.html) -- Handles ARexx messages.

    ATTRIBUTES
        AREXX_HostName (STRPTR)
            The name of the host.  The ARexx portname is derived from this.
            In pretty much all cases, this should the same as your app's
            basename.  You should refrain from using names like "MYPROG_RX"
            or others with unnecessary suffixes.

            To create the portname, the hostname will be uppercased, and,
            unless AREXX_NoSlot is specified, a slot number will be
            appended.

            Applicability is (OM_NEW, OM_GET)

        AREXX_NoSlot (BOOL)
            Specifies that no slot number should be appended to the port
            name when it is being created.  This greatly increases the
            chances that your requested portname is in use, so your code
            must be sure to handle this situation.

            Defaults to FALSE.

            Applicability is (OM_NEW)

        AREXX_DefExtension (STRPTR)
            Default filename extension for macros started by your app.  Do
            not include the ".", just the extension text.   In pretty much
            all cases, this should be the same as your app's basename.  You
            should refrain from using extensions like "myrx".

            Defaults to "rexx".

            Applicability is (OM_NEW)

        AREXX_Commands (struct [ARexxCmd](../Includes_and_Autodocs_3._guide/node05D5.html#line113) *)
            The table of the commands supported by your ARexx interface.
            This will be a pointer to an array of struct [ARexxCmd](../Includes_and_Autodocs_3._guide/node05D5.html#line113).  If this
            array is not passed then your host will not be able to process
            any ARexx commands.

            The following fields must be setup initially by the app before
            OM_NEW:

                ac_Name (STRPTR)
                The name of the command.  By convention this is usually all
                uppercase, though a case-insensitive comparisons will be
                done.

                ac_ID (WORD)
                A unique number identifying this command.

                ac_Func (*()(struct [ARexxCmd](../Includes_and_Autodocs_3._guide/node05D5.html#line113) *, struct [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97) *))
                A pointer to the function that will be called when this
                command is received by your programme.  The function will
                get past a pointer to its [ARexxCmd](../Includes_and_Autodocs_3._guide/node05D5.html#line113) entry and the [RexxMsg](../Includes_and_Autodocs_3._guide/node0633.html#line97)
                structure received for the command.  You may use this
                for setting ARexx variables, but please note that is may
                be NULL

                ac_ArgTemplate (STRPTR)
                DOS ReadArgs()-style argument template for this command.

                ac_Flags (ULONG)
                Command flags.  Currently unused, but in order to remain
                compatable, you must ensure that this is NULL.

            These fields are ignored in OM_NEW and are set by the class
            when calling the ac_Func command callback.

                ac_ArgList (ULONG *)
                Result of [ReadArgs()](../Includes_and_Autodocs_3._guide/node01A1.html) using the arguments received with the
                command and ac_ArgTemplate as the template.

                ac_RC (LONG)
                Primary result, the RC variable.  Also causes the RC2
                variable to return, and will cause RESULT to NOT be set.

                ac_RC2 (LONG)
                Secundary result, the RC2 variable.  This will not be set
                unless RC is non-zero.

                ac_Result (STRPTR)
                RESULT variable, this should be a string.  If you want to
                return a number, you will have to convert it to a string
                first.  This string will not be set if RC is non-zero.

            The array must be terminated with a NULL ac_Name field.

            Applicability is (OM_NEW)

        AREXX_ErrorCode (ULONG *)
            A pointer to storage space for OM_NEW to store an error code
            when it fails trying to create the object.  Possible values
            are:

            RXERR_NO_COMMAND_LIST - No command list was provided.
            RXERR_NO_PORT_NAME - No host base name was provided.
            RXERR_PORT_ALREADY_EXISTS - The  class  was unable to create a
                unique name of the base name you provided.
            RXERR_OUT_OF_MEMORY - Not enough free memory.

            No error code will be returned if you provide a NULL pointer.

            Defaults NULL.

            Applicability is (OM_NEW)

        AREXX_SigMask (ULONG)
            The signal mask for the object's message port.  This is the
            signal you will want to [Wait()](../Includes_and_Autodocs_3._guide/node0246.html) on so you know when there is
            activity at the ARexx port.

            Applicability is (OM_GET)

        AREXX_ReplyHook (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *)
            This is a function hook that will get called whenever your host
            replies to an ARexx message.  This generally happens after your
            host has sent a message (eg. via AM_EXECUTE) and the task
            receiving the message has completed its processing with the
            message.  This is most useful for checking return codes from
            commands sent via [AM_EXECUTE](../Includes_and_Autodocs_3._guide/node0054.html).

            The object parameter in the hook function will point to the
            [Object](../Includes_and_Autodocs_3._guide/node0636.html#line18) * that is yur host, and the message parameter will be
            the ARexx message that is being replied to (from which you
            could extract result codes).

            Defaults to NULL.

            Applicability is (OM_NEW, OM_GET)

    BUGS
        AREXX_HostName MUST be all uppercase in V40 otherwise the checks for
        an already existing port won't work right.
