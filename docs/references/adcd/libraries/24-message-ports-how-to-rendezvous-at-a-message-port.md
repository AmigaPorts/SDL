---
title: 24 / Message Ports / How To Rendezvous at a Message Port
manual: libraries
chapter: libraries
section: 24-message-ports-how-to-rendezvous-at-a-message-port
functions: [FindPort, Forbid, Permit]
libraries: [exec.library]
---

# 24 / Message Ports / How To Rendezvous at a Message Port

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [FindPort()](autodocs-2.0/exec-library-findport.md) function provides a means of finding the address of a
public port given its symbolic name.  For example, FindPort("Griffin")
will return either the address of the message port named "Griffin" or NULL
indicating that no such public port exists.  Since FindPort() does not do
any arbitration over access to public ports, the usage of FindPort() must
be protected with [Forbid()/Permit()](libraries/21-task-exclusion-forbidding-task-switching.md). Names should be unique to prevent
collisions among multiple applications.  It is a good idea to use your
application name as a prefix for your port name.  FindPort() does not
arbitrate for access to the port list.  The owner of a port might remove
it at any time.  For these reasons a Forbid()/Permit() pair is required
for the use of FindPort().  The port address can no longer be regarded as
being valid after Permit() unless your application knows that the port
cannot go away (for example, if your application created the port).

The following is an example of how to safely put a message to a specific
port:


```c
    #include <exec/types.h>
    #include <exec/ports.h>

       BOOL MsgPort SafePutToPort(struct Message *message, STRPTR portname)
       {
           struct MsgPort *port;

           Forbid();
           port = FindPort(portname);
           if (port) PutMsg(port,message);
           Permit();
           return(port ? TRUE : FALSE);
                           /* If FALSE, the port was not found */

           /* Once we've done a Permit(), the port might go away */
           /* and leave us with an invalid port address. So we   */
           /* return just a BOOL to indicate whether the message */
           /* has been sent or not.                              */
       }
```

---

## See Also

- [FindPort — exec.library](../autodocs/exec.library.md#findport)
- [Forbid — exec.library](../autodocs/exec.library.md#forbid)
- [Permit — exec.library](../autodocs/exec.library.md#permit)
