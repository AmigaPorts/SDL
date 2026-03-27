# 12 / Boopsi Gadgets / The Active Gadget


While a gadget is active, Intuition sends it a [GM_HANDLEINPUT](../Libraries_Manual_guide/node0219.html) message for
every timer pulse, mouse move, mouse click, and key press that takes
place.  A timer event pulse arrives about every tenth of a second.  Mouse
move events can arrive at a much higher rate than the timer pulses.
Without even considering the keyboard, a gadget can get a lot of
GM_HANDLEINPUT messages in a short amount of time. Because the active
gadget has to handle a large volume of GM_HANDLEINPUT messages, the
overhead of this method should be kept to a minimum.

Because the gadget will always receive a [GM_GOACTIVE](../Libraries_Manual_guide/node0219.html) message before it is
active and a [GM_GOINACTIVE](../Libraries_Manual_guide/node0219.html) message after it is no longer active, the
gadget can use these methods to allocate, initialize, and deallocate
temporary resources it needs for the [GM_HANDLEINPUT](../Libraries_Manual_guide/node0219.html) method.  This can
significantly reduce the overhead of GM_HANDLEINPUT because it eliminates
the need to allocate, initialize, and deallocate resources for every
GM_HANDLEINPUT message.

Note that the [RastPort](../Libraries_Manual_guide/node034A.html) from [ObtainGIRPort()](../Includes_and_Autodocs_2._guide/node0232.html) is not cachable using this
method.  If the [GM_HANDLEINPUT](../Libraries_Manual_guide/node0219.html) method needs to use a RastPort, it has to
obtain and release the RastPort for every GM_HANDLEINPUT message using
ObtainGIRPort() and [ReleaseGIRPort()](../Includes_and_Autodocs_2._guide/node0243.html).

 [RKMButtonclass.c](../Libraries_Manual_guide/node021F.html) 

