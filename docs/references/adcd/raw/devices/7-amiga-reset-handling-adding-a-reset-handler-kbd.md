# 7 / Amiga Reset Handling / Adding A Reset Handler (KBD_ADDRESETHANDLER)


The [KBD_ADDRESETHANDLER](../Includes_and_Autodocs_2._guide/node050D.html) command adds a custom routine to the chain of
reset-handlers.  Reset handlers are just like any other handler and are
added to the handler list with an [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure.  The priority field
in the list node of the Interrupt structure establishes the sequence in
which reset handlers are processed by the system.  Keyboard reset handlers
are currently limited to the priority values of a software interrupt, that
is, values of -32, -16, 0, 16, and 32.

The io_Data field of the I/O request is filled in with a pointer to the
[Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure and the io_Command field is set to
[KBD_ADDRESETHANDLER](../Includes_and_Autodocs_2._guide/node050D.html).  These are the only two fields you need to initialize
to add a reset handler.  Any return value from the command is ignored.
All keyboard reset handlers are activated if time permits.  Normally, a
reset handler will just signal the requisite task and return.  The task
then does whatever processing it needs to do and notifies the system that
it is done by using the KBD_RESETHANDLERDONE command described below.

   Non-interference and speed are the keys to success.
   ---------------------------------------------------
   If you add your own handler to the chain, you must ensure that your
   handler allows the rest of reset processing to occur.  Reset must
   continue to function.  Also, if you don't execute your reset code
   fast enough, the system will still reboot (about 10 seconds).

