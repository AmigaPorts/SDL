---
title: arexx_cl/AM_EXECUTE
manual: autodocs-3.5
chapter: autodocs-3.5
section: arexx-cl-am-execute
functions: []
libraries: []
---

# arexx_cl/AM_EXECUTE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AM_EXECUTE -- [Execute](autodocs-3.5/dos-library-execute-2.md) an ARexx macro.

    FUNCTION
        This method allows you to execute a macro in another host.  The
        default host is the ARexx server.  This is how you would execute
        disk-based ARexx macros, by passing the name of the file as the
        command string to the ARexx server.

        This method uses the following custom message structure:

          struct [apExecute](autodocs-3.5/include-classes-arexx-h.md)
          {
              ULONG MethodID;
              [STRPTR](autodocs-3.5/include-exec-types-h.md) ape_CommandString;
              [STRPTR](autodocs-3.5/include-exec-types-h.md) ape_PortName;
              [LONG](autodocs-3.5/include-exec-types-h.md) *ape_RC;
              [LONG](autodocs-3.5/include-exec-types-h.md) *ape_RC2;
              [STRPTR](autodocs-3.5/include-exec-types-h.md) *ape_Result;
              [BPTR](autodocs-3.5/include-dos-dos-h.md) ape_IO;
          };

        ape_CommandString (STRPTR)
            This must point to the command including arguments to execute.
            If the command is found in the host command list it will be
            executed.  Unknown commands will be shipped off to the ARexx
            server.

        ape_RC, ape_RC2, ape_Result (LONG *, [LONG](autodocs-3.5/include-exec-types-h.md) *, [STRPTR](autodocs-3.5/include-exec-types-h.md) *)
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
```
