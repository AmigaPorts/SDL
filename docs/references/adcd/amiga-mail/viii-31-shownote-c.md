---
title: VIII-31/ShowNote.c
manual: amiga-mail
chapter: amiga-mail
section: viii-31-shownote-c
functions: [Wait]
libraries: [exec.library]
---

# VIII-31/ShowNote.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* shownote.c - Execute to compile with SAS/C 6.56
sc DATA=FAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 shownote.c
slink FROM LIB:c.o shownote.o TO shownote LIBRARY LIB:sc.lib LIB:amiga.lib
quit
*/

/* (c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved. */
/* The information contained herein is subject to change without    */
/* notice, and is provided "as is" without warranty of any kind,    */
/* either expressed or implied.  The entire risk as to the use of   */
/* this information is assumed by the user.                         */

/*
** Our Application Prototypes (specific to noter.c file)
*/
void    main( void );
void    TG_Init( void );
int     SS_Init( void );
int     DoER( char *, char *, char * );
void    AppPanic( char *, int );
void    HandleMsg( int );

/*
** Application-specific defines and globals
*/

char Version[] = "\0$VER: ShowNote 1.2 (1.12.91)";

/*
** The library bases...we need em later...
*/

struct Library *IntuitionBase, *SockBase;

/*
** All other includes and protos are indexed off our catch-all file
** note.h which both the client (sendnote.c) and server (shownote.c) include.
*/

#include    "note.h"


VOID    main( VOID )
{
```c
    int     socket;         /* The socket */

    fd_set  sockmask,       /* Mask of open sockets */
            mask;           /* Return value of socketwait() */

    long    umask;          /* AmigaDOS signal mask */



    /*
    ** Call TG_Init to prepare the generic Amiga stuff for use...
    */

    TG_Init();

    /*
    ** ...and SS_Init for the socket-specific arrangements, keeping
    ** track of what it hands back.
    */

    socket = SS_Init();

    /*
    ** First, prepare the various masks for signal processing
    */

    FD_ZERO( &sockmask );
    FD_SET( socket, &sockmask );


    /*
    ** And we enter the event loop itself
    */

    while(1)
    {
        /*
        ** Reset the mask values for another pass
        */

        mask = sockmask;
        umask = SIGBREAKF_CTRL_C;

        /*
        ** selectwait is a combo network and Amiga Wait() rolled into
        ** a single call.  It allows the app to respond to both Amiga
        ** signals (CTRL-C in this case) and to network events.
        **
        ** Here, if the selectwait event is the SIGBREAK signal, we
        ** bail and AppPanic() but otherwise its a network event.
        ** This is a very crude way of handling the exit, but it
        ** is an effective one
        */

        if (selectwait( 2, &mask, NULL, NULL, NULL, &umask ) == -1 )
        {
            AppPanic("CTRL-C:\nProgram terminating!",0);
        }

        /*
        ** Since the contact between the client and server is so
        ** quick, an iterative server is adeqaute.  For cases where
        ** extended connections or concurrent connections are needed,
        ** either a state-machine or concurrent server would be a
        ** better choice.
        **/

        /*
        ** Here, we accept the pending connection (the only case
        ** possible with this mechanism) and dispatch to a routine
        ** which actually handles the client-server communication.
        */

        if (FD_ISSET( socket, &mask ))
        {
            HandleMsg( socket );
        }
        else
        {
            AppPanic("Network Signal Error!",0);
        }
    }
```
}


/*
**  AppPanic() - General Shutdown Routine
**
**  This routine serves to provide both a nice GUI way of indicating error
**  conditions to the user, and to handle all the aspects of shutting the
**  server down.  In a real-world application, you would probably separate
**  the error condition shutdown from the normal shutdown.  Since this is
**  an example, it would add needless complexity to the code.  Further,
**  as far as this server is concerned, shutting down _is_ an error state,
**  since SIGBREAKF_CTRL_C is a process-specific warning of shutdown.
*/



VOID    AppPanic( char *panictxt, int panicnum )
{

```c
    char buffer[255];

    if (!panicnum)
    {
        DoER( APPNAME, panictxt, "OK" );
    }
    else
    {
        sprintf( (char *)&buffer, "%s\n\n%s", panictxt, strerror(panicnum));
        DoER( APPNAME, (char *)&buffer, "OK" );
    }
    if (SockBase)
    {
        cleanup_sockets();
        CloseLibrary(SockBase);
    }

    if (IntuitionBase)
    {
        CloseLibrary(IntuitionBase);
    }

    exit(RETURN_ERROR);
```
}

/*
**  DoER() - Attempt at a "generic" wrapper for EasyRequest()
**
**  Since EasyRequest(), though "easy", still requires some initialization
**  before it can be used, this routine acts as a wrapper to EasyRequest.
**  It also catches and provides a means to implement application-generic
**  values for what gets handed to the EasyRequest routine, making coding
**  just a wee bit easier.
*/
int     DoER( char *titletxt, char *msgtxt, char *btntxt )
{
```c
    struct EasyStruct easy =    {
                                sizeof(struct EasyStruct),
                                NULL,
                                NULL,
                                NULL,
                                NULL
                                };

    int retval = 0;

    if (IntuitionBase)
    {
        if (titletxt)
        {
            easy.es_Title = titletxt;
        }
        else
        {
            easy.es_Title = APPNAME;
        }

        if (msgtxt)
        {
            easy.es_TextFormat = msgtxt;
        }
        else
        {
            easy.es_TextFormat = "Null message text!\nIsnt it?";
        }

        if (btntxt)
        {
            easy.es_GadgetFormat = btntxt;
        }
        else
        {
            easy.es_GadgetFormat = "Take off, eh!";
        }

        retval = EasyRequest( NULL, &easy, NULL, NULL );
        return (retval);
    }
```
}

/*
**  TG_Init() - Initializer of AOS/Intuition
**
**  This routine just handles opening Intuition, but would be a good
**  place to put any other initialization code which is specific to getting
**  an application's Amiga environment properly set up.
*/
VOID    TG_Init( VOID )
{
```c
    IntuitionBase = OpenLibrary("intuition.library",36);
    if (!IntuitionBase)
        exit(RETURN_ERROR);
```
}
/*
**  SS_Init() - Initializer of shared socket library
**
**  SS_Init() handles the opening of socket.library, the formation of an
**  application-specific socket environment, and the creation of the initial
**  socket for the server.  It returns an identifier to the socket it has
**  prepared, which just happens to represent itself as an int.
*/
int     SS_Init( VOID )
{

```c
    struct sockaddr_in  sockaddr;

    int snum, len = sizeof(sockaddr);

    /*
    ** Attempt to open socket library and initialize socket environ.
    ** If this fails, bail out to the non-returning AppPanic() routine.
    */

    /*
    ** The errno variable is a part of ANSI, and is defined in the c.o
    ** startup code.  Essentially, its where ANSI functions put their
    ** error codes when they fail.  For more information, consult a
    ** reference to ANSI C.
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library",0L))
    {
        setup_sockets( 3, &errno );
    }
    else
    {
        AppPanic("Can't open socket.library!",0);
    }

    /*
    ** Open the initial socket on which incoming messages will queue for
    ** handling.  While the server is iterative, I do it this way so that
    ** SIGBREAKF_CTRL_C will continue to function.
    */


    if ((snum = socket( AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        AppPanic("Socket Creation:",errno);
    }

    /*
    ** Here we clear and prepare the information to give our socket
    ** a real address on the system.
    */

    memset( &sockaddr, 0, len );
    sockaddr.sin_family = AF_INET;
```
	/*
	**  Following is commented out for ease of testing purposes!
	**
	**  {
	**      struct servent *servptr;
	**      char *serv = APPNAME;
	**
	**      if ((servptr = getservbyname( serv, "tcp" )) == NULL)
	**      {
	**          AppPanic("Service not in inet:db/services list!",0);
	**      }
	**      sockaddr.sin_port = servptr->s_port;
	**  }
	*/

```c
    sockaddr.sin_port = 8769;

    sockaddr.sin_addr.s_addr = INADDR_ANY;

    /*
    ** Having everything set up, we now attempt to allocate the port number
    ** for our socket.  If this fails, we bail.
    */

    if ( bind( snum, (struct sockaddr *)&sockaddr, len ) < 0 )
    {
        AppPanic("Socket Binding:",errno);
    }

    /*
    ** Okay, the socket is as ready as it gets.  Now all we need to do is to
    ** tell the system that the socket is open for business.  In an ideal
    ** world, this needs to be checked for errors, but for the scope of the
    ** example, it isnt necessary.  By the way, the '5' in the listen() call
    ** indicates the "queue size" for number of outstanding requests.
    */

    listen( snum, 5 );

    /*
    ** And last, we pass the socket number back to the main routine.
    */

    return snum;
```
}

/*
**  HandleMsg() - Handles client connection and message display
**
**  This is where 90% of the "function" of the program occurs.  This routine
**  connects the server to the client socket, gets the incoming message pkt,
**  acknowledges it, displays it, then terminates the client connection.
**  For doing all that, its small, a testament to how easily the actual work
**  can be done.
*/
void    HandleMsg( int sock )
{

```c
    struct NetNote in;              /* Buffer for incoming packets */

    struct sockaddr_in saddr;       /* Socket address from accept() */
    struct in_addr sad;             /* Internet address component */

    struct hostent *hent;           /* Internet host information */

    int nsock,                      /* New socket from accept() */
        len,                        /* Length of addr from accept() */
        retv;                       /* Return value from DoER call */

    char rname[80],                 /* Buffer for titlebar string */
         *hname,                    /* Ptr to the hostname */
         *dd_addr;                  /* Ptr to the dotted-decimal address */

    /*
    ** We accept() the attempted connection on socket 'sock'
    ** which also yields the addr of the remote machine.  Then we
    ** attempt to convert the name to something meaningful.
    **
    ** First, we clear the stuff...
    */


    bzero( (char *)&rname, 80);
    bzero( (char *)&saddr, sizeof(struct sockaddr_in) );
    bzero( (char *)&sad, sizeof(struct in_addr) );
    len = sizeof(struct sockaddr_in);


    /*
    ** Then we accept the connection on the socket
    */
    /* Bug fixed 1/93: line below checked for wrong return value. Sorry Dale! */
    if (!(nsock = accept( sock, (struct sockaddr *)&saddr, &len )))
    {
        AppPanic("Accept:",errno);
    }

    /*
    ** Break the internet address out of the sockaddr_in structure and then
    ** create a dotted-decimal format string from it, for later use
    */

    sad = saddr.sin_addr;
    dd_addr = inet_ntoa(sad.s_addr);

    /*
    ** Use the internet address to find out the machine's name
    */

    if ( !(hent =
            gethostbyaddr( (char *)&sad.s_addr,
                           sizeof(struct in_addr),
                           AF_INET )))
    {
        AppPanic("Client resolution:\nAddress not in hosts db!", 0 );
    }
    hname = hent->h_name;

    /*
    ** Form the string which goes into the title bar using name & address
    */

    sprintf( rname, "FROM: %s (%s)", hname, dd_addr );



    /*
    ** Okay, now the waiting packet needs to be removed from the connected
    ** socket that accept() gave back to us.  Verify its of type NN_MSG and
    ** if not, set return type to NN_ERR.  If it is, then display it and
    ** return an NN_ACK message.
    */

    recv( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    if (in.nn_Code == NN_MSG)
    {
        DisplayBeep(NULL);
        DisplayBeep(NULL);
        retv = DoER( rname, (char *)&in.nn_Text, (char *)&in.nn_Button );
        in.nn_Code = NN_ACK;
        in.nn_Retval = retv;
    }
    else
    {
        in.nn_Code = NN_ERR;
    }

    /*
    ** Having dealt with the message one way or the other, send the message
    ** back at the remote, then disconnect from the remote and return.
    */

    send( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    s_close( nsock );
```
}

---

## See Also

- [Wait — exec.library](../autodocs/exec.library.md#wait)
