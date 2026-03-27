---
title: 6 / Device Interface / Input Device Event Types
manual: devices
chapter: devices
section: 6-device-interface-input-device-event-types
functions: []
libraries: []
---

# 6 / Device Interface / Input Device Event Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The input device is automatically opened by the console device when the
system boots.  When the input device is opened, a task named
"input.device" is started. The input device task communicates directly
with the keyboard device to obtain raw key events. It also communicates
with the gameport device to obtain mouse button and mouse movement events
and with the timer device to obtain time events. In addition to these
events, you can add your own input events to the input device, to be fed
to the handler chain (see below).

The keyboard device is accessible directly (see the [Keyboard Device](devices/7-keyboard-device.md)
chapter).  However, once the input.device task has started, you should not
read events from the keyboard device directly, since doing so will deprive
the input device of the events and confuse key repeating.

The gameport device has two units. As you view the Amiga, looking at the
gameport connectors, the left connector is assigned as the primary mouse
input for Intuition and contributes gameport input events to the input
event stream.

The right connector is handled by the other gameport unit and is currently
unassigned.  While the input  device task is running, that task expects to
read the input from the left connector. Direct use of the gameport device
is covered in the [Gameport Device](devices/5-gameport-device.md) chapter of this manual.

The timer device is used to generate time events for the input device. It
is also used to control key repeat rate and key repeat threshold. The
timer device is a shared-access device and is described in
[Timer Device](devices/13-timer-device.md) chapter of this manual.

The device-specific commands are described below.  First though, it may be
helpful to consider the types of input events that the input device deals
with. An input event is a data structure that describes the following:

   *  The class of the event-often describes the device that generated

      the event.
   *  The subclass of the event-space for more information if needed.

   *  The code-keycode if keyboard, button information if mouse, others.

   *  A qualifier such as "Alt key also down,"or "key repeat active".

   *  A position field that contains a data address or a mouse position

      count.
   *  A time stamp, to determine the sequence in which the events occurred.

   *  A link-field by which input events are linked together.

   *  The class, subclass, code and qualifier of the previous down key.

The full definitions for each field can be found in the include file
devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md).  You can find more information about input events in
the [Gameport Device](devices/5-gameport-device.md) and [Console Device](devices/4-console-device.md) chapters of this manual.

The various types of input events are listed below.


                         Input Device Event Types
                         ------------------------
   IECLASS_NULL            A NOP input event
   IECLASS_RAWKEY          A raw keycode from the keyboard device
   IECLASS_RAWMOUSE        The raw mouse report from the gameport device
   IECLASS_EVENT           A private console event
   IECLASS_POINTERPOS      A pointer position report
   IECLASS_TIMER           A timer event
   IECLASS_GADGETDOWN      Select button pressed down over a
```c
                           gadget (address in ie_EventAddress)
```
   IECLASS_GADGETUP        Select button released over the same gadget
```c
                           (address in ie_EventAddress)
```
   IECLASS_REQUESTER       Some requester activity has taken place.
   IECLASS_MENULIST        This is a menu number transmission (menu
```c
                           number is in ie_Code)
```
   IECLASS_CLOSEWINDOW     User has selected active window's Close Gadget
   IECLASS_SIZEWINDOW      This window has a new size
   IECLASS_REFRESHWINDOW   The window pointed to by
                           ie_EventAddress needs to be refreshed
   IECLASS_NEWPREFS        New preferences are available
   IECLASS_DISKREMOVED     The disk has been removed
   IECLASS_DISKINSERTED    The disk has been inserted
   IECLASS_ACTIVEWINDOW    The window is about to be been made active
   IECLASS_INACTIVEWINDOW  The window is about to be made inactive
   IECLASS_NEWPOINTERPOS   Extended-function pointer position report (V36)
   IECLASS_MENUHELP        Help key report during Menu session (V36)
   IECLASS_CHANGEWINDOW    The Window has been modified with move,


```c
                           size, zoom, or change (V36)
```
There is a difference between simply receiving an input event from a
device and actually becoming a handler of an input event stream. A handler
is a routine that is passed an input event list.  It is up to the handler
to decide if it can process the input events. If the handler does not
recognize an event, it leaves it undisturbed in the event list.

   It All Flows Downhill.
   ----------------------
   Handlers can themselves generate new linked lists of events which can
   be passed down to lower priority handlers.

The InputEvent structure is used by the input device to describe an input
event such as a keypress or a mouse movement.


   struct InputEvent
   {
```c
       struct  InputEvent *ie_NextEvent;/* the next chronological event */
       UBYTE   ie_Class;            /* the input event class */
       UBYTE   ie_SubClass;         /* optional subclass of the class */
       UWORD   ie_Code;             /* the input event code */
       UWORD   ie_Qualifier;        /* qualifiers in effect for the event*/
       union
       {
           struct
           {
               WORD    ie_x;        /* the pointer position for event */
               WORD    ie_y;
           } ie_xy;
           APTR    ie_addr;         /* the event address */
           struct
           {
               UBYTE   ie_prev1DownCode;/* previous down keys for dead */
               UBYTE   ie_prev1DownQual;/* key translation: the ie_Code */
               UBYTE   ie_prev2DownCode;/* &low byte of ie_Qualifier for */
               UBYTE   ie_prev2DownQual;/* last & second last down keys */
           } ie_dead;
       } ie_position;
       struct timeval ie_TimeStamp;     /* the system tick at the event */
```
   };


The IEPointerPixel and IEPointerTablet structures are used to set the
mouse position with the IECLASS_NEWPOINTERPOS input event class.


   struct IEPointerPixel
   {
```c
       struct Screen       *iepp_Screen;   /* pointer to an open screen */
       struct
       {                           /* pixel coordinates in iepp_Screen */
           WORD    X;
           WORD    Y;
       } iepp_Position;
```
   };


   struct IEPointerTablet
   {
```c
       struct
       {
           UWORD   X;
           UWORD   Y;
       } iept_Range;       /* 0 is min, these are max      */
       struct
       {
           UWORD   X;
           UWORD   Y;
       } iept_Value;       /* between 0 and iept_Range     */

       WORD iept_Pressure; /* -128 to 127 (unused, set to 0)  */
```
   };


See the include file devices/[inputevent.h](autodocs-2.0/includes-devices-inputevent-h.md) for the complete structure
definitions.

For input device handler installation, the Interrupt structure is used.


   struct Interrupt
   {
```c
       struct Node is_Node;
       APTR   is_Data;         /* server data segment */
       VOID   (*is_Code)();    /* server code entry   */
```
   };


See the include file exec/[interrupts.h](autodocs-2.0/includes-exec-interrupts-h.md) for the complete structure
definition.

