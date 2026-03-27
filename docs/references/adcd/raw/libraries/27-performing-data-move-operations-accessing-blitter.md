# 27 / / Performing Data Move Operations / Accessing Blitter Directly


To use the blitter directly, you must first be familiar with how its
registers control its operation.  This topic is covered thoroughly in the
Amiga Hardware Reference Manual and is not repeated here.  There are two
basic approaches you can take to perform direct programming of the
blitter: synchronous and asynchronous.

  * Synchronous programming of the blitter is used when you want to do a

```c
    job with the blitter right away.  For synchronous programming, you
    first get exclusive access to the blitter with [OwnBlitter()](../Includes_and_Autodocs_2._guide/node0466.html).  Next
    call [WaitBlit()](../Libraries_Manual_guide/node0368.html) to ensure that any previous blitter operation that
    might have been in progress is completed.  Then set up your blitter
    operation by programming the blitter registers.  Finally, start the
    blit and call [DisownBlitter()](../Includes_and_Autodocs_2._guide/node0433.html).
```
  * Asynchronous programming of the blitter is used when the blitter

```c
    operation you want to perform does not have to happen immediately.
    In that case, you can use the [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) and [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html) functions in
    order to queue up requests for the use of the blitter on a
    non-exclusive basis.  You share the blitter with system tasks.
```
Whichever approach you take, there is one rule you should generally keep
in mind about using the blitter directly:


    Don't Tie Up The Blitter.
    -------------------------
    The system uses the blitter extensively for disk and display
    operation.  While your task is using the blitter, many other system
    processes will be locked out.  Therefore, use it only for brief
    periods and relinquish it as quickly as possible.
To use [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) and [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html), you must create a data structure called a
bltnode (blitter node) that contains a pointer to the blitter code you
want to execute.  The system uses this structure to link blitter usage
requests into a first-in, first-out (FIFO) queue.  When your turn comes,
your own blitter routine can be repeatedly called until your routine says
it is finished using the blitter.

Two separate blitter queues are maintained.  One queue is for the [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html)
routine.  You use QBlit() when you simply want something done and you do
not necessarily care when it happens.  This may be the case when you are
moving data in a memory area that is not currently being displayed.

The second queue is maintained for [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html). QBS stands for
"queue-beam-synchronized".  QBSBlit() requests form a beam-synchronized
FIFO queue.  When the video beam gets to a predetermined position, your
blitter routine is called.  Beam synchronization takes precedence over the
simple FIFO.  This means that if the beam sync matches, the
beam-synchronous blit will be done before the non-synchronous blit in the
first position in the queue.  You might use QBSBlit() to draw into an area
of memory that is currently being displayed to modify memory that has
already been "passed-over" by the video beam.  This avoids display flicker
as an area is being updated.

The sole input to both [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) and [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html) is a pointer to a bltnode
data structure, defined in the include file <hardware/[blit.h](../Includes_and_Autodocs_2._guide/node00CC.html#line88)>.  Here is a
copy of the structure, followed by details about the items you must
initialize:


```c
    struct bltnode
    {
        struct  bltnode *n;
        int     (*function)();
        char    stat;
        short   blitsize;
        short   beamsync;
        int     (*cleanup)();
    };
```
struct bltnode *n;

```c
    This is a pointer to the next bltnode, which, for most applications
    will be zero.  You should not link bltnodes together.  This is to be
    performed by the system in a separate call to [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) or [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html).
```
int (*function)( );

```c
    This is the address of your blitter function that the blitter queuer
    will call when your turn comes up.  Your function must be formed as a
    subroutine, with an RTS instruction at the end. Follow Amiga
    programming conventions by placing the return value in D0 (or in C,
    use return(value)).

    If you return a nonzero value, the system will call your routine
    again next time the blitter is idle until you finally return 0.  This
    is done so that you can maintain control over the blitter; for
    example, it allows you to handle all five bitplanes if you are
    blitting an object with 32 colors.  For display purposes, if you are
    blitting multiple objects and then saving and restoring the
    background, you must be sure that all planes of the object are
    positioned before another object is overlaid.  This is the reason for
    the lockup in the blitter queue; it allows all work per object to be
    completed before going on to the next one.

    Note:
    -----
    Not all C compilers can handle *function() properly!  The system
    actually tests the processor status codes for a condition of
    equal-to-zero (Z flag set) or not-equal-to-zero (Z flag clear) when
    your blitter routine returns.  Some C compilers do not set the
    processor status code properly (i.e., according to the value
    returned), thus it is not possible to use such compilers to write the
    (*function)()) routine.  In that case assembly language should be
    used.  Blitter functions are normally written in assembly language
    anyway so they can take advantage of the ability of [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) and
    [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html) to pass them parameters in processor registers.

    The register passing conventions for these routines are as follows.
    Register A0 receives a pointer to the system hardware registers so
    that all hardware registers can be referenced as an offset from that
    address.  Register A1 contains a pointer to the current bltnode.  You
    may have queued up multiple blits, each of which perhaps uses the
    same blitter routine.  You can access the data for this particular
    operation as an offset from the value in A1.  For instance, a typical
    user of these routines can precalculate the blitter register values
    to be placed in the blitter registers and, when the routine is
    called, simply copy them in.  For example, you can create a new
    structure such as the following:

        INCLUDE "exec/types.i"
        INCLUDE "hardware/blit.i"

        STRUCTURE mybltnode,0
                          ; Make this new structure compatible with a
                          ; bltnode by making the first element a bltnode
                          ;  structure.
        STRUCT bltnode,bn_SIZEOF
                UWORD   bltcon1         ; Blitter control register 1.
                UWORD   fwmask          ; First and last word masks.
                UWORD   lwmask
                UWORD   bltmda          ; Modulos for sources a, b,and c.
                UWORD   bltmdb
                UWORD   bltmdc
                UWORD   any_more_data   ; add anything else you want
        LABEL mbn_SIZEOF

    Other forms of data structures are certainly possible, but this
    should give you the general idea.
```
char stat;

```c
    Tells the system whether or not to execute the clean-up routine at
    the end.  This byte should be set to CLEANUP (0x40) if cleanup is to
    be performed.  If not, then the bltnode cleanup variable can be zero.
```
short beamsync;

```c
    The value that should be in the VBEAM counter for use during a
    beam-synchronous blit before the function() is called. The system
    cooperates with you in planning when to start a blit in the routine
    [QBSBlit()](../Includes_and_Autodocs_2._guide/node0469.html) by not calling your routine until, for example, the video
    beam has already passed by the area on the screen into which you are
    writing.  This is especially useful during single buffering of your
    displays.  There may be time enough to write the object between scans
    of the video display. You will not be visibly writing while the beam
    is trying to scan the object.  This avoids flicker (part of an old
    view of an object along with part of a new view of the object).
```
int (*cleanup)();

```c
    The address of a routine that is to be called after your last return
    from the [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) routine.  When you finally return a zero, the queuer
    will call this subroutine (ends in RTS or return()) as the clean-up.
    Your first entry to the function may have dynamically allocated some
    memory or may have done something that must be undone to make for a
    clean exit.  This routine must be specified.
```
