# 2 / Audio And System I/O Functions / BeginIO()


All the commands that you can give to the audio device should be sent by
calling the [BeginIO()](../Includes_and_Autodocs_2._guide/node04AD.html) function.  This differs from other Amiga devices
which generally use [SendIO()](../Includes_and_Autodocs_2._guide/node037A.html) or [DoIO()](../Includes_and_Autodocs_2._guide/node034B.html).  You should not use SendIO() or
DoIO() with the audio device because these functions clear some special
flags used by the audio device; this might cause audio to work incorrectly
under certain circumstances.  To be safe, you should always use BeginIO()
with the audio device.

