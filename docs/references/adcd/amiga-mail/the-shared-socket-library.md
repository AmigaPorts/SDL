---
title: The Shared Socket Library
manual: amiga-mail
chapter: amiga-mail
section: the-shared-socket-library
functions: [OpenLibrary, Wait]
libraries: [exec.library]
---

# The Shared Socket Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The primary goal of the Shared Socket Library is to provide a network API
which is as compatible with standard Unix as possible.  This makes porting
many applications much easier, but it also creates many little quirks that
cannot be "fixed".  The justification behind this is: faithfully emulating
Unix's quirks is better than creating new ones, since at least you can
then write more portable software and only need to remember one set of
quirks.  Remember this when you wish that some function returned *void
rather than *foo, etc.  Expect to get a few spurious compiler warnings
from your nice ANSI 'C' compiler.

Many functions in socket.library are only needed by those developers
porting standard Unix remote services and probably should not be used by
most Amiga applications.  For example, all the functions dealing with user
and group IDs belong in this category.

To use the socket.library functions, the first thing you have to do, of
course, is open it.  This library is a little unconventional because it
returns a different library base for each OpenLibrary() call.  The Shared
Socket Library uses different library bases to keep track of some global
data for each process that opens it.  If you start a new process with a
new context, the new process must open and initialize socket.library.
Tasks should not access the socket.library, only processes should.

Before using any other function in the socket.library, you must call its
function setup_sockets() to initialize the library:


```c
    ULONG retval = setup_sockets( UWORD max_sockets, int *errnop );
```
where max_sockets is the maximum number of sockets that can be open at
once and errnop points to errno, a global integer that provides details
about error conditions.  This global value is used extensively by the
standard socket functions.  The standard Amiga C startup code (c.o)
creates a global variable labelled "errno" which you can use as the global
pointer.

The setup_sockets() call must be matched with the cleanup_sockets() call.
This takes care of deallocating system resources that setup_sockets()
allocates.

The socket.library assumes that all ints are 32-bit values.  If you are
using a compiler which doesn't use 32-bit ints, you must make sure that
all ints are converted to longs by your code.

There are a couple of important differences between the AS225
socket.library and the standard Unix implementation.  When writing
softwarefor AS225, you cannot use the read(), write(), close(), and
ioctl() functions on sockets. These functions come from Unix and apply
both to files and sockets.  To avoid confusion, socket.library does not
contain these functions.  Use the socket.library functions recv(), send(),
s_close(), and s_ioctl() instead.

The standard Unix implementation has a series of get*() functions.  These
functions return a pointer to a static buffer.  The buffer returned by a
call to getX*() is cleared on the next invocation of getX*().  For
example, the buffer pointed to by the return of gethostent() is cleared by
another call to gethostent(), gethostbyaddr() or gethostbyname(), but not
by a call to getprotoent(), etc.  None of the get*ent(), set*ent() or
end*ent() functions should normally be used except for porting existing
programs.

The Shared Socket Library contains a function called selectwait().  This
function combines the select() function with the exec.library Wait()
function so that an Amiga networked application can wait on both Amiga
events and network events at the same time.

This article, the examples from the Network Developer's disk,  and the
include files and the Autodocs should be enough to get you started.
Writing network applications can be very complex and difficult, but is
well worth the effort. This article only introduces you to writing network
applications for the Amiga with AS225, and has left a lot unsaid about the
socket interface and about networking in general.  In addition to the
Shared Socket Library include files and Autodocs, the following books and
articles are all highly recommended. Several should be required reading
for anyone seriously developing any Amiga and/or Unix network applications
with TCP/IP:

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [Wait — exec.library](../autodocs/exec.library.md#wait)
