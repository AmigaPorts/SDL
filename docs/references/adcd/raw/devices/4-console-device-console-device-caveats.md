# 4 Console Device / Console Device Caveats


   *  Only one console unit can be attached per window.  Sharing a console

      window must be done at a level higher than the device.
   *  Do not mix graphics.library calls with console rendering in the same

      areas of a window.  It is permissible to send console sequences to
      adjust the area in which console renders, and use graphics.library
      calls to render outside of the area console is using.
For example, do not render text with console sequences and scroll using
the graphics.library [ScrollRaster()](../Includes_and_Autodocs_2._guide/node0473.html) function.

   *  The character map feature is private and cannot be accessed by the

      programmer.  Implementation details and behaviors of the character
      map my change in the future.
   *  Do not use an IDCMP with character mapped consoles.  All Intuition

      messages should be obtained via RAW INPUT EVENTS from the console
      device.
