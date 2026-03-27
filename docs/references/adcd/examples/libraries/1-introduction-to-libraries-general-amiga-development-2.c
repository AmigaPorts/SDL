/* Source: ADCD 2.1
 * Section: 1-introduction-to-libraries-general-amiga-development
 * Library: libraries
 * ADCD reference: libraries/1-introduction-to-libraries-general-amiga-development.md
 */

    for external events like menu selection or keystrokes, do not bog
    down the [multitasking](../Libraries_Manual_guide/node000A.html) system by busy-waiting in a loop.  Instead, let
    your task go to sleep by [Wait()ing](../Libraries_Manual_guide/node02D4.html) on its signal bits.  For example:

        signals = (ULONG)Wait(  (1<<windowPtr->UserPort->mp_SigBit) |
                                    (1<<consoleMsgPortPtr->mp_SigBit)  );

    This turns the signal bit number for each port into a mask, then
    combines them as the argument for the Exec library [Wait()](../Libraries_Manual_guide/node02D4.html) function.
    When your task wakes up, handle all of the messages at each port
    where the mp_SigBit is set.  There may be more than one message per
    port, or no messages at the port.  Make sure that you [ReplyMsg()](../Libraries_Manual_guide/node02F3.html) to
    all messages that are not replies themselves.  If you have no signal
    bits to Wait() on, use [Delay()](../Includes_and_Autodocs_2._guide/node0292.html) or [WaitTOF()](../Libraries_Manual_guide/node0390.html) to provide a measured
    delay.
