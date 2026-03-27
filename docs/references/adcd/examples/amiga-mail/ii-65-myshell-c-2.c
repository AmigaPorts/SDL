/* Source: ADCD 2.1
 * Section: ii-65-myshell-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-65-myshell-c.md
 */

    commandname = &(command[COMMANDLINELENGTH]);
    prompt = &(command[COMMANDLINELENGTH + COMMANDBUFLENGTH]);
    do
    {
      /* Make sure the shell looks to cli_CurrentInput for its command lines */

      SelectInput(ml->mycli->cli_CurrentInput);
      /* is this an interactive shell? */
      ml->mycli->cli_Interactive =
      /* if this is not a backround CLI, and */
        ((!(ml->mycli->cli_Background)) &&
      /* input has not been redirected to an script file, and */
         NOTSCRIPT &&
      /* this shell was not started from System() */
         (!SYSTEM)) ? DOSTRUE : DOSFALSE;

      /* if this is a script and the user hit CTRL-D, break out of the script */
      if (!((SetSignal(0L, SIGBREAKF_CTRL_C |
                       SIGBREAKF_CTRL_D |
                       SIGBREAKF_CTRL_E |
                       SIGBREAKF_CTRL_F) & SIGBREAKF_CTRL_D) &&
            (!SYSTEM) && (ISSCRIPT)))
      {
        /* if this shell is interactive and there is a prompt, print it */
        /* (unless, of course, this was created by Run, etc) */
        if (ml->mycli->cli_Interactive == DOSTRUE && !(ml->mycli->cli_Background))
        {

          /*
           * If this wasn't an example, I would probably change the prompt
           * here, probably to reflect the name of the current directory.
           */
          /* print the prompt */
          if (GetPrompt(prompt, 256))
          {
            FPuts(Output(), prompt);
            /* Make sure the prompt gets printed */
            Flush(Output());
          }
        }
        /* Get Command */
        if (FGets(ml->mycli->cli_CurrentInput, command, COMMANDLINELENGTH))
        {
          cmd = command;
          /* skip leading spaces in command line */
          while (*cmd == ' ')
            cmd++;

          /*
           * If I was bothering to deal with aliases, I would probably resolve
           * them here.
           */

          cmdname = commandname;
          x = 0;
          /* copy the actual command from the cmd buffer */
          while ((*cmd >= '0') && (*cmd <= 'z') && (x < (COMMANDBUFLENGTH - 1)))
          {
            *cmdname++ = *cmd++;
            x++;
          }
          *cmdname = '\0';
          /*
           * OK, now we have the actual command in commandname. Using it we can
           * find the actual executeable code.  The command could come from
           * several sources:
           *
           * The resident list
           * The shell (an internal command)
           * disk (from either an absolute or relative path)
           *
           * This example only looks through the resident list for commands. A
           * real shell would also try to load a command from disk if the
           * command is not present in the resident list (or the command is not
           * internal to the shell.
           */

          /* Search resident list for the command */
          Forbid();
          if (!(cmdseg = FindSegment(commandname, NULL, FALSE)))
            cmdseg = FindSegment(commandname, NULL, TRUE);
          if (cmdseg)
          {
            if ((cmdseg->seg_UC < CMD_DISABLED) ||
                (cmdseg->seg_UC == CMD_SYSTEM))
              cmdseg = NULL;
            else if (cmdseg->seg_UC >= 0)
              cmdseg->seg_UC++;
          }
          Permit();

          /*
           * if !cmdseg, the command was not in the resident list.  If I were
           * bothering to look for commands on disk, I would try to load the
           * command here.  If I has successfully loaded a command and was
           * going to execute it, I would have to set ml->myprocess->pr_HomeDir
           * to be a DupLock() of the directory I loaded the command from.  I
           * don't do this for commands from the resident list because they
           * have no home directory.
           */

          /* If we did find a command, run it */
          if (cmdseg)
          {
            /* Clear the error field before executing the command */
            SetIoErr(0);

            SetProgramName(commandname);
            ml->mycli->cli_Module = cmdseg->seg_Seg;

            /*
             * Set the I/O streams to their defaults. NOTE: StandardInput, NOT
             * CurrentInput!  The Execute command will cause nasty things to
             * happen if you use CurrentInput, since it must close that in
             * order to change the input stream to the next file. Obviously,
             * this only applies if you're using the normal AmigaDOS Execute
             * command for scripts.
             */
            SelectInput(ml->mycli->cli_StandardInput);
            SelectOutput(ml->mycli->cli_StandardOutput);

            /*
             * If I were doing redirection, the I/O handles above would be the
             * redirection handles.
             */

            /* Run the command */
            result = RunCommand(ml->mycli->cli_Module,
                                (ml->mycli->cli_DefaultStack * 4),
                                cmd,
                                strlen(cmd));
            /*
             * OK, we returned from the command.  Fill in any error codes in
             * the appropriate CLI fields.
             */
            ml->mycli->cli_ReturnCode = result;
            ml->mycli->cli_Result2 = IoErr();
            /* If I had bothered to load code from an executable file on disk,
             * I would have to unload it now.  Since I didn't, all I have to do
             * is NULL cli_Module.
             */
            ml->mycli->cli_Module = NULL;

            SetProgramName("");
            Forbid();
            if (cmdseg->seg_UC > 0)
              cmdseg->seg_UC--;
            Permit();
            cmdseg = NULL;
          }
          else
          {
            /* we couldn't find the command.  Print an error message unless the
             * command starts with a non-alphanumeric character (like a
             * carriage return) or the first character is a comment character.
             */
            if ((commandname[0] >= '0') &&
                (commandname[0] <= 'z') &&
                (commandname[0] != ';'))
            {
              PutStr(commandname);
              PutStr(": Command not found\n");
              Flush(Output());
            }
          }

          /* if you set up redirection I/O handles for the command don't forget
           * to flush and close them.
           */

          /* Make sure the proper I/O handles are in place. */
          SelectInput(ml->mycli->cli_CurrentInput);
          SelectOutput(ml->mycli->cli_StandardOutput);

          /* Get rid of any unused data left in the buffer */
          ch = UnGetC(Input(), -1) ? '\0' : '\n';
          while ((ch != '\n') && (ch != ENDSTREAMCH))
            ch = FGetC(Input());
          if (ch == ENDSTREAMCH)
            done = TRUE;
        }
        else
          done = TRUE;                 /* We got an EOF when reading in a
                                        * command */
        if (done)
        {
          if (ISSCRIPT)
          {
            done = FALSE;              /* this is a script (which could be
                                        * s:shell-startup), so don't quit, just
                                        * exit the script and set up IO
                                        * handles. */
            /* Close the script file */
            Close(ml->mycli->cli_CurrentInput);
            /* Reset the input to what we started with */
            SelectInput(ml->mycli->cli_StandardInput);
            ml->mycli->cli_CurrentInput = ml->mycli->cli_StandardInput;

            /* Restore Fail Level after executing a script */
            ml->mycli->cli_FailLevel = RETURN_ERROR;

            /* if the script created a file, delete it */
            if (((char *) BADDR(ml->mycli->cli_CommandFile))[0])
            {
              cmd = (char *) BADDR(ml->mycli->cli_CommandFile);
              CopyMem(&(cmd[1]), command, (LONG) cmd[0]);
              command[cmd[0]] = '\0';
              DeleteFile(command);
              cmd[0] = '\0';
            }
          }
        }
      }
      else
        /* Somebody hit CTRL_D in a script */
      {
        /* print the string associated with error #304 */
        PrintFault(304, "MyShell");
        /* Close the script file */
        Close(ml->mycli->cli_CurrentInput);
        /* Reset the input to what we started with */
        SelectInput(ml->mycli->cli_StandardInput);
        ml->mycli->cli_CurrentInput = ml->mycli->cli_StandardInput;

        cmd = (char *) BADDR(ml->mycli->cli_CommandFile);
        cmd[0] = '\0';
      }
      /* this takes care of some problems certain programs caused */
      if (SYSTEM && NOTSCRIPT)
        done = TRUE;

    } while (!done);
    FreeVec((void *) command);
