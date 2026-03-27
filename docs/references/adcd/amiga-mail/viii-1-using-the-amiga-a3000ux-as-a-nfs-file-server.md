---
title: VIII-1: Using the Amiga A3000UX as a NFS File Server
manual: amiga-mail
chapter: amiga-mail
section: viii-1-using-the-amiga-a3000ux-as-a-nfs-file-server
functions: []
libraries: []
---

# VIII-1: Using the Amiga A3000UX as a NFS File Server

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By David Miller - Unix Technical Support Specialist, CATS


You've just added an A3000UX to your ethernet and you can rcp and ftp
files between UNIX and AmigaDOS using the AS225 TCP/IP software.  Great!
But what about the AS225's Network File System (NFS) client software?
Under AmigaDOS, the NFS software lets your Amiga mount the drives of a NFS
server as normal DOS volumes, but how do you set up a server?

NFS allows one machine to share files with other machines connected to a
network.  NFS lets multiple machines access the same files, so only one
copy of the data is necessary.  A client machine (a client is any machine
that can mount a shared directory) can free some of its disk space by
moving common programs to the server's disk (a server is any machine that
shares a part of its disk with other machines).

There are however limitations when sharing files between machines with
different operating systems.  For example;

*  Filenames - UNIX S5 filesystem does not support filenames longer than
   14 characters.  If you copy files from AmigaDOS to UNIX, make sure
   that they are unique in the first 14 characters.  And don't forget
   about the ".info" files! If you copy a file that has a ".info" file
   associated with it, be sure that the name preceding the ".info" does
   not exceed 9 characters.

*  Permissions - UNIX files have permissions for read, write, and execute.
   There is no delete permission; if you have write access to the
   directory, you can delete any file it contains.  Script and archive
   bits are not supported either, so setting the script or archive bits,
   or clearing the delete bit will not work.

*  Filenotes - UNIX does not support filenotes.  If you copy a file from
   an AmigaDOS filesystem to a UNIX filesystem, any file notes will be
   lost. Likewise, you cannot add a comment to a file on a UNIX
   filesystem.  You will not receive any error indication, but the
   operation will have no effect.

The following notes will walk you step-by-step through the process of
configuring and administering NFS on the A3000UX.  If you have used NFS
before with BSD, Sun/OS, Ultrix, or any other operating system, you should
at least skim over these notes, because the implementation is different
under UNIX SVR4.

To keep this article brief, I'm making the following assumptions:


    *  You know how to use one of the editors shipped with Amiga UNIX.
    *  You know how to log in as root or how to su to root.
If you don't, read the Learning Amiga UNIX and Using Amiga UNIX manuals
which come with the  A3000UX.

The five examples illustrate how to do some simple file sharing with NFS.
Using the concepts discussed in these examples you will be able to select
the options necessary to share files while maintaining system security and
integrity.  But, first, you need to start the networking software on the
A3000UX, if it's not already running.  To do this, type the following:


    # init 3
This changes the operating to ``run-level'' 3, the networking run-level.
Other run-levels include:




      S - single user maintenance mode
      0 - system power off
      1 - single user mode
      2 - multiuser mode w/o networking
      3 - multiuser mode w/ networking
      4 - user defined
      5 - system reboot
      6 - system reboot
To find out what your machine's current run-level is, type:


    # who -r
The output will look something like this:


    run-level 3  Jun 18 18:40    3    0    S
Here's what all of that means:




                 run-level 3  Jun 18 18:40    3    0    S
                 -----------  ------------    -    -    -
                      |            |          |    |    |
    This is the   ____|            |          |    |    |
    current state                  |          |    |    |
    of your machine                |          |    |    |
                                   |          |    |    |
    This is when the current ______|          |    |    |
    run-level was entered                     |    |    |
                                              |    |    |
    This is the current run-level ____________|    |    |
                                                   |    |
    This is the number of times                    |    |
    your machine has been in this _________________|    |
    run-level before.                                   |
                                                        |
    This is the previous run-level _____________________|
This is the host table (/etc/inet/hosts on Amiga UNIX and INET:db/hosts on
AmigaDOS) that I'll be using for the examples:



    #
    #       TCP/IP HOST TABLE
    #
    #
    127.0.0.1       localhost loghost loopback me
    #
    #
    #       Widget works engineering network
    #
    #
    # IP Number     Name          Nickname      Comment
    #
    192.9.120.1      Hydrogen       H           # A3000UX - in comp center
    192.9.120.2      Helium         He          # A2000   - in room 316
    192.9.120.3      Lithium        Li          # A2500   - in room 321
    192.9.120.4      Beryllium      Be          # A3000   - in room 320
    192.9.120.5      Boron          B           # A2500   - in room 119
    192.9.120.6      Carbon         C           # A2000   - in room 119
    192.9.120.7      Nitrogen       N           # A2000   - in room 204
    192.9.120.8      Oxygen         O           # A3000   - in room 220
    192.9.120.9      Fluorine       F           # A2500   - in room 132
    192.9.120.10     Neon           Ne          # A3000   - in room 307
The host table contains a list of IP addresses with node names for each of
those addresses.  The machine uses this list to find other nodes by their
name, rather than their numeric IP address.


Example 1
---------

Hydrogen has a directory called /home/scratch which is for temporary
storage. Everyone should be able to read and write in this directory.  To
share this with the rest of the net, the administrator of Hydrogen would
type:


    share -F nfs -o rw /home/scratch
where:



            share  is the command to share files between hosts.
           -F nfs  tells the program share to use the NFS filesystem.
            -o rw  tells the program share to allow all systems both
                     read and write access to the shared files.  This
                     is the default if you don't supply any options.
                     I've just included it here for completeness.
    /home/scratch  is the directory to be shared.
Example 2
---------

Hydrogen also has a large disk attached as /storage.  To allow other hosts
to use this as extra disk space type the following:


```c
    share -F nfs -o rw=Helium /storage/Helium
    share -F nfs -o rw=Lithium /storage/Lithium
            ...
    share -F nfs -o rw=Ne /storage/Neon
```
where:


```c
       -o rw=name  tells share to allow <name> to mount this resource
                     and to deny access to everyone else.
```
This establishes private storage areas for each host.  This way all of the
hosts can share the disk without having their files readable by everyone
on the network.

Note the use of the nickname Ne for the host Neon.  Nicknames must be
explicitly entered in the host table and may be used interchangeably with
the full name of the host.


Example 3
---------

A group of hosts on the first floor of your building are all being used on
one big project, so they need a common work area to store files.  The
administrator could create a work area in /storage called, for example,
ff-project, for first-floor-project, then give the hosts on the first
floor access to this work area by typing:


```c
    share -F nfs -o rw=Boron:Carbon:Fluorine /storage/ff-project
```
where:


```c
    -o rw=name[:name]...
```
allows read and write access to the hosts that are listed and denies
access to everyone else and


    /storage/ff-project
is the name of the directory to share.


Example 4
---------

Hydrogen has a directory called /home/public which is full of useful Amiga
tools.  To share these with the rest of the net, the administrator of
Hydrogen would type:


    share -F nfs -o ro /home/public
where:


    -o ro
tells share to make the shared filesystem readable to all hosts and
writable by no one.  The ``ro'' stands for ``read-only'' and


    /home/public
is the name of the directory to share.

The files are shared read-only for two reasons.  The first is that it
prevents temporary files from being created in the shared partition.  Also
it prevents accidental or malicious removal of shared files.


Example 5
---------

Now, coincidentally, Hydrogen also has a directory called /home/private
which is full of special tools used only by the development staff on the
3rd floor. To share these exclusively with the hosts on the third floor,
the administrator of Hydrogen would type:


```c
    share -F nfs -o ro=He:Li:Be:Ne /home/private
```
where:


```c
    -o ro=name[:name]...
```
tells the share program to give the listed hosts read access to the shared
files.  All other hosts will be denied access to the shared files (Note
the use of nicknames) and


    /home/private
is the name of the shared filesystem.

These options may be combined to allow different types of access.  For
example:


```c
    -o rw=Helium:Neon,ro
```
Everyone can read shared files, but only Helium and Neon have write access.



```c
    -o rw,ro=Fluorine
```
Everyone except Fluorine may read and write files.  Fluorine may only read
files.


```c
    -o rw=C:O,ro=N
```
Carbon and Oxygen have read and write access, Nitrogen has read access,
and the others have no access.

To summarize:



```c
    -o ro      Gives everyone read-only access to the shared files
    -o rw      Gives everyone read/write access
    -o ro=...  Gives read-only access to the listed hosts
    -o rw=...  Gives read/write access to the listed hosts
```
If a host appears in both a rw= and a ro= list, the host will be given
read and write access.  The ordering of the options does not matter.

Since you probably want these directories to be shared automatically every
time you start Amiga UNIX, you need to perform the following steps:


1. Edit the file /etc/inittab and change the line:



         is:2:initdefault
     to
         is:3:initdefault

     This will make your machine go directly to run-level 3 when you boot
     the UNIX Operating System.
2. Edit the file /etc/dfs/dfstab, and enter one line for each directory
   to be shared.  For Example 1 above, this would be the line:



```c
         share -F nfs -o ro /home/public

     So, the complete dfstab for the 5 examples given above would look
     something like this:

         #
         # For Example 1
         #
         share -F nfs -o rw /home/scratch

         #
         # For Example 2
         #
         share -F nfs -o rw=Hydrogen /storage/Hydrogen
         share -F nfs -o rw=Helium /storage/Helium
         share -F nfs -o rw=Lithium /storage/Lithium
         share -F nfs -o rw=Beryllium /storage/Beryllium
         share -F nfs -o rw=Boron /storage/Boron
         share -F nfs -o rw=Carbon /storage/Carbon
         share -F nfs -o rw=Nitrogen /storage/Nitrogen
         share -F nfs -o rw=Oxygen /storage/Oxygen
         share -F nfs -o rw=Fluorine /storage/Fluorine
         share -F nfs -o rw=Neon /storage/Neon

         #
         # For Example 3
         #
         share -F nfs -o rw=Boron:Carbon:Fluorine /storage/ff-project

         #
         # For Example 4
         #
         share -F nfs -o ro /home/public

         #
         # For Example 5
         #
         share -F nfs -o ro=He:Li:Be:Ne /home/private
```
3. Run the command:



         shareall -F nfs

     which will share all of the NFS filesystems, and the command:

         unshareall -F nfs

     which will make the NFS filesystems unavailable.
For those interested in more information on UNIX SVR4 networking, either
as a user or an administrator, UNIX System V Release 4 - Network User's
and Administrator's Guide, published by Prentice Hall is an excellent
starting place.

If you have any suggestions for the new Amiga UNIX section of Amiga Mail,
please send it to me either via email:


```c
        davidm@cbmvax.commodore.com
                or
        ...!{rutgers,uunet}!cbmvax!davidm
```
or US Mail:


        ATTN:  David Miller
        Commodore Applications and Technical Support
        Commodore Business Machines, Inc.
        1200 Wilson Drive
        West Chester, PA 19380
or FAX:


        David Miller
        Commodore Business Machines
        +1 215 431 9156
or BIX:


        david.miller
