# 6 / Adding an Input Handler / Rules For Input Device Handlers


The following rules should be followed when you are designing an input
handler:

   *  If an input handler is capable of processing a specific kind of an

```c
      input event and that event has no links (ie_NextEvent = 0), the
      handler can end the handler chain by returning a NULL (0) value.
```
   *  If there are multiple events linked together, the handler is free to

      unlink an event from the input event chain, thereby passing a shorter
      list of events to subsequent handlers. The starting address of the
      modified list is the return value.
   *  If a handler wishes to add new events to the chain that it passes to

      a lower-priority handler, it may initialize memory to contain the new
      event or event chain. The handler, when it again gets control on the
      next round of event handling, should assume nothing about the current
      contents of the memory blocks attached to the event chain.  Lower
      priority handlers may have modified the memory as they handled their
      part of the event.  The handler that allocates the memory for this
      purpose should keep track of the starting address and the size of
      this memory chunk so that the memory can be returned to the free
      memory list when it is no longer needed.
Your assembly language handler routine should be structured similar to the
following pseudo-language statement:

   newEventChain = yourHandlerCode(oldEventChain, yourHandlerData);

```c
        d0       =                      a0               a1
```
where:

   *  yourHandlerCode is the entry point to your routine.

   *  oldEventChain is the starting address for the current chain of input

      events.
   *  yourHandlerData is a user-definable value, usually a pointer to some

      data structure your handler requires.
   *  newEventChain is the starting address of an event chain which you are

      passing to the next handler, if any.
When your handler code is called, the event chain is passed in A0 and the
handler data is passed in A1. (You may choose not to use A1.) When your
code returns, it should return the pointer to the event chain in D0. If
all of the events were removed by the routine, return NULL. A NULL (0)
value terminates the handling thus freeing more CPU resources.

Memory that you use to describe a new input event that you have added to
the event chain is available for reuse or deallocation when the handler is
called again or after the [IND_REMHANDLER](../Includes_and_Autodocs_2._guide/node04E2.html) command for the handler is
complete. There is no guarantee that any field in the event is unchanged
since a handler may change any field of an event that comes through the
food chain.

   Do Not Confuse the Device.
   --------------------------
   Altering a repeat key report will confuse the input device when it
   tries to stop the repeating after the key is raised under pre-V36
   Kickstart.

Because [IND_ADDHANDLER](../Includes_and_Autodocs_2._guide/node04E1.html) installs a handler in any position in the handler
chain, it can, for example, ignore specific types of input events as well
as act upon and modify existing streams of input. It can even create new
input events for Intuition or other programs to interpret.

