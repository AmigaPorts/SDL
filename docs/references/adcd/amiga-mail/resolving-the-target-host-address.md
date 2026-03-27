---
title: Resolving the Target (Host) Address
manual: amiga-mail
chapter: amiga-mail
section: resolving-the-target-host-address
functions: [ReadArgs]
libraries: [dos.library]
---

# Resolving the Target (Host) Address

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The client gets a string back from the ReadArgs() call which contains
the hostname in either dotted-decimal notation or ASCII form.  The
clint needs to convert that string to a usable form.




```c
    struct sockaddr_in serv;
    struct hostent *host;
    char *hostnam, *text, *button;

    /*
    ** First we need to try and resolve the host machine as an IP/Internet address.
    ** If that fails, fall back to seaching the hosts file for it.  Later versions of
    ** gethostbyname() may use DNS to find a host name, rather than searching the hosts file.
    */



    bzero( &serv, sizeof(struct sockaddr_in) );
    if ( (serv.sin_addr.s_addr = inet_addr(hostnam)) == INADDR_NONE )
    {
        /*
        ** Okay, the program wasnt handed a dotted decimal address,
        ** so we check and see if it was handed a machine name.
        */

        if ( (host = gethostbyname(hostnam)) == NULL )
        {
            printf("Host not found: %s\n",host);
            FinalExit( RETURN_ERROR );
        }

        /*
        ** It does indeed have a name, so copy the addr field from the
        ** hostent structure into the sockaddr structure.
        */

        bcopy( host->h_addr, (char *)&serv.sin_addr, host->h_length );
    }
```
After clearing out the serv sockadd_in structure, the client tries to
convert the host name string (hostnam) it got from its command line
from dotted-decimal to an IP address block using the inet_addr()
function.  If this fails, the server treats the string hostnam as an
ASCII string containing a host name, and tries to get a normal IP
address using gethostbyname().  This will search the hosts file
(inet:db/hosts) for a matching entry.  Future versions of
gethostbyname() may use DNS (domain name system), which allows
gethostbyname() to ask a server for host information rather than
looking it up in a hosts file.

If it is successful, gethostbyname() returns a pointer to a hostent
structure.  It requires a little work to to convert this hostent
structure to a sockaddr_in (IP socket address) structure.  There is a
sockaddr structure embedded inside the hostent structure which can be
used as a sockaddr string in this case.  The call to bcopy() copies
that embedded sockaddr structure into the client's sockaddr_in buffer.

---

## See Also

- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
