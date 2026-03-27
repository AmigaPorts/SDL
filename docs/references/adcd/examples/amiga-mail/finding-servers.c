/* Source: ADCD 2.1
 * Section: finding-servers
 * Library: amiga-mail
 * ADCD reference: amiga-mail/finding-servers.md
 */

     applications should use configurable port numbers.  In programs
     written for AS225, you should use the inet:db/services file to
     configure a port number.  The function getservbyname() accepts a
     protocol (UDP or TCP) and the name of a well-known server and returns
     the port number of that service.  This requires you to configure your
     application by adding an entry to the inet:db/services file on every
     machine which will use the application.  Many standard Internet
     applications and Unix remote services are already in the
     inet:db/services file that comes with AS225.  If your application
     isn't already included, your installation scripts should add the
     entry for your application to inet:db/services.  Offer a default
     value, but let your user actually pick the number since your port
     number must not conflict with another (pre-existing) port number.
