/* Source: ADCD 2.1
 * Section: intuition-library-modifyidcmp
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-modifyidcmp.md
 */

     argument is not zero, this means that you want to change the
     state of which events will be broadcast to you through the IDCMP

    NOTE:  You can set up the Window->UserPort to any port of your own
    before you call ModifyIDCMP().  If IDCMPFlags is non-null but
    your UserPort is already initialized, Intuition will assume that
    it's a valid port with task and signal data preset and Intuition
    won't disturb your set-up at all, Intuition will just allocate
    the Intuition message port half of it.  The converse is true
    as well:  if UserPort is NULL when you call here with
    IDCMPFlags == NULL, Intuition will deallocate only the Intuition
    side of the port.

    This allows you to use a port that you already have allocated:
    - [OpenWindow()](../Includes_and_Autodocs_2._guide/node0239.html) with IDCMPFlags equal to NULL (open no ports)
    - set the UserPort variable of your window to any valid port of your
      own choosing
    - call ModifyIDCMP with IDCMPFlags set to what you want
    - then, to clean up later, set UserPort equal to NULL before calling
      [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html) (leave IDCMPFlags alone)  BUT FIRST: you must make
      sure that no messages sent your window are queued at the port,
      since they will be returned to the memory free pool.

    For an example of how to close a window with a shared IDCMP,
    see the description for [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html).
