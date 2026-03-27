# 2 / Audio And System I/O Functions / Wait() and WaitPort()


These functions can be used to put your task to sleep while a sound plays.
[Wait()](../Includes_and_Autodocs_2._guide/node038A.html) takes a wake-up mask as its argument. The wake-up mask is usually
the mp_SigBit of a [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) that you have set up to get replies back from
the audio device.

[WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) will put your task to sleep while a sound plays.  The argument
to WaitPort() is a pointer to a MsgPort that you have set up to get
replies back from the audio device.

[Wait()](../Includes_and_Autodocs_2._guide/node038A.html) and [WaitPort()](../Includes_and_Autodocs_2._guide/node038C.html) will not remove the message from the reply port.
You must use [GetMsg()](../Includes_and_Autodocs_2._guide/node035A.html) to remove it.

You must always use Wait() or WaitPort() to wait for I/O to finish with
the audio device.

