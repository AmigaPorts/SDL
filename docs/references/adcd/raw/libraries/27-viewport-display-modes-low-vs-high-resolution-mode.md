# 27 / / Viewport Display Modes / Low- vs. High-resolution Mode


In LORES mode, horizontal lines of 320 pixels fill most of the ordinary
viewing area.  The system software lets you define a screen segment width
up to 362 pixels in this mode, or you can define a screen segment as
narrow as you desire (minimum of 16 pixels).  In [HIRES](../Libraries_Manual_guide/node0327.html#line25) mode, 640 pixels
fill a horizontal line. In this mode you can specify any width from 16 to
724 pixels. In [SUPERHIRES](../Libraries_Manual_guide/node0327.html#line29) mode, 1280 pixels fill a horizontal line. In
this mode you can specify any width from 16 to 1448 pixels. The fact that
many monitor manufacturers set their monitors to overscan the video
display normally limits you to showing only 16 to 320 pixels per line in
LORES, 16 to 640 pixels per line in HIRES, or 16 to 1280 pixels per line
in SUPERHIRES. Under Release 2, the user can set the monitor's viewable
screen size with the Preferences Overscan editor.


  |   |   |   |   |   |   |   |   |   |   |
  |   |   |   |   |   |   |   |   |   |   |
  |   |   |                       |   |   |
  |   |   |   320 Pixels Across   |   |   |  [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) = 0
  |   |   | width of 352 possible |   |   |
  |   |   |                       |   |   |
  |   |   |   |   |   |   |   |   |   |   |
  |   |   |   |   |   |   |   |   |   |   |


  | | | | | | | | | | | | | | | | | | | | |
  | | | | | | | | | | | | | | | | | | | | |
  | | | | | |                   | | | | | |
  | | | | |   640 Pixels Across   | | | | |  [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) = HIRES
  | | | | | width of 704 possible | | | | |
  | | | | |                       | | | | |
  | | | | | | | | | | | | | | | | | | | | |
  | | | | | | | | | | | | | | | | | | | | |


  |||||||||||||||||||||||||||||||||||||||||
  |||||||||||||||||||||||||||||||||||||||||
  |||||||||||                   |||||||||||
  ||||||||||  1280 Pixels Across  |||||||||  [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) = SUPERHIRES
  ||||||||| width of 1408 possible ||||||||
  ||||||||||                      |||||||||
  |||||||||||||||||||||||||||||||||||||||||
  |||||||||||||||||||||||||||||||||||||||||



    Figure 27-14: How HIRES and SUPERHIRES Affect the Width of Pixels
