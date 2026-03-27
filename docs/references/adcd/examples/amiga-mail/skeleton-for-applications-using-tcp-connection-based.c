/* Source: ADCD 2.1
 * Section: skeleton-for-applications-using-tcp-connection-based
 * Library: amiga-mail
 * ADCD reference: amiga-mail/skeleton-for-applications-using-tcp-connection-based.md
 */

    struct in_addr {
        u_long s_addr;
    };

    struct sockaddr_in {
        short     sin_family;        /* address family.  Make this
                                        AF_INET for TCP/IP */
        u_short   sin_port;          /* the port number (the value from
                                        servent.s_port)    */
        struct    in_addr sin_addr;  /* internet address. For TCP/IP, make
                                        sin_addr.s_addr INADDR_ANY.  Bind
                                        will know what to do with this. */
        char      sin_zero[8];       /* unused by TCP/IP */
    };
