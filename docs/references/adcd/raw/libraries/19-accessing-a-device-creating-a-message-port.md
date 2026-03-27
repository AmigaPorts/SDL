# 19 / Accessing a Device / Creating a Message Port


When a device completes the command in a message, it will return the
message to the message port specifed as the reply port in the message.  A
message port is obtained by calling the [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39) or [CreatePort()](../Libraries_Manual_guide/node02EC.html)
function.  You must delete the message port when you are finished by
calling the [DeleteMsgPort()](../Libraries_Manual_guide/node02ED.html#line26) or [DeletePort()](../Libraries_Manual_guide/node02ED.html) function.

If your application needs to be compatible with pre-V36 versions of the
operating system, use the amiga.lib functions [CreatePort()](../Libraries_Manual_guide/node02EC.html) and
[DeletePort()](../Libraries_Manual_guide/node02ED.html); if you require V36 or higher, you may use the Exec ROM
functions [CreateMsgPort()](../Libraries_Manual_guide/node02EC.html#line39) and [DeleteMsgPort()](../Libraries_Manual_guide/node02ED.html#line26).

